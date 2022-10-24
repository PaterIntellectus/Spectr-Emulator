#include "trackmanager.h"

TrackManager::TrackManager(QObject *parent)
    : QObject{ parent }
    , mMediaPlayer{ new QMediaPlayer(this) }
    , mAudioOutput{ new QAudioOutput(this) }
{
    qInfo() << "TrackManager construction...";

    mMediaPlayer->setAudioOutput(mAudioOutput);
    mAudioOutput->setVolume(50);

    // создание директории с треками
    QDir::current().mkdir(tracksDirectory);

//    // поиск всех треков в папке и запись информации в список
    initTracks();

    qInfo() << "/TrackManager constructed";
}

TrackManager::~TrackManager()
{
    qInfo() << "~TrackManager";

    saveTracksList();
}

void TrackManager::initConnections()
{
    qInfo() << "TrackManager::initConnections";


}

void TrackManager::initTracks()
{
    qInfo() << "TrackManager::initTracks";

    QFile file_tracksData{ tracksDirectory + trackListFileName };

    if (file_tracksData.open(QIODevice::ReadOnly)) {
        while (!file_tracksData.atEnd()) {
//            format: "trackName;lastModified";
            auto trackData{ QString(file_tracksData.readLine()).split(';', Qt::SkipEmptyParts) };
            if (QFile::exists(getTrackRelativePath(trackData.at(0)))) {
                appendTrackList(trackData.at(0), trackData.at(1));
            }
        }
        file_tracksData.close();
    } else {
        emit errorMessage(tr("Не вышло открыть файл с данными о треках!!!"));
        return;
    }
}

void TrackManager::appendTrackList(const QString &trackName, const QString &lastModified)
{
    qInfo() << "TrackManager::addTrack";

    auto ptr_newTrack{ QSharedPointer<Track>::create(trackName, lastModified) };

//     если трек с таким именем уже имеется в списке,
//     то он будет заменён
    if (auto track{ getTrackPtr(trackName) }; track) {
        track.swap(ptr_newTrack);
        ptr_newTrack.reset();
        emit newMessage(tr("Трек %1 перезаписан").arg(trackName));
    } else {
        mList_tracks.append(ptr_newTrack);
        emit newMessage(tr("Добавлен новый трек: %1").arg(trackName));
    }
}

void TrackManager::saveTracksList()
{
    qInfo() << "TrackManager::saveTracksList";

    QFile file_trackList{ tracksDirectory + trackListFileName };

    if (file_trackList.open(QIODevice::WriteOnly)) {
        QTextStream stream{ &file_trackList };
        for (const auto ptr_track : mList_tracks) {
            stream
                    << ptr_track->name() << ';'
                    << ptr_track->lastModified().toString(lastModifiedDateFormal) << ';'
                    << '\n';
        }
        file_trackList.close();
    } else {
        emit errorMessage(tr("Невозможно сохранить данные о треках!"));
    }
}

bool TrackManager::saveTrack(const QString &trackName, const QByteArray &trackData, const QString &lastModified)
{
    qInfo() << "TrackManager::saveTrack";

    QFile file_track{ tracksDirectory + trackName };
    if (file_track.open(QIODevice::WriteOnly)) {
        file_track.write(trackData);
        file_track.close();
    } else {
        emit errorMessage("Не удалось открыть файл для сохранения трека!!!");
        return false;
    }
    appendTrackList(trackName, lastModified);
    return true;
}

QSharedPointer<Track> TrackManager::getTrackPtr(QStringView trackName)
{
    qInfo() << "TrackManager::getTrackPtr";

    for (const auto &track : mList_tracks) {
        if (track->name() == trackName) {
            return track;
        }
    }
    return nullptr;
}

QSharedPointer<Track> TrackManager::getTrackPtr(const int trackNum)
{
    return getTrackPtr(createTrackName(trackNum));
}

bool TrackManager::playTrack(QStringView trackName)
{
    qInfo() << "TrackManager::playTrack";

    const auto &pathToTrack{ getTrackRelativePath(trackName) };

    if (!QFile(pathToTrack).exists()) {
        emit errorMessage(tr("Не найден файл для воспроизведения!"));
        return false;
    }
    mMediaPlayer->setSource(pathToTrack);
    mMediaPlayer->play();

    emit newMessage(tr("Проигрывается трек: '%1'").arg(trackName));
    return true;
}

bool TrackManager::playTrack(const int trackNum)
{
    return playTrack(createTrackName(trackNum));
}

const QByteArray TrackManager::calculateCrc32(const QString &trackName)
{
    qInfo() << "TrackManager::calculateCrc32";

    QByteArray data;

    // поиск файла в списке
    auto track{ getTrackPtr(trackName) };
    if (!track) {
        emit errorMessage(tr("Трек '%1' не найден в списке, перекачайте трек").arg(trackName));
        return 0;
    }

    // получение массива байтов из файла
    if (QFile file_track{ getTrackRelativePath(trackName) }; file_track.exists()) {
        file_track.open(QIODevice::ReadOnly);
        data.append(file_track.readAll());
        file_track.close();
    } else {
        emit errorMessage(tr("Трек '%1' не найден в папке, перекачайте трек").arg(trackName));
        return 0;
    }

    // дополнение массива нулевыми байтами для кратности числу 4
    if (auto dop{ data.size() % 4 }; dop) {
        dop = 4 - dop;
        while (dop--) {
            data.append(char(0));
        }
    }

    // дополнение массива данными о дате последней мовификации
    if (!track->lastModified().isNull()) {
        // ужимание даты и времени в формат Filinfo из бибилиотеки FatFs
        int time{ track->lastModified().time().hour() * 2048 };
        time |= track->lastModified().time().minute() * 32;
        time |= track->lastModified().time().second() / 2;
        int date{ (track->lastModified().date().year() - 1980) * 512 };
        date |= track->lastModified().date().month() * 32;
        date |= track->lastModified().date().day();

        // ужимание даты в 4 байта
        QQueue<int> qI_lastModifiedBytes;
        qI_lastModifiedBytes.enqueue(time & 0x00ff);
        qI_lastModifiedBytes.enqueue((time & 0xff00) >> 8);
        qI_lastModifiedBytes.enqueue(date & 0x00ff);
        qI_lastModifiedBytes.enqueue((date & 0xff00) >> 8);

        // дополнение массива байтами даты
        while (qI_lastModifiedBytes.size()) {
            data.append(qI_lastModifiedBytes.dequeue());
        }
    }

    return QByteArray::number // не видно старшие байты массива, если они = 0
            (calculateCrc32(data), 16) // подсчёт crc32 и cast в 16-бит
            .rightJustified(8, '0'); // fix: заполняет старшие байты массива нулями
}

const QByteArray TrackManager::calculateCrc32(const int trackNum)
{
    return calculateCrc32(createTrackName(trackNum));
}

const quint32 TrackManager::calculateCrc32(const QByteArray data)
{
    qInfo() << "TrackManager::calculateCrc32";

    quint32 crc{ 0xFFFFFFFFUL };
    quint32 poly{ 0x04c11db7 };

    for (qint64 i{}, len{ data.size() }; i < len; ++i) {
        crc = (crc ^ (data.at(i) << 24));
        for (int j{}; j < 8; ++j) {
            int msb = (crc >> 31) & 1;
            crc = crc << 1;
            if (msb) { crc = crc ^ poly; }
        }
    }
    return crc & 0xFFFFFFFFUL;
}
