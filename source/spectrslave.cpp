#include "spectrslave.h"

SpectrSlave::SpectrSlave(const int id, const DeviceStatus status, QObject *parent)
    : SpectrAbstract{ id, status, parent }
{
    qInfo() << "SpectrDevice construction...";

    initConnections();

    qInfo() << "/SpectrDevice constructed";
}

SpectrSlave::SpectrSlave(const SpectrSlave &spectrDevice)
    : SpectrSlave{ spectrDevice.getId(), spectrDevice.getStatus(), spectrDevice.parent() }
{}

SpectrSlave::SpectrSlave(const SpectrSlave &&spectrDevice)
    : SpectrAbstract(std::move(spectrDevice))
{}

SpectrSlave::SpectrSlave(QObject *parent)
    : SpectrSlave{ 0, DeviceStatus::FirstRequest, parent }
{}

SpectrSlave::~SpectrSlave()
{
    qInfo() << "~SpectrDevice";
}

SpectrSlave &SpectrSlave::operator=(const SpectrSlave &spectrDevice)
{
    qInfo() << "anotherDevice id:" << spectrDevice.getId();
    if (this != &spectrDevice) {
        SpectrAbstract::operator=(spectrDevice);
    }
    return *this;
}

void SpectrSlave::initConnections()
{
    qInfo() << "SpectrDevice::initConnections";
}

void SpectrSlave::setStatus(const DeviceStatus status)
{
    qInfo() << "SpectrDevice::setStatus";

    switch(status)
    {
    case DeviceStatus::Pending:
    case DeviceStatus::PlayingAudio:
    case DeviceStatus::AccidentOccurred:
    case DeviceStatus::FirstRequest:
    // slave only
    case DeviceStatus::ReceivingFile:
        SpectrAbstract::setStatus(status);
        break;
    default:
        emit errorMessage(tr("Не верный статус устройства!!!"));
        break;
    }
}
