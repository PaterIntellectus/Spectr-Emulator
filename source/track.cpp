#include "track.h"

Track::Track(QStringView name, QStringView strv_lastModified)
    : trackFile{ name.toString() }
{
    qInfo() << "Track construction...";

    setLastModified(strv_lastModified);

    qInfo() << "/Track constructed";
}

void Track::setLastModified(const QStringView strv_lastModified)
{
    qInfo() << "Track::setLastModified";

    auto listStrv_dateTime{ strv_lastModified.split(' ', Qt::SkipEmptyParts) };
    auto listStrv_date{ listStrv_dateTime.at(0).split('.', Qt::SkipEmptyParts) };
    auto listStrv_time{ listStrv_dateTime.at(1).split(':', Qt::SkipEmptyParts) };

    this->dateTime_lastModified.setDate(
                QDate(listStrv_date.at(0).toInt(), listStrv_date.at(1).toInt(), listStrv_date.at(2).toInt())
                );
    this->dateTime_lastModified.setTime(
                QTime(listStrv_time.at(0).toInt(), listStrv_time.at(1).toInt(), listStrv_time.at(2).toInt())
                );
}
