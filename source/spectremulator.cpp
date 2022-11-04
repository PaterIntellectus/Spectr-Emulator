#include "spectremulator.h"

SpectrEmulator::SpectrEmulator(const int id, QObject *parent)
    : SpectrMaster{ id, DeviceStatus::FirstRequest, parent }

    , m_networkManager{ new QNetworkAccessManager(this) }
    , m_emulationTimer{ new QTimer(this) }

    , m_requestType{ RequestType::getcmd }
    , mB_automaticMode{ false }
{
    qInfo() << "SpectrEmulator construction...";

    initConnectionSettings();

    initConnections();

    qInfo() << "/SpectrEmulator constructed";
}

SpectrEmulator::~SpectrEmulator()
{
    qInfo() << "~SpectrEmulator";
}

void SpectrEmulator::initConnections()
{
    qInfo() << "SpectrEmulator::initConnections";

    connect(m_emulationTimer, &QTimer::timeout, [this](){ sendRequest(m_requestType); });
    connect(m_networkManager, &QNetworkAccessManager::finished, this, &SpectrEmulator::processReply);
}

void SpectrEmulator::initConnectionSettings()
{
    qInfo() << "SpectrEmulator::setConnectionSettings";

    QFile connectionSettingsFile{ connectionSettingsFilePath };
    connectionSettingsFile.open(QIODevice::ReadOnly);

    QTextStream stream{ &connectionSettingsFile };
    QString host;
    quint16 port;
    stream >> host >> port;

    connectionSettingsFile.close();

    updateHost(host);
    updatePort(port);
}

void SpectrEmulator::toggleAutomaticMode(bool onOff)
{
    qInfo() << "SpectrEmulator::toggleEmulationMode";

    mB_automaticMode = onOff;
    if (!mB_automaticMode) {
        m_emulationTimer->stop();
        emit newMessage(tr("Эмуляция окончена"));
        return;
    }

    setStatus(DeviceStatus::FirstRequest);
    setRequestType(RequestType::getcmd);
    m_emulationTimer->start(2000);
    emit newMessage(tr("Эмуляция началась:"));
}

void SpectrEmulator::sendRequest(const RequestType requestType, QUrlQuery query)
{
    qInfo() << "SpectrEmulator::sendRequest";
    m_emulationTimer->stop();

    setRequestType(requestType);

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
    qInfo() << "SpectrEmulator::createQuery";

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("page"), mList_pages.at(static_cast<int>(m_requestType)));
    query.addQueryItem(QStringLiteral("id"), QString::number(getId()));

    switch(m_requestType)
    {
    case RequestType::getcmd:
        query.addQueryItem(QStringLiteral("val"), QString::number(getRelaysVal()));
        query.addQueryItem(QStringLiteral("st"), QString::number(static_cast<int>(getStatus())));
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
        query.addQueryItem(QStringLiteral("num"), QString::number(m_trackManager->remindTrackNum()));
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

    // shows all Reply's headers
//    qInfo() << "Replie's headers:";
//    for (auto headerPair : reply->rawHeaderPairs()) {
//        qInfo() << headerPair.first << ':' << headerPair.second;
//    }

    auto replyData{ reply->readAll() };
    if (replyData.isEmpty()) {
        emit errorMessage(tr("Нет ответа от сервера"));
        setStatus(DeviceStatus::AccidentOccurred);
        m_cmd->setStatus(Command::Status::NoCommand);
        return;
    }

    // showing server's reply, ONLY if it's not a file's download request
    if (m_requestType != RequestType::download) {
        emit newMessage(tr("Ответ: ") + replyData);
    }

    // выбор обработчика на основе отправленного запроса
    const auto &page{ QUrlQuery(reply->url().query()).queryItemValue("page") };
    if (page == "getcmd") {
        processGetcmdReply(replyData);

    } else if (page == "stcmd") {
        processStcmdReply(replyData);

    } else if (page == "slist") {
        processSlistReply(replyData);

    } else if (page == "flist") {
        processFlistReply(reply, replyData);

    } else if (page == "download") {
        processDownloadReply(reply, replyData);

    } else {
        emit errorMessage(tr("Неизвестный "));

    }
    qInfo() << "Request Type:" << static_cast<int>(m_requestType);

    if (mB_automaticMode) {
        m_emulationTimer->start(2000);
    }
}

void SpectrEmulator::processGetcmdReply(const QByteArray &replyData)
{
    qInfo() << "SpectrEmulator::processGetcmdReply";

    if (replyData.startsWith("no")) {
        syncWithServer(replyData);
        return;
    }
        // полученная команда всегда начинается с id
    if (replyData.startsWith("id")) {
        executeCmd(Command(replyData));
        return;
    }
    emit errorMessage(tr("Получена неизвестная команда"));
}

void SpectrEmulator::processStcmdReply(const QByteArray &replyData)
{
    qInfo() << "SpectrEmulator::processStcmdReply";

    if (replyData != "ok") {
        emit errorMessage(tr("Сервер не подтвердил команду"));
    }
    setRequestType(RequestType::getcmd);
}

void SpectrEmulator::processSlistReply(const QByteArray &replyData)
{
    qInfo() << "SpectrEmulator::processSlistReply";

    if (replyData == "no") {
        emit newMessage(tr("У данного мастера нет Slave устройств"));
        return;
    }
    QList<int> list_slaveId;
    for (const auto &bArr_slaveId : replyData.split(';')) {
        if (bArr_slaveId.isEmpty()) { continue; }
        list_slaveId.append(bArr_slaveId.toInt());
    }
    initSlaveList(list_slaveId);
}

void SpectrEmulator::processFlistReply(const QNetworkReply *reply, const QByteArray &replyData)
{
    qInfo() << "SpectrEmulator::processFlistReply";

    emit newMessage(tr("Поиск файлов..."));
    for (const auto &trackLine : replyData.split(';')) {
        if (trackLine.isEmpty()) { continue; }

        auto trackNum{ trackLine.first(trackLine.indexOf(',')).toInt() };
        auto receivedCrc{ trackLine.sliced(trackLine.indexOf(',') + 1) };

        auto trackCrc{
            QByteArray::number(m_trackManager->calculateCrc32Track(trackNum),16)
                    .rightJustified(8, '0')
        };
        if (trackCrc.isEmpty()) {
            continue;
        }
        emit newMessage(
                    QStringLiteral("%1: %2 %4 %3(server)")
                    .arg(Track::createTrackNameByNumber(trackNum))
                    .arg(trackCrc).arg(receivedCrc)
                    .arg(receivedCrc == trackCrc ? "==" : "!=")
                    );
    }
}

void SpectrEmulator::processDownloadReply(const QNetworkReply *reply, const QByteArray &replyData)
{
    qInfo() << "SpectrEmulator::processDownloadReply";

    auto str_dispositionHeader{ reply->header(QNetworkRequest::ContentDispositionHeader).toString() };
    QString trackName{ str_dispositionHeader.sliced(str_dispositionHeader.indexOf('=') + 1) };

    m_trackManager->createNewTrack(
                Track(trackName, static_cast<QString>(reply->rawHeader("Last-Modified")))
                , replyData);

    m_cmd->setStatus(Command::Status::Completed);
    setStatus(DeviceStatus::DownloadingFile);
    setRequestType(RequestType::stcmd);
}

void SpectrEmulator::syncWithServer(const QByteArray &bArr_serverParameters)
{
    qInfo() << "SpectrEmulator::syncWithServer";
    // todo: обработка всего остального, что есть в строке
    // получаемой при отсутствии новых команд
    // ...

    auto list_masterData{ bArr_serverParameters.split(',') };
    auto slaveStatus{ list_masterData.at(1) };
    auto serverTracksCrc32{ list_masterData.at(2) };
    auto seconds{ list_masterData.at(3) };

    emit newMessage(tr(
                        "Slave status: %1\n"
                        "crc32 треков сервера: %2\n"
                        "Время в секундах + милисекундах: %3"
                        ).arg(slaveStatus).arg(serverTracksCrc32).arg(seconds)
                    );

    emit newMessage(
                QString::number(m_trackManager->calculateCrc32OfAllTracks(), 16)
                .rightJustified(8, '0')
                );

}

void SpectrEmulator::executeCmd(const Command &cmd)
{
    qInfo() << "SpectrEmulator::executeCmd" << cmd.getName() << cmd.getId();

    const auto cmdName{ cmd.getName() };
    emit cmdReceived(cmd.getId());

    if (cmdName == "play") {
        executePlayCmd(cmd);

    } else if (cmdName == "quiet") {
        executeQuietCmd(cmd);

    } else if (cmdName == "stop") {
        executeStopCmd(cmd);

    } else if (cmdName == "getfile") {
        executeGetFileCmd(cmd);

    } else if (cmdName == "out") {
        executeOutCmd(cmd);

    } else {
        emit errorMessage(tr("Получена неизвестная команда"));
        setStatus(DeviceStatus::Pending);
    }
}

void SpectrEmulator::executePlayCmd(const Command &cmd)
{
    qInfo() << "SpectrEmulator::executePlayCmd";

    // воспроизведение файла
    if (m_trackManager->playTrack(cmd.getArguments().at(0))) {
        setStatus(DeviceStatus::PlayingAudio);
        m_cmd->setStatus(Command::Status::Completed);
        m_cmd->setErrorCode(Command::Error::NoError);
        setRequestType(RequestType::stcmd);
    } else {
        m_cmd->setStatus(Command::Status::ErrorOccured);
        m_cmd->setErrorCode(Command::Error::CannotOpenAudioFile);
    }
}

void SpectrEmulator::executeQuietCmd(const Command &cmd)
{
    qInfo() << "SpectrEmulator::executeQuietCmd";

    // воспроизведение файла
    if (m_trackManager->playTrack(cmd.getArguments().at(0), 0.2)) {
        setStatus(DeviceStatus::PlayingAudio);
        m_cmd->setStatus(Command::Status::Completed);
        m_cmd->setErrorCode(Command::Error::NoError);
    } else {
        m_cmd->setStatus(Command::Status::ErrorOccured);
        m_cmd->setErrorCode(Command::Error::CannotOpenAudioFile);
    }
    setRequestType(RequestType::stcmd);
}

void SpectrEmulator::executeStopCmd(const Command &cmd)
{
    qInfo() << "SpectrEmulator::executeStopCmd";

    m_trackManager->stopPlaying();
    setStatus(DeviceStatus::Pending);
    m_cmd->setStatus(Command::Status::Completed);
    setRequestType(RequestType::stcmd);
}

void SpectrEmulator::executeGetFileCmd(const Command &cmd)
{
    qInfo() << "SpectrEmulator::executeGetFileCmd";

    m_trackManager->rememberTrackNum(cmd.getArguments().at(0));
    setRequestType(RequestType::download);
}

void SpectrEmulator::executeOutCmd(const Command &cmd)
{
    qInfo() << "SpectrEmulator::executeOutCmd";

    // переключение Реле
    auto arguments{ cmd.getArguments() };
    if (toggleRelay(arguments.at(0) * 10 + arguments.at(1), arguments.at(2))) {
        setStatus(DeviceStatus::Pending);
        m_cmd->setStatus(Command::Status::Completed);
    } else {
        m_cmd->setStatus(Command::Status::ErrorOccured);
        m_cmd->setErrorCode(Command::Error::WrongParameter);
    }
    setRequestType(RequestType::stcmd);
}
