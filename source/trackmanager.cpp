#include "trackmanager.h"

TrackManager::TrackManager(const QString &tracksDirPath, QObject *parent)
    : QObject{ parent }
    , tracksDir{ tracksDirPath }
    , mMediaPlayer{ new QMediaPlayer(this) }
    , mAudioOutput{ new QAudioOutput(this) }
{
    qInfo() << "TrackManager construction...";

    mMediaPlayer->setAudioOutput(mAudioOutput);

    // создание директории с треками
    if (!tracksDir.exists()) {
        QDir::current().mkdir(tracksDir.path());
    }
    // поиск треков
    initTrackList();

    initConnections();

    qInfo() << "/TrackManager constructed";
}

TrackManager::TrackManager(QObject *parent)
    : TrackManager{ defaultTracksDirectory, parent }
{
}

TrackManager::~TrackManager()
{
    qInfo() << "~TrackManager";

    saveTrackList();
}

void TrackManager::initConnections()
{
    qInfo() << "TrackManager::initConnections";

    connect(this, &TrackManager::stopPlaying, mMediaPlayer, &QMediaPlayer::stop);
}

void TrackManager::initTrackList()
{
    qInfo() << "TrackManager::initTracks";

    QFile file_trackList{ tracksDir.filePath(trackListFileName) };
    if (file_trackList.open(QIODevice::ReadOnly)) {
        while (!file_trackList.atEnd()) {
            auto trackData{ QString(file_trackList.readLine()).split(';', Qt::SkipEmptyParts) };
            if (tracksDir.exists(trackData.at(0))) {
                appendTrackList({ trackData.at(0), trackData.at(1) });
            }
        }
        file_trackList.close();
    } else {
        emit newMessage(tr("Не удалось открыть файл с данными о треках"));
        return;
    }
}

void TrackManager::appendTrackList(const Track &newTrack)
{
    qInfo() << "TrackManager::appendTrackList";

    if (auto opt_track{ findTrack(newTrack.fileName()) }; opt_track) {
        mList_tracks.replace(mList_tracks.indexOf(opt_track.value()), newTrack);
        emit newMessage(tr("Трек заменён"));
    } else {
        mList_tracks.append(newTrack);
        emit newMessage(tr("Трек закачан"));
    }
}

void TrackManager::saveTrackList() const
{
    qInfo() << "TrackManager::saveTracksList";

    QFile file_trackList{ tracksDir.filePath(trackListFileName) };

    if (file_trackList.open(QIODevice::WriteOnly)) {
        QTextStream stream{ &file_trackList };
        for (const auto &track : mList_tracks) {
            stream
                    << track.fileName() << ';'
                    << track.lastModified().toString(lastModifiedDateFormal) << ';'
                    << '\n';
        }
        file_trackList.close();
    } else {
        emit errorMessage(tr("Не удалось открыть файл для записи."));
        return;
    }
}

void TrackManager::rememberTrackNum(int trackNum)
{
    m_trackNum = trackNum;
}

bool TrackManager::createNewTrack(const Track &track, const QByteArray &trackData)
{
    qInfo() << "TrackManager::createNewTrack";

    QFile file_track{ tracksDir.filePath(track.fileName()) };
    if (file_track.open(QIODevice::WriteOnly)) {
        file_track.write(trackData);
        file_track.close();

        appendTrackList(track);
    } else {
        emit errorMessage(tr("Не удалось сохранить трек"));
        return false;
    }
    return true;
}

const std::optional<Track> TrackManager::findTrack(const QString &trackName) const
{
    qInfo() << "TrackManager::findTrack";

    if (!tracksDir.exists(trackName)) {
        emit errorMessage(tr("Трек '%1' не найден по пути '%2'")
                          .arg(trackName).arg(tracksDir.absolutePath()));
        return std::nullopt;
    }
    for (const auto &track : mList_tracks) {
        if (track.fileName() == trackName) {
            return std::optional<const Track>(std::in_place, track);
        }
    }
    emit errorMessage(tr("Трек '%1' не найден в списке").arg(trackName));
    return std::nullopt;
}

bool TrackManager::playTrack(const QString &trackName, const float volume)
{
    qInfo() << "TrackManager::playTrack" << trackName;

    if (!findTrack(trackName).has_value()) {
        return false;
    }
    if (mMediaPlayer->source().toString() != tracksDir.filePath(trackName)) {
        mAudioOutput->setVolume(volume);
        mMediaPlayer->setSource(tracksDir.filePath(trackName));
        mMediaPlayer->setLoops(QMediaPlayer::Infinite);
        mMediaPlayer->play();
        emit newMessage(tr("Проигрывается трек: '%1'").arg(trackName));
    }

    return true;
}

bool TrackManager::playTrack(const int trackNum, const float volume)
{
    return playTrack(Track::createTrackNameByNumber(trackNum), volume);
}

const quint32 TrackManager::calculateCrc32Track(const Track &track) const
{
    qInfo() << "TrackManager::calculateCrc32Track";

    QByteArray data;

    // получение массива байтов из файла
    if (tracksDir.exists(track.fileName())) {
        QFile file_track{ tracksDir.filePath(track.fileName()) };
        file_track.open(QIODevice::ReadOnly);
        data.append(file_track.readAll());
        file_track.close();
    } else {
        emit errorMessage(tr("Файл '%1' не найден").arg(track.fileName()));
        return 0;
    }

    // дополнение массива нулевыми байтами для кратности числу 4
    if (auto dop{ data.size() % 4 }; dop) {
        dop = 4 - dop;
        while (dop--) {
            data.append(char(0));
        }
    }

    // дополнение массива данными о дате последней модификации
    if (const auto &lastModified{ track.lastModified() }; lastModified.isValid()) {
        // ужимание даты и времени в формат Filinfo из бибилиотеки FatFs
        int time{ lastModified.time().hour() * 2048 };
        time |= lastModified.time().minute() * 32;
        time |= lastModified.time().second() / 2;
        int date{ (lastModified.date().year() - 1980) * 512 };
        date |= lastModified.date().month() * 32;
        date |= lastModified.date().day();

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
    return calculateCrc32(data);
}

const quint32 TrackManager::calculateCrc32Track(const QString &trackName) const
{
    return calculateCrc32Track(findTrack(trackName).value());
}

const quint32 TrackManager::calculateCrc32Track(const int trackNum) const
{
    return calculateCrc32Track(Track::createTrackNameByNumber(trackNum));
}

const quint32 TrackManager::calculateCrc32OfAllTracks() const
{
    qInfo() << "TrackManager::calculateCrc32OfAllTracks";

    quint32 crc{};
    for (const auto &track : mList_tracks) {
        QFile file_track{ tracksDir.filePath(track.fileName()) };
        file_track.open(QIODevice::ReadOnly);
        crc += calculateCrc32Track(track);
        file_track.close();
    }
    return crc &= 0xFFFFFFFF;
}

const quint32 TrackManager::calculateCrc32(const QByteArray &data) const
{
    quint32 crc{ 0xFFFFFFFF };
    quint32 poly{ 0x04c11db7 };
    for (qint64 i{}, len{ data.size() }; i < len; ++i) {
        crc ^= data.at(i) << 24;
        for (int j{}; j < 8; ++j) {
            int msb = (crc >> 31) & 1;
            crc <<= 1;
            if (msb) { crc ^= poly; }
        }
    }
    return crc & 0xFFFFFFFF;
}
