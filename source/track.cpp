#include "track.h"

Track::Track(const QString &name, QStringView strv_lastModified)
{
    qInfo() << "Track construction...";

    setName(name);
    setLastModified(strv_lastModified);

    qInfo() << "/Track constructed";
}

Track::Track(const int num, QStringView strv_lastModified)
    : Track(createTrackNameByNumber(num), strv_lastModified)
{
}

Track::Track()
    : Track(QStringLiteral(), QStringLiteral())
{
}

void Track::setName(const QString &name)
{
    m_fileName = name;
}

void Track::setLastModified(QStringView strv_lastModified)
{
    qInfo() << "Track::setLastModified";

    qInfo() << "strv_lastModified" << strv_lastModified;

    if (strv_lastModified.isEmpty()) {
        mDateTime_lastModified.setDate(QDate());
        mDateTime_lastModified.setTime(QTime());
        return;
    }

    auto listStrv_dateTime{ strv_lastModified.split(' ', Qt::SkipEmptyParts) };
    auto listStrv_date{ listStrv_dateTime.at(0).split('.', Qt::SkipEmptyParts) };
    auto listStrv_time{ listStrv_dateTime.at(1).split(':', Qt::SkipEmptyParts) };

    mDateTime_lastModified.setDate(
                QDate(listStrv_date.at(0).toInt(), listStrv_date.at(1).toInt(), listStrv_date.at(2).toInt())
                );
    mDateTime_lastModified.setTime(
                QTime(listStrv_time.at(0).toInt(), listStrv_time.at(1).toInt(), listStrv_time.at(2).toInt())
                );
}
