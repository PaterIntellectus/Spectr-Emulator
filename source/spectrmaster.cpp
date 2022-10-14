#include "spectrmaster.h"

SpectrMaster::SpectrMaster(const QString &connectionSettingsFilePath, const int id, QObject *parent)
    : SpectrAbstract{ id, parent }
    , mFile_connectionSettings{ connectionSettingsFilePath }
    , m_currentRequestType{ RequestTypes::getcmd }
    , m_emulationTimer{ new QTimer(this) }
    , m_cmd{ new Command(this) }
{
    qInfo() << "SpectrMaster construction...";

    m_emulationMode = false;

    updateConnectionSettings();

    initConnections();

    qInfo() << "/SpectrMaster constructed";
}

SpectrMaster::~SpectrMaster()
{
    qInfo() << "~SpectrMaster";

    if (m_emulationTimer->isActive())
        m_emulationTimer->stop();
}

void SpectrMaster::initConnections()
{
    qInfo() << "SpectrMaster::initConnections";

    // эмуляция:
    // отправка запроса по окончанию таймера
    connect(m_emulationTimer, &QTimer::timeout, [this](){ sendRequest(createQuery()); });
    // обработка полученного ответа
    connect(&m_networkManager, &QNetworkAccessManager::finished, this, &SpectrMaster::processReply);
}

void SpectrMaster::updateConnectionSettings()
{
    qInfo() << "SpectrMaster::updateConnectionSettings";
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
        emit errorOccured(QStringLiteral("Wrong port number: %1 [0 >> 65535]").arg(port));
    }
}

void SpectrMaster::setStatus(const DeviceStatus status)
{
    qInfo() << "SpectrMaster::setStatus";

    switch(status)
    {
    case DeviceStatus::Pending:
    case DeviceStatus::PlayingAudio:
    case DeviceStatus::AccidentOccured:
    case DeviceStatus::FirstRequest:
    // master only
    case DeviceStatus::DownloadingFile:
    case DeviceStatus::SpottingDifferences:
    case DeviceStatus::UploadingFile:
    case DeviceStatus::Verification:
    case DeviceStatus::Paused:
    case DeviceStatus::Sinchronization:
        SpectrAbstract::setStatus(status);
        break;
    default:
        errorOccured(QStringLiteral("Wrong master status!!!"));
        break;
    }
}

void SpectrMaster::toggleEmulationMode(bool onOff)
{
    qInfo() << "SpectrMaster::toggleEmulationMode";

    m_emulationMode = onOff;
    if (m_emulationMode) {
        m_emulationTimer->start(2000);
        emit newMessage(QStringLiteral("Emulation Started:"));
        qInfo() << "Emulation started";
    } else {
        m_emulationTimer->stop();
        emit newMessage(QStringLiteral("Emulation stopped"));
        qInfo() << "Emulation stopped";
    }
}

const QUrlQuery SpectrMaster::createQuery()
{
    qInfo() << "SpectrMaster::emulateQuery";

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("page"), mList_pages.at(static_cast<int>(m_currentRequestType)));
    query.addQueryItem(QStringLiteral("id"), QString::number(getIdInt()));

    switch(m_currentRequestType) {
    case RequestTypes::getcmd:
        query.addQueryItem(QStringLiteral("val"), QString::number(getInputsValInt()));
        query.addQueryItem(QStringLiteral("st"), QString::number(static_cast<int>(getStatusInt())));
        break;
    case RequestTypes::stcmd:
        query.addQueryItem(QStringLiteral("idcmd"), m_cmd->getIdStr());
        query.addQueryItem(QStringLiteral("st"), m_cmd->getStatusCodeStr());
        query.addQueryItem(QStringLiteral("err"), m_cmd->getErrorCodeStr());
        break;
    case RequestTypes::slist:
    case RequestTypes::flist:
    case RequestTypes::download:
        break;
    default:
        emit errorOccured(QStringLiteral("Can not prepare query: wrong request num"));
        break;
    }
    return query;
}

void SpectrMaster::sendRequest(QUrlQuery query)
{
    qInfo() << "SpectrMaster::sendRequest";
    m_emulationTimer->stop();

    QUrl url;
    url.setScheme("http");
    url.setHost(m_connectionSettings.host);
    url.setPort(m_connectionSettings.port);
    if (query.isEmpty()) {
        query = createQuery();
        // изменение параметра page, чтобы эмулятор понимал, на какую страницу передаётся запрос
        m_currentRequestType =
                static_cast<RequestTypes>(mList_pages.indexOf(query.queryItemValue(QStringLiteral("page"))));

    } // если query не передана, то она построится исходя из данных устройства
    url.setQuery(query);

    emit newMessage(QStringLiteral("Request: %1").arg(url.toString()));

    QNetworkRequest request{ url };
    m_networkManager.get(request);
}

void SpectrMaster::processReply(QNetworkReply *reply)
{
    qInfo() << "SpectrMaster::processReply";
    reply->deleteLater();

    auto replyData{ reply->readAll() };
    if (replyData.isEmpty()) {
        replyData = "Reply is empty!";
    }

    // showing server's reply, if it's not a file
    if (m_currentRequestType != RequestTypes::download) {
        emit newMessage(QStringLiteral("Reply: %1").arg(replyData));
    }

    // выбор действий на основе отправленного запроса
    if (m_currentRequestType == RequestTypes::getcmd) {
        if (replyData.startsWith("no")) {
            // todo: обработка всего остального, что есть в строке
            // получаемой при отсутствии новых команд
            // ...
//            emit newMessage(tr("No new commands"));
        } else {
            // выборка id из строки
            m_cmd->setId(replyData
                          .first(replyData.indexOf(';')) // возвразает байты до первого знака ';'
                          .sliced(replyData.indexOf('=') + 1) // возвращает байты после знака '='
                          .toInt() // конвертирует строку в int
                         );

            // измененние параметров устройства
            m_currentRequestType = RequestTypes::stcmd;
            m_cmd->setStatus(Command::CommandStatuses::Completed);
            setStatus(DeviceStatus::Pending);

            // todo:
//            auto cmd { replyData
//                        .sliced(replyData.indexOf(' ') + 1) // возврат байт после пробела разделющего параметры
//                        .split('=')
//                        };

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

    } else if (m_currentRequestType == RequestTypes::stcmd) {
        if (replyData == "ok") {
            m_currentRequestType = RequestTypes::getcmd;
        }

    } else if (m_currentRequestType == RequestTypes::slist) {
        // todo: при получении списка id устройств, создавать новые устройства и удалять отключенные

    } else if (m_currentRequestType == RequestTypes::flist) {
        // todo: при получении списка фудио файлов, проверять их и скачивать все нужные

    } else if (m_currentRequestType == RequestTypes::download) {
        // todo: закачка аудио файла

    } else {
        errorOccured(QStringLiteral("Can not process reply!!!!"));
        return;
    }
    qInfo() << "Request Type:" << static_cast<int>(m_currentRequestType);
    if (m_emulationMode) {
        m_emulationTimer->start(2000);
    }
}
