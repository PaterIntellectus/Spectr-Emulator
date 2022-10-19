#ifndef SPECTREMULATOR_H
#define SPECTREMULATOR_H

#include "spectrmaster.h"
#include <QObject>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QUrl>

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFile>
#include <QDir>

#include <QTimer>


class SpectrEmulator : public SpectrMaster
{
    Q_OBJECT
public:
    explicit SpectrEmulator(const int id, const QString &connectionSettingsFilePath, QObject *parent = nullptr);

    ~SpectrEmulator();

    enum class RequestType : unsigned int {
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

signals:


public slots:
    void updateConnectionSettings();

    void toggleEmulationMode(bool onOff);

    void sendRequest(const RequestType requestType, QUrlQuery query = QUrlQuery());


private slots:
    const QUrlQuery createQuery();
    void processReply(QNetworkReply *reply);

    void processGetcmdReply(const QString &replyData);
    void processStcmdReply(const QString &replyData);
    void processFlistReply(const QString &replyData);
    void processSlistReply(const QString &replyData);
    void processDownloadReply(const QNetworkReply *reply, const QByteArray &replyData);

private:
    // настройки подключения
    ConnectionSettings m_connectionSettings;
    QFile mFile_connectionSettings;

    QNetworkAccessManager *m_networkManager{ nullptr };

    // объекты эмуляции
    QTimer *m_emulationTimer{ nullptr };
    bool m_emulationMode;



    QList<QString> mList_pages{
        "getcmd", "stcmd", "slist", "flist", "download"
    };
    RequestType m_requestType;
};

#endif // SPECTREMULATOR_H
