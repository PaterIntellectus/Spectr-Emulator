#include "spectremulator.h"

SpectrEmulator::SpectrEmulator(const int id, const QString &connectionSettingsFilePath, QObject *parent)
    : SpectrMaster{ id, DeviceStatus::FirstRequest, parent }
    , mFile_connectionSettings{ connectionSettingsFilePath }
    , m_networkManager{ new QNetworkAccessManager(this) }
    , m_emulationTimer{ new QTimer(this) }
    , m_requestType{ RequestType::getcmd }
    , m_emulationMode{ false }
{
    qInfo() << "SpectrEmulator construction...";

    updateConnectionSettings();
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

void SpectrEmulator::updateConnectionSettings()
{
    qInfo() << "SpectrEmulator::updateConnectionSettings";

    mFile_connectionSettings.open(QIODevice::ReadOnly);
    QTextStream stream{ &mFile_connectionSettings };

    QString address, port;
    stream >> address >> port;

    mFile_connectionSettings.close();

    if (m_connectionSettings.host != address) {
        m_connectionSettings.host = address;
    }
    if (0 < port.toInt() && port.toInt() < 65534) {
        m_connectionSettings.port = port.toUShort();
    } else {
        emit errorOccured(tr("Неверный номер порта: %1 [0 >> 65535]").arg(port));
    }
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
    url.setHost(m_connectionSettings.host);
    url.setPort(m_connectionSettings.port);
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
    case RequestType::download:
        break;
    default:
        emit errorOccured(QStringLiteral("Can not prepare query: wrong request num"));
        break;
    }
    return query;
}

void SpectrEmulator::processReply(QNetworkReply *reply)
{
    qInfo() << "SpectrEmulator::processReply";
    reply->deleteLater();

    // only for debug purposes
    qInfo() << "Replie's headers:";
    for (auto headerName : reply->rawHeaderList()) {
        qInfo() << reply->rawHeader(headerName);
    }

    auto replyData{ reply->readAll() };
    if (replyData.isEmpty()) {
        emit newMessage(tr("Получен пустой ответ!"));
        return;
    }

    // showing server's reply, ONLY if it's not a file
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
        // todo: при получении списка id устройств, создавать новые устройства и удалять отключенные
        processFlistReply(replyData);
        break;
    case RequestType::flist:
        // todo: при получении списка фудио файлов, проверять их и скачивать все нужные
        processSlistReply(replyData);
        break;
    case RequestType::download:
        processDownloadReply(reply, replyData);
        break;
    default:
        emit errorOccured(tr("Не существует такого типа запроса"));
        return;
    }
    qInfo() << "Request Type:" << static_cast<int>(m_requestType);

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
        auto list_{ replyData.split(',') };

    } else if (replyData.startsWith("id")) {

        auto list_cmdData = replyData.split("; ", Qt::SkipEmptyParts);
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
            auto cmdParameters{ cmdText.split(',', Qt::SkipEmptyParts) };
            // воспроизведение файла
            if (playFile(cmdParameters.at(0), cmdParameters.at(1), cmdParameters.at(2))) {
                setStatus(DeviceStatus::PlayingAudio);
                m_requestType = RequestType::stcmd;
            } else {
                setStatus(DeviceStatus::AccidentOccured);
                m_requestType = RequestType::download;
            }

        } else {
            setStatus(DeviceStatus::Pending);
        }

        // измененние параметров устройства
        m_cmd->setStatus(Command::CommandStatuses::Completed);

        // выставление статуса устройства
//        auto cmdName {
//                    .split('=')
//                    };
//        if (cmdName == "play") {

//        } else {}
    } else {
        emit errorOccured(tr("Получена неизвестная команда"));
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

    if (replyData == "ok") {
        setStatus(DeviceStatus::Pending);
        m_requestType = RequestType::getcmd;
    } else {
        setStatus(DeviceStatus::AccidentOccured);
        m_requestType = RequestType::stcmd;

        emit errorOccured(tr("Не получилось подтвердить команду"));
        return;
    }

}

void SpectrEmulator::processFlistReply(const QString &replyData)
{
    qInfo() << "SpectrEmulator::processFlistReply";

}

void SpectrEmulator::processSlistReply(const QString &replyData)
{
    qInfo() << "SpectrEmulator::processSlistReply";

}

void SpectrEmulator::processDownloadReply(const QNetworkReply *reply, const QByteArray &replyData)
{
    qInfo() << "SpectrEmulator::processDownloadReply";

    auto str_dispositionHeader{ reply->header(QNetworkRequest::ContentDispositionHeader).toString() };
    QString filename{ "track_file.mp3" };
    for (auto &str : str_dispositionHeader.split(';', Qt::SkipEmptyParts)) {
        if (str.contains(QStringLiteral("filename="))) {
            filename = str.sliced(str.indexOf('=') + 1);
        }
    }
    qInfo() << "filename:" << filename;
    // создание директории и аудио файла
    QDir::current().mkdir(QStringLiteral("audio"));
    QFile file_audio{ QStringLiteral("audio/") + filename };

    // сохранение файла
    if (!file_audio.open(QIODevice::WriteOnly)) {
        emit newMessage(tr("Невозможно открыть файл для записи!!!"));
        return;
    }
    file_audio.write(replyData);
    file_audio.close();

    m_requestType = RequestType::getcmd;
    setStatus(DeviceStatus::DownloadingFile);

    emit newMessage(tr("Аудио трек %1 закачан.").arg(filename));
}
