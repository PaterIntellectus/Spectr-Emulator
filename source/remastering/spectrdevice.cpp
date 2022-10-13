#include "spectrdevice.h"

SpectrDevice::SpectrDevice(const int devId, QObject *parent)
    : QObject{ parent }
    , m_status{ DeviceStatuses::FirstRequest }
{
    qInfo() << "SpectrDevice construction...";

    initConnections();

    setId(devId);

//    // преобразование массива бинарников в int
//    int val = 0;
//    for (int i = 0; i < std::size(arr_inputs); i++) {
//        val |= arr_inputs[i] << (std::size(arr_inputs) - i - 1);
//    }
//    qInfo() << val;

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

void SpectrDevice::setId(const int id)
{
    qInfo() << "SpectrDevice::setId";
    if (0 < id) {
        m_id = id;
        qInfo() << "device id:" << m_id;
    } else {
        emit errorOccured(QStringLiteral("Wrong device id:") + QString::number(id));
    }
}

void SpectrDevice::setStatus(DeviceStatuses status)
{
    switch (status)
    {
    case 0:
    }
}

