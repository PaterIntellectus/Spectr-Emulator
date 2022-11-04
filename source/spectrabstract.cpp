#include "spectrabstract.h"

SpectrAbstract::SpectrAbstract(const int id, const DeviceStatus status, QObject *parent)
    : QObject{ parent }
    , m_trackManager{ new TrackManager(this) }
{
    qInfo() << "SpectrAbstract construction...";

    setId(id);
    setStatus(status);
    for (int i{}; i < sizeof(mArr_relays); ++i) {
        mArr_relays[i] = false;
    }
    initConnections();

    qInfo() << "/SpectrAbstract constructed";
}

SpectrAbstract::SpectrAbstract(const SpectrAbstract &spectrObject)
    : SpectrAbstract{ spectrObject.getId(), spectrObject.getStatus(), spectrObject.parent() }
{}

SpectrAbstract::SpectrAbstract(const SpectrAbstract &&spectrDevice)
{
    qInfo() << "SpectrAbstract moving...";

    m_id = std::move(spectrDevice.m_id);
    m_status = std::move(spectrDevice.m_status);
    for (int i{}; i < sizeof(mArr_relays); ++i) {
        mArr_relays[i] = std::move(spectrDevice.mArr_relays[i]);
    }
    setParent(std::move(spectrDevice.parent()));

    initConnections();

    qInfo() << "/SpectrAbstract moved";
}

SpectrAbstract::SpectrAbstract(QObject *parent)
    : SpectrAbstract{ 0, DeviceStatus::FirstRequest, parent }
{}

SpectrAbstract::~SpectrAbstract()
{
}

const SpectrAbstract &SpectrAbstract::operator=(const SpectrAbstract &anotherDevice)
{
    qInfo() << "SpectrAbstract::operator=";

    if (this != &anotherDevice) {
        setId(anotherDevice.getId());
        qInfo() << getId();
        setStatus(anotherDevice.getStatus());
        for (int i{}; i < sizeof(mArr_relays); ++i) { mArr_relays[i] = anotherDevice.mArr_relays[i]; }
    }
    return *this;
}

const int SpectrAbstract::getRelaysVal() const
{
    qInfo() << "SpectrAbstract::inputsVal";

    // преобразование массива бинарников в int
    int val = 0;
    auto arrSize{ std::size(mArr_relays) };
    for (size_t i = 0; i < arrSize; ++i) {
        val |= mArr_relays[i] << (arrSize - i - 1);
    }
    return val;
}

void SpectrAbstract::initConnections()
{
    qInfo() << "SpectrAbstract::initConnections";

    connect(m_trackManager, &TrackManager::newMessage, this, &SpectrAbstract::newMessage);
    connect(m_trackManager, &TrackManager::errorMessage, this, &SpectrAbstract::errorMessage);
}

void SpectrAbstract::setId(const int newId)
{
    qInfo() << "SpectrAbstract::setId";

    if (m_id != newId) {
        m_id = newId;
        emit idChanged(getId());
    }
}

void SpectrAbstract::setStatus(const DeviceStatus newStatus)
{
    qInfo() << "SpectrAbstract::setStatus";

    if (m_status != newStatus) {
        m_status = newStatus;
        emit statusChanged(statusInt());
    }
}

bool SpectrAbstract::toggleRelay(const int relayNum, bool onOff)
{
    qInfo() << "SpectrAbstract::toggleRelay";

    if (relayNum < relaysMin && relaysMax < relayNum) {
        emit errorMessage(tr(
                              "Попытка получить доступ ко входу, за диапазоном\n"
                              "%1 << %2 << %3\n"
                              ).arg(relaysMin).arg(relayNum).arg(relaysMax));
        return false;
    }

    QString str_onOff = { onOff ? "Включено" : "Выключено" };

    if (mArr_relays[relayNum] == onOff) {
        emit newMessage(tr(
                            "Вход под номером '%1' уже находится в состоянии '%2'"
                            ).arg(relayNum).arg(str_onOff));
        return true;
    }

    mArr_relays[relayNum] = onOff;
    emit relayValChanged(getRelaysVal());
    emit newMessage(tr(
                        "Вход под номером '%1' был переключен в состояние '%2'"
                        ).arg(relayNum).arg(str_onOff));
    return true;
}
