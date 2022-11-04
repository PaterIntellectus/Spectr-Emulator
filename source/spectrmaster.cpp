#include "spectrmaster.h"

SpectrMaster::SpectrMaster(const int id, const DeviceStatus status, QObject *parent)
    : SpectrAbstract{ id, status, parent }
    , m_cmd{ new Command(this) }
    , mFile_slaves{ slaveListFileName }
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

}

void SpectrMaster::initConnections()
{
    qInfo() << "SpectrMaster::initConnections";

    connect(this, &SpectrMaster::cmdReceived, m_cmd, &Command::setId);

}

void SpectrMaster::setStatus(const DeviceStatus status)
{
    qInfo() << "SpectrMaster::setStatus";

    switch(status)
    {
    case DeviceStatus::Pending:
    case DeviceStatus::PlayingAudio:
    case DeviceStatus::AccidentOccurred:
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
        errorMessage(tr("Не верный статус мастера!!!"));
        break;
    }
}

void SpectrMaster::initSlaveList(QList<int> list_slaveId)
{
    qInfo() << "SpectrMaster::initSlaveList";

    // removing extra slaves
    for (const auto &slave : mList_slaves) {
        if (list_slaveId.contains(slave.getId())) {
            continue;
        }
        removeSlave(slave.getId());
    }
    // adding slaves
    for (const auto slaveId : list_slaveId) {
        addSlave(slaveId);
    }
}

void SpectrMaster::addSlave(const int id, const DeviceStatus status)
{
    qInfo() << "SpectrMaster::addSlave";

    if (findSlave(id).has_value()) {
        emit newMessage(tr("Устройство #%1 уже является slave устройством").arg(id));
        return;
    }
//    mList_slaves.append(SpectrSlave(id, status, this));
    emit newMessage(tr("Добавлено уcтройство #%1").arg(id));
}

void SpectrMaster::removeSlave(const int id)
{
    qInfo() << "SpectrMaster::removeSlave";

    auto opt_slave{ findSlave(id) };

    if (!opt_slave.has_value()) {
        emit errorMessage(tr("Невозможно удалить не подключенное slave устройство"));
        return;
    }
    mList_slaves.removeOne(opt_slave.value());
    mList_slaves.squeeze();
    emit newMessage(tr("Устройство #%2(%1) удалено")
                    .arg(opt_slave->getName().size() ? opt_slave->getName() : QStringLiteral("no name"))
                    .arg(opt_slave->getId())
                    );
}

const std::optional<SpectrSlave> SpectrMaster::findSlave(const int id) const
{
    qInfo() << "SpectrMaster::findSlave";

    for (const auto &slave : mList_slaves) {
        if (slave.getId() == id) {
            return std::optional<const SpectrSlave>(std::in_place, slave);
        }
    }
    emit newMessage(tr("Устройство #%1 не найдено").arg(id));
    return std::nullopt;
}
