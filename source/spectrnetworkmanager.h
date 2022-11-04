#ifndef SPECTRNETWORKMANAGER_H
#define SPECTRNETWORKMANAGER_H

#include <QNetworkAccessManager>
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
#include <QTextStream>

#include <QTimer>

#include "DirAndFileNames.h"

using PairHostPort = QPair<QString, quint16>;

class SpectrNetworkManager : public QNetworkAccessManager
{
    Q_OBJECT
public:
    explicit SpectrNetworkManager(QObject *parent = nullptr);

    ~SpectrNetworkManager();

    enum class RequestType : unsigned int {
        getcmd = 0, stcmd = 1,
        slist = 2, flist = 3,
        download = 4
    };

private:
    virtual void initConnections();

signals:
    void errorMessage(QStringView errorMessage);
    void newMessage(QStringView message);

public slots:
    void initConnectionSettings();

//    void toggleAutomaticMode(bool onOff);

//    void getcmd();
//    void stcmd();
//    void flist();
//    void slist();
//    void download();

private slots:



//    const QUrlQuery createQuery();
//    void processReply(QNetworkReply *reply);

//    void processGetcmdReply(const QString &replyData);
//    void processStcmdReply(const QString &replyData);
//    void processSlistReply(const QString &replyData);
//    void processFlistReply(const QNetworkReply *reply, const QByteArray &replyData);
//    void processDownloadReply(const QNetworkReply *reply, const QByteArray &replyData);

private:
    PairHostPort mPair_hostPort;

    QTimer *m_emulationTimer{ nullptr };
    bool m_automaticMode;

    QList<QString> mList_pages{
        "getcmd", "stcmd", "slist", "flist", "download"
    };
    RequestType m_requestType;

};

#endif // SPECTRNETWORKMANAGER_H
