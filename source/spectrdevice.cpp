#include "spectrdevice.h"

SpectrDevice::SpectrDevice(const int id, QObject *parent)
    : SpectrAbstract{ id, parent }
{
    qInfo() << "SpectrDevice construction...";

    initConnections();

    qInfo() << "/SpectrDevice constructed";
}

SpectrDevice::~SpectrDevice()
{
    qInfo() << "~SpectrDevice";
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
