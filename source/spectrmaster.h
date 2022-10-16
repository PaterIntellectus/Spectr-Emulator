#ifndef SPECTRMASTER_H
#define SPECTRMASTER_H

#include "spectrabstract.h"
#include <QObject>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QUrl>

#include "spectrdevice.h"
#include "command.h"

class SpectrMaster : public SpectrAbstract
{
    Q_OBJECT
public:
    SpectrMaster(const int id, const DeviceStatus status, QObject *parent = nullptr);
    SpectrMaster(const SpectrMaster &spectrDevice);
    explicit SpectrMaster(QObject *parent = nullptr);

    ~SpectrMaster();

private:
    virtual void initConnections();

public slots:
    virtual void setStatus(const DeviceStatus status);

    const QList<int> getSlaveIdList();

private slots:


protected:
    QList<SpectrDevice> mList_slaveDevices;
    // параметры получаемой команды
    Command *m_cmd{ nullptr };

};

#endif // SPECTRMASTER_H
