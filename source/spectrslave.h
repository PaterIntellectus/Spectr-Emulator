#ifndef SPECTRSLAVE_H
#define SPECTRSLAVE_H

#include "spectrabstract.h"
#include <QObject>

class SpectrSlave : public SpectrAbstract
{
    Q_OBJECT
public:
    SpectrSlave(const int id, const DeviceStatus status = DeviceStatus::FirstRequest, QObject *parent = nullptr);
    SpectrSlave(const SpectrSlave &spectrDevice);
    SpectrSlave(const SpectrSlave &&spectrDevice);
    explicit SpectrSlave(QObject *parent = nullptr);
    ~SpectrSlave();

    SpectrSlave &operator=(const SpectrSlave &spectrDevice);


private:
    virtual void initConnections();

public slots:
    virtual void setStatus(const DeviceStatus status);

};

#endif // SPECTRDEVICE_H
