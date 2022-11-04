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

static const QString defaultTracksDirectory{ "tracks/" };
static const QString trackListFileName{ "trackList.txt" };


class TrackManager : public QObject
{
    Q_OBJECT
public:
    TrackManager(const QString &tracksDirPath, QObject *parent = nullptr);
    explicit TrackManager(QObject *parent = nullptr);
    ~TrackManager();

private:
    void initConnections();

    void initTrackList();

    void appendTrackList(const Track &newTrack);

    void saveTrackList() const;

signals:
    void errorMessage(QStringView str_error) const;
    void newMessage(QStringView message) const;

    void stopPlaying();

public slots:
    void rememberTrackNum(int trackNum);
    int remindTrackNum() { return m_trackNum; }


    bool createNewTrack(const Track &newTrack, const QByteArray &trackData);
    const std::optional<Track> findTrack(const QString &trackName) const;
    bool playTrack(const QString &trackName, const float volume = 0.8);
    bool playTrack(const int trackNum, const float volume = 0.8);

    const quint32 calculateCrc32Track(const QString &trackName) const;
    const quint32 calculateCrc32Track(const int trackNum) const;

    const quint32 calculateCrc32OfAllTracks() const;

private slots:
    const quint32 calculateCrc32Track(const Track &track) const;
    const quint32 calculateCrc32(const QByteArray &data) const;

private:
    const QDir tracksDir;

    QList<Track> mList_tracks;

    int m_trackNum;

    QMediaPlayer *mMediaPlayer{ nullptr };
    QAudioOutput *mAudioOutput{ nullptr };
};

#endif // TRACKMANAGER_H
