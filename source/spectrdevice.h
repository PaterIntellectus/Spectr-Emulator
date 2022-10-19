#ifndef SPECTRDEVICE_H
#define SPECTRDEVICE_H

#include "spectrabstract.h"
#include <QObject>

class SpectrDevice : public SpectrAbstract
{
    Q_OBJECT
public:
    SpectrDevice(const int id, const DeviceStatus status, QObject *parent = nullptr);
    SpectrDevice(const SpectrDevice &spectrDevice);
    SpectrDevice(const SpectrDevice &&spectrDevice);
    explicit SpectrDevice(QObject *parent = nullptr);
    ~SpectrDevice();

    SpectrDevice &operator=(const SpectrDevice &spectrDevice);

private:
    virtual void initConnections();

public slots:
    virtual void setStatus(const DeviceStatus status);

};

#endif // SPECTRDEVICE_H
