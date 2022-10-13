#ifndef SPECTRDEVICE_H
#define SPECTRDEVICE_H

#include "spectrabstract.h"
#include <QObject>

class SpectrDevice : public SpectrAbstract
{
    Q_OBJECT
public:
    explicit SpectrDevice(const int devId = 0, QObject *parent = nullptr);
    ~SpectrDevice();

private:
    virtual void initConnections();

public slots:
    virtual void setStatus(const DeviceStatus status);

};

#endif // SPECTRDEVICE_H
