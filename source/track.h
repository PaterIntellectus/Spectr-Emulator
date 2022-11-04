#ifndef TRACK_H
#define TRACK_H

#include <QDateTime>
#include <QDebug>

static const QString lastModifiedDateFormal{ "yyyy.MM.dd hh:mm:ss" };
static const QString trackDateFormat{ "yyyy.MM.dd" };
static const QString trackTimeFormat{ "hh:mm:ss" };

class Track
{
public:
    Track(const QString &name, QStringView strv_lastModified);
    Track(const int num, QStringView strv_lastModified);
    explicit Track();

    operator bool() const { return !fileName().isEmpty(); }

    static const QString createTrackNameByNumber(const int trackNum) {
        return QStringLiteral("track%1.mp3").arg(trackNum, 2, 10, QChar('0'));
    }

    const QDateTime& lastModified() const { return mDateTime_lastModified; }
    const QString &fileName() const { return m_fileName; }

    friend bool operator==(const Track &left, const Track &right) { return left.fileName() == right.fileName(); }

private:
    void setName(const QString &name);
    void setLastModified(QStringView strv_lastModified);

    QString m_fileName;
    QDateTime mDateTime_lastModified;
};

#endif // TRACK_H
