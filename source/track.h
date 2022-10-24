#ifndef TRACK_H
#define TRACK_H

#include <QFile>
#include <QDateTime>

class Track
{
public:
    Track(const QStringView name, const QStringView strv_lastModified);

    QString name() { return trackFile.fileName(); }
    const QDateTime& lastModified() { return dateTime_lastModified; }

private:
    void setLastModified(const QStringView strv_lastModified);

    QFile trackFile;
    QDateTime dateTime_lastModified;
};

#endif // TRACK_H
