#include "spectrmaster.h"

SpectrMaster::SpectrMaster(const int id, const DeviceStatus status, QObject *parent)
    : SpectrAbstract{ id, status, parent }
    , m_cmd{ new Command(this) }
{
    qInfo() << "SpectrMaster construction...";

    initConnections();

    qInfo() << "/SpectrMaster constructed";
}

SpectrMaster::SpectrMaster(const SpectrMaster &spectrObject)
    : SpectrMaster{ spectrObject.getId(), spectrObject.getStatus(), spectrObject.parent() }
{}

SpectrMaster::SpectrMaster(QObject *parent)
    : SpectrMaster{ 0, DeviceStatus::FirstRequest, parent }
{}

SpectrMaster::~SpectrMaster()
{
    qInfo() << "~SpectrMaster";

    if (!mList_slaves.empty()){
        for (auto &slave : mList_slaves) { delete slave; }
    }
}

void SpectrMaster::initConnections()
{
    qInfo() << "SpectrMaster::initConnections";
}

void SpectrMaster::setStatus(const DeviceStatus status)
{
    qInfo() << "SpectrMaster::setStatus";

    switch(status)
    {
    case DeviceStatus::Pending:
    case DeviceStatus::PlayingAudio:
    case DeviceStatus::AccidentOccured:
    case DeviceStatus::FirstRequest:
    // master only
    case DeviceStatus::DownloadingFile:
    case DeviceStatus::SpottingDifferences:
    case DeviceStatus::UploadingFile:
    case DeviceStatus::Verification:
    case DeviceStatus::Paused:
    case DeviceStatus::Sinchronization:
        SpectrAbstract::setStatus(status);
        break;
    default:
        errorOccured(tr("Не верный статус мастера!!!"));
        break;
    }
}

const QList<int> SpectrMaster::getSlaveIdList()
{
    QList<int> list_slaveId;
    for (const auto &slave : mList_slaves) {
        list_slaveId.append(slave->getId());
    }
    return list_slaveId;
}
