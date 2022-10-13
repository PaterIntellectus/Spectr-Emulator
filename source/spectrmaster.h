#ifndef SPECTRMASTER_H
#define SPECTRMASTER_H

#include "spectrabstract.h"
#include <QObject>

#include "spectrdevice.h"
#include "command.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QUrl>

#include <QFile>

#include <QTimer>

class SpectrMaster : public SpectrAbstract
{
    Q_OBJECT
public:
    explicit SpectrMaster(const QString &connectionSettingsFilePath, const int id, QObject *parent = nullptr);
    ~SpectrMaster();

    enum class RequestTypes : unsigned int {
        getcmd = 0, stcmd = 1,
        slist = 2, flist = 3,
        download = 4
    };
    struct ConnectionSettings {
        QString host;
        quint16 port;
    };

private:
    virtual void initConnections();

    void playAudio(int fileNum, int seconds, int milliseconds);

public slots:
    void updateConnectionSettings();
    virtual void setStatus(const DeviceStatus status);

    void sendRequest(QUrlQuery query = QUrlQuery());

    void toggleEmulationMode(bool onOff);


private slots:
    const QUrlQuery createQuery();
    void processReply(QNetworkReply *reply);

private:
    QList<SpectrDevice> mList_slaves;
    // параметры получаемой команды
    Command *m_cmd{ nullptr };

    ConnectionSettings m_connectionSettings;
    QFile mFile_connectionSettings;

    QList<QString> mList_pages{
        "getcmd", "stcmd", "slist", "flist", "download"
    };
    RequestTypes m_currentRequestType;


    // объекты эмуляции
    QTimer *m_emulationTimer{ nullptr };
    bool m_emulationMode;

    QNetworkAccessManager m_networkManager;

};

#endif // SPECTRMASTER_H
