#include "spectrnetworkmanager.h"

SpectrNetworkManager::SpectrNetworkManager(QObject *parent)
    : QNetworkAccessManager{parent}
    , m_emulationTimer{ new QTimer(this) }

    , m_requestType{ RequestType::getcmd }
    , m_automaticMode{ false }
{
    qInfo() << "SpectrNetworkManager construction...";

    initConnectionSettings();
    initConnections();

    qInfo() << "/SpectrNetworkManager constructed";
}


SpectrNetworkManager::~SpectrNetworkManager()
{
    qInfo() << "~SpectrNetworkManager";

    if (m_emulationTimer->isActive())
        m_emulationTimer->stop();
}

void SpectrNetworkManager::initConnections()
{
    qInfo() << "SpectrNetworkManager::initConnections";

}

void SpectrNetworkManager::initConnectionSettings()
{
    qInfo() << "SpectrNetworkManager::setConnectionSettings";

    QFile connectionSettingsFile{ connectionSettingsFilePath };
    if (connectionSettingsFile.open(QIODevice::ReadOnly)) {
        QTextStream stream{ &connectionSettingsFile };
        stream >> mPair_hostPort.first >> mPair_hostPort.second;
        connectionSettingsFile.close();
    } else {
        emit errorMessage(tr("Не получилось открыть файл настроек подключения."));
        return;
    }
}

