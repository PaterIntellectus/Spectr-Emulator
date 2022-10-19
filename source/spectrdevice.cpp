#include "spectrdevice.h"

SpectrDevice::SpectrDevice(const int id, const DeviceStatus status, QObject *parent)
    : SpectrAbstract{ id, status, parent }
{
    qInfo() << "SpectrDevice construction...";

    qInfo() << "SpectrDevice id:" << id;

    initConnections();

    qInfo() << "/SpectrDevice constructed";
}

SpectrDevice::SpectrDevice(const SpectrDevice &spectrDevice)
    : SpectrDevice{ spectrDevice.getId(), spectrDevice.getStatus(), spectrDevice.parent() }
{

}

SpectrDevice::SpectrDevice(const SpectrDevice &&spectrDevice)
    : SpectrAbstract(std::move(spectrDevice))
{

}

SpectrDevice::SpectrDevice(QObject *parent)
    : SpectrDevice{ 0, DeviceStatus::FirstRequest, parent }
{

}

SpectrDevice::~SpectrDevice()
{
    qInfo() << "~SpectrDevice";
}

SpectrDevice &SpectrDevice::operator=(const SpectrDevice &spectrDevice)
{
    qInfo() << "anotherDevice id:" << spectrDevice.getId();
    if (this != &spectrDevice) {
        SpectrAbstract::operator=(spectrDevice);
    }
    return *this;
}

void SpectrDevice::initConnections()
{
    qInfo() << "SpectrDevice::initConnections";
}

void SpectrDevice::setStatus(const DeviceStatus status)
{
    qInfo() << "SpectrDevice::setStatus";

    switch(status)
    {
    case DeviceStatus::Pending:
    case DeviceStatus::PlayingAudio:
    case DeviceStatus::AccidentOccured:
    case DeviceStatus::FirstRequest:
    // slave only
    case DeviceStatus::ReceivingFile:
        SpectrAbstract::setStatus(status);
        break;
    default:
        emit errorOccured("Wrong device status!!!");
        break;
    }
}
