#ifndef TRACKMANAGER_H
#define TRACKMANAGER_H

#include <QObject>

#include <QDir>
#include <QFile>
#include <QDateTime>
#include <QMediaPlayer>
#include <QAudioOutput>

#include <QSharedPointer>
#include <QQueue>

#include "track.h"

static const QString tracksDirectory{ "tracks/" };
static const QString trackListFileName{ "trackList.txt" };

static const QString lastModifiedDateFormal{ "yyyy.MM.dd hh:mm:ss" };
static const QString trackDateFormat{ "yyyy.MM.dd" };
static const QString trackTimeFormat{ "hh:mm:ss" };


class TrackManager : public QObject
{
    Q_OBJECT
public:
    explicit TrackManager(QObject *parent = nullptr);
    TrackManager(const QList<int> list_trackNum, QObject *parent = nullptr);
    ~TrackManager();

    const QString createTrackName(const int trackNum) const {
        return QStringLiteral("track%1.mp3").arg(trackNum, 2, 10, QChar('0'));
    }
    const QString getTrackRelativePath(const int trackNum) {
        return getTrackRelativePath(createTrackName(trackNum));
    }
    const QString getTrackRelativePath(QStringView trackName) {
        return tracksDirectory + trackName.toString();
    }

private:
    void initConnections();

    void initTracks();

    void appendTrackList(const QString &name, const QString &lastModified);

    void saveTracksList();

    QSharedPointer<Track> getTrackPtr(QStringView trackName);
    QSharedPointer<Track> getTrackPtr(const int trackNum);

signals:
    void errorMessage(const QString &message);
    void newMessage(const QString &message);

public slots:
    bool saveTrack(const QString &trackName, const QByteArray &trackData, const QString &lastModified);

    bool playTrack(QStringView trackName);
    bool playTrack(const int trackNum);

    const QByteArray calculateCrc32(const QString &trackName);
    const QByteArray calculateCrc32(const int trackNum);

private slots:
    const quint32 calculateCrc32(const QByteArray data);

private:
    QList<QSharedPointer<Track>> mList_tracks;

    quint32 allTracksCrc;

    QMediaPlayer *mMediaPlayer{ nullptr };
    QAudioOutput *mAudioOutput{ nullptr };
};

#endif // TRACKMANAGER_H
