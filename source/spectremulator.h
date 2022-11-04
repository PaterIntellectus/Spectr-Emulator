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

#include <QRegularExpression>

#include <QTimer>

#include "DirAndFileNames.h"

class SpectrEmulator : public SpectrMaster
{
    Q_OBJECT
public:
    explicit SpectrEmulator(const int id, QObject *parent = nullptr);

    ~SpectrEmulator();

    enum class RequestType : unsigned int {
        getcmd = 0, stcmd = 1,
        slist = 2, flist = 3,
        download = 4
    };

private:
    virtual void initConnections();

    void setRequestType(RequestType requestType) { m_requestType = requestType; }

signals:

    void finished(bool);


public slots:
    void initConnectionSettings();
    void updateHost(QStringView host) { if (host != mPair_hostPort.first) { mPair_hostPort.first = std::move(host.toString()); } }
    void updatePort(const quint16 port) { if (port != mPair_hostPort.second) { mPair_hostPort.second = port; } }

    void toggleAutomaticMode(bool onOff);

    void sendRequest(const RequestType requestType, QUrlQuery query = QUrlQuery());

private slots:
    const QUrlQuery createQuery();
    void processReply(QNetworkReply *reply);

    void processGetcmdReply(const QByteArray &replyData);
    void processStcmdReply(const QByteArray &replyData);
    void processSlistReply(const QByteArray &replyData);
    void processFlistReply(const QNetworkReply *reply, const QByteArray &replyData);
    void processDownloadReply(const QNetworkReply *reply, const QByteArray &replyData);

    void syncWithServer(const QByteArray &bArr_serverParameters);
    void executeCmd(const Command &cmd);
    void executePlayCmd(const Command &cmd);
    void executeQuietCmd(const Command &cmd);
    void executeStopCmd(const Command &cmd);
    void executeGetFileCmd(const Command &cmd);
    void executeOutCmd(const Command  &cmd);

private:

    QPair<QString, quint16> mPair_hostPort;
    QNetworkAccessManager *m_networkManager{ nullptr };

    QList<QString> mList_pages{
        "getcmd", "stcmd", "slist", "flist", "download"
    };
    RequestType m_requestType;

    QTimer *m_emulationTimer{ nullptr };
    bool mB_automaticMode;
};

#endif // SPECTREMULATOR_H
