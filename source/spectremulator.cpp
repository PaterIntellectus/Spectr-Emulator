#include "spectremulator.h"

SpectrEmulator::SpectrEmulator(const int id, PairHostPort pair_hostPort, QObject *parent)
    : SpectrMaster{ id, DeviceStatus::FirstRequest, parent }

    , m_networkManager{ new QNetworkAccessManager(this) }
    , m_emulationTimer{ new QTimer(this) }

    , m_requestType{ RequestType::getcmd }
    , m_emulationMode{ false }
{
    qInfo() << "SpectrEmulator construction...";

    setConnectionSettings(pair_hostPort);
    initConnections();

    qInfo() << "/SpectrEmulator constructed";
}

SpectrEmulator::~SpectrEmulator()
{
    qInfo() << "~SpectrEmulator";

    if (m_emulationTimer->isActive())
        m_emulationTimer->stop();
}

void SpectrEmulator::initConnections()
{
    qInfo() << "SpectrEmulator::initConnections";

    connect(m_emulationTimer, &QTimer::timeout, [this](){ sendRequest(m_requestType); });
    connect(m_networkManager, &QNetworkAccessManager::finished, this, &SpectrEmulator::processReply);
}

void SpectrEmulator::setConnectionSettings(PairHostPort pair_hostPort)
{
    qInfo() << "SpectrEmulator::setConnectionSettings";

    mPair_hostPort.first = pair_hostPort.first;
    mPair_hostPort.second = pair_hostPort.second;


//    mFile_connectionSettings.open(QIODevice::ReadOnly);
//    QTextStream stream{ &mFile_connectionSettings };

//    QString address, port;
//    stream >> address >> port;

//    mFile_connectionSettings.close();

//    if (m_connectionSettings.host != address) {
//        m_connectionSettings.host = address;
//    }
//    if (0 < port.toInt() && port.toInt() < 65534) {
//        m_connectionSettings.port = port.toUShort();
//    } else {
//        emit errorMessage(tr("Неверный номер порта: %1 [0 >> 65535]").arg(port));
//    }
}

void SpectrEmulator::toggleEmulationMode(bool onOff)
{
    qInfo() << "SpectrEmulator::toggleEmulationMode";

    m_emulationMode = onOff;
    if (m_emulationMode) {
        m_requestType = RequestType::getcmd;
        setStatus(DeviceStatus::FirstRequest);

        m_emulationTimer->start(2000);
        emit newMessage(tr("Эмуляция началась:"));
    } else {
        m_emulationTimer->stop();
        emit newMessage(tr("Эмуляция окончена"));
    }
}

void SpectrEmulator::sendRequest(const RequestType requestType, QUrlQuery query)
{
    qInfo() << "SpectrEmulator::sendRequest";
    if (m_emulationTimer->isActive()) {
        m_emulationTimer->stop();
    }
    m_requestType = requestType;

    QUrl url;
    url.setScheme("http");
    url.setHost(mPair_hostPort.first);
    url.setPort(mPair_hostPort.second);
    // если query не передана, то она построится исходя из данных устройства
    if (query.isEmpty()) { query = createQuery(); }
    url.setQuery(query);

    emit newMessage(tr("Запрос: ") + url.toString());

    QNetworkRequest request{ url };
    m_networkManager->get(request);
}

const QUrlQuery SpectrEmulator::createQuery()
{
    qInfo() << "SpectrEmulator::emulateQuery";

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("page"), mList_pages.at(static_cast<int>(m_requestType)));
    query.addQueryItem(QStringLiteral("id"), QString::number(getId()));

    switch(m_requestType) {
    case RequestType::getcmd:
        query.addQueryItem(QStringLiteral("val"), QString::number(getInputsValInt()));
        query.addQueryItem(QStringLiteral("st"), QString::number(static_cast<int>(getStatusInt())));
        break;
    case RequestType::stcmd:
        query.addQueryItem(QStringLiteral("idcmd"), m_cmd->getIdStr());
        query.addQueryItem(QStringLiteral("st"), m_cmd->getStatusCodeStr());
        query.addQueryItem(QStringLiteral("err"), m_cmd->getErrorCodeStr());
        break;
    case RequestType::slist:
    case RequestType::flist:
        break;
    case RequestType::download:
        break;
    default:
        emit errorMessage(tr("Невозможно создать запрос такого типа!!!"));
        break;
    }
    return query;
}

void SpectrEmulator::processReply(QNetworkReply *reply)
{
    qInfo() << "SpectrEmulator::processReply";
    reply->deleteLater();

    // for debug
//    qInfo() << "Replie's headers:";
//    for (auto headerPair : reply->rawHeaderPairs()) {
//        qInfo() << headerPair.first << ':' << headerPair.second;
//    }

    auto replyData{ reply->readAll() };
    if (!replyData.isEmpty()) {
        // showing server's reply, ONLY if it's not a file's download request
        if (m_requestType != RequestType::download) {
            emit newMessage(tr("Ответ: ") + replyData);
        }
        // выбор обработчика на основе отправленного запроса
        switch (m_requestType) {
        case RequestType::getcmd:
            processGetcmdReply(replyData);
            break;
        case RequestType::stcmd:
            processStcmdReply(replyData);
            break;
        case RequestType::slist:
            processSlistReply(replyData);
            break;
        case RequestType::flist:
            processFlistReply(reply, replyData);
            break;
        case RequestType::download:
            processDownloadReply(reply, replyData);
            break;
        default:
            emit errorMessage(tr("Не существует такого типа запроса"));
            return;
        }
        qInfo() << "Request Type:" << static_cast<int>(m_requestType);

    } else {
        emit errorMessage(tr("Нет ответа от сервера!"));
    }

    if (m_emulationMode) {
        m_emulationTimer->start(2000);
    }
}

void SpectrEmulator::processGetcmdReply(const QString &replyData) {
    qInfo() << "SpectrEmulator::processGetcmdReply";

    if (replyData.startsWith("no")) {
        // todo: обработка всего остального, что есть в строке
        // получаемой при отсутствии новых команд
        // ...
        auto list_masterData{ replyData.split(',') };

    } else if (replyData.startsWith("id")) {

        auto list_cmdData{ replyData.split("; ", Qt::SkipEmptyParts) };
//        for (QStringView line : list_cmdData) { qInfo() << line; }

        // выборка и сохранение id полученной команды
        auto idcmd{
            list_cmdData.at(0)
                    .sliced(list_cmdData.at(0).indexOf('=') + 1) // взятие части строки до  знака '='
                    .toInt() // конвертирует строку в int
        };
        m_cmd->setId(idcmd);

        //  выборка имени команды из ответа
        auto cmdName{
            list_cmdData.at(1)
                    .first(list_cmdData.at(1).indexOf('='))
        };
        // выборка текста команды из ответа
        auto cmdText{
            list_cmdData.at(1)
                    .sliced(list_cmdData.at(1).indexOf('=') + 1)
        };
        qInfo() << idcmd << cmdName << cmdText;

        if (cmdName == "play") {
            // список параметров команды
            auto list_cmdParameters{ cmdText.split(',', Qt::SkipEmptyParts) };

            // воспроизведение файла
            if (mTrackManager->playTrack(list_cmdParameters.at(0).toInt())) {
                setStatus(DeviceStatus::PlayingAudio);
                m_cmd->setStatus(Command::CommandStatuses::Completed);
                m_cmd->setErrorCode(Command::ErrorCode::NoError);
                m_requestType = RequestType::stcmd;
            } else {
                setStatus(DeviceStatus::AccidentOccured);
                m_cmd->setStatus(Command::CommandStatuses::ErrorOccured);
                m_cmd->setErrorCode(Command::ErrorCode::CannotOpenAudioFile);
                m_requestType = RequestType::download;
            }

        } else {
            setStatus(DeviceStatus::Pending);
        }


        // выставление статуса устройства
//        auto cmdName {
//                    .split('=')
//                    };
//        if (cmdName == "play") {

//        } else {}
    } else {
        emit errorMessage(tr("Получена неизвестная команда"));
        return;
    }

        // todo:

//            qInfo() << cmd;


//            map_cmdData.insert("id", replyData.first(replyData.indexOf(';')));


//            for (const auto &cmdParameter : replyData.split(';')) {
//                if (cmdParameter.isEmpty()) { continue; }
//                auto keyVal{ cmdParameter.split('=') };
//                map_cmdData.insert(keyVal[0].trimmed(), keyVal[1].trimmed());
//            }
        // запись данных о полученной команде
//            m_cmd->setId(map_cmdData.value("id").toInt());
//            m_cmd->setStatusCode(Command::CommandStatuses::Completed);
//            m_cmd->setErrorCode(0);

        // смена типа запроса для следующей отправки
        //            m_currentRequestType = RequestTypes::stcmd;
}

void SpectrEmulator::processStcmdReply(const QString &replyData)
{
    qInfo() << "SpectrEmulator::processStcmdReply";

    if (replyData != "ok") {
        emit errorMessage(tr("Команда НЕ подтверждена!!!"));
    }
    setStatus(DeviceStatus::Pending);
    m_requestType = RequestType::getcmd;
}

void SpectrEmulator::processSlistReply(const QString &replyData)
{
    qInfo() << "SpectrEmulator::processSlistReply";

    // проходит по всему полученному списку id,
    for (const auto &str_devId : replyData.split(';', Qt::SkipEmptyParts)) {
        auto devId{ str_devId.toInt() };

        bool slaveExists{ false };
        for (const auto &slave : mList_slaves) {
            if (slave->getId() == devId) {
                slaveExists = true;
                break;
            }
        }
        if (slaveExists) { continue; }

        // добавление нового устройства в список
        mList_slaves.append(new SpectrDevice(devId, DeviceStatus::FirstRequest, this));
        emit newMessage(QStringLiteral("Добавлено новое утройство с id=%1").arg(devId));
    }

    // testing
    emit newMessage(QStringLiteral("Список всех устройств(%1): ").arg(mList_slaves.count()));
    for (const auto &slave : mList_slaves) {
        emit newMessage(QString::number(slave->getId()));
    }
}

void SpectrEmulator::processFlistReply(const QNetworkReply *reply, const QByteArray &replyData)
{
    qInfo() << "SpectrEmulator::processFlistReply";

    emit newMessage(tr("Поиск и файлов..."));
    for (const auto &trackLine: replyData.split(';')) {
        if (trackLine.isEmpty()) { continue;}

        auto delimeterIndex{ trackLine.indexOf(',') };

        auto trackNum{ trackLine.first(delimeterIndex).toInt() };
        auto receivedCrc{ trackLine.sliced(delimeterIndex + 1) };

        auto trackCrc{ mTrackManager->calculateCrc32(trackNum) };

        emit newMessage(
                    QStringLiteral("%1: %2 %4 %3(server)")
                    .arg(mTrackManager->createTrackName(trackNum))
                    .arg(trackCrc).arg(receivedCrc)
                    .arg(receivedCrc == trackCrc ? "==" : "!=")
                    );
    }
}

void SpectrEmulator::processDownloadReply(const QNetworkReply *reply, const QByteArray &replyData)
{
    qInfo() << "SpectrEmulator::processDownloadReply";

    auto str_dispositionHeader{ reply->header(QNetworkRequest::ContentDispositionHeader).toString() };
    QString trackname{ "!FailedTrack!" };
    for (auto &str : str_dispositionHeader.split(';', Qt::SkipEmptyParts)) {
        if (str.contains(QStringLiteral("filename="))) {
            trackname = str.sliced(str.indexOf('=') + 1);
        }
    }
    mTrackManager->saveTrack(trackname, replyData, reply->rawHeader("Last-Modified"));

    m_requestType = RequestType::getcmd;
    setStatus(DeviceStatus::DownloadingFile);
}
