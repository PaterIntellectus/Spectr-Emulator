#include "spectrabstract.h"

SpectrAbstract::SpectrAbstract(const int id, QObject *parent)
    : QObject{parent}
    , mArr_inputs{ 0, 0, 0, 0, 0, 0, 0, 0 }
{
    qInfo() << "SpectrAbstract construction...";

    setId(id);
    setStatus(DeviceStatus::FirstRequest);


    qInfo() << "/SpectrAbstract constructed";
}

const int SpectrAbstract::getInputsValInt()
{
    qInfo() << "SpectrDevice::getInputsValInt";

    // преобразование массива бинарников в int
    int val = 0;
    auto arrSize{ std::size(mArr_inputs) };
    for (size_t i = 0; i < arrSize; ++i) {
        val |= mArr_inputs[i] << (arrSize - i - 1);
    }
    return val;
}

void SpectrAbstract::setId(const int id)
{
    qInfo() << "SpectrDevice::setId";

    if (0 > id || id > 255) {
        emit errorOccured(QStringLiteral("Wrong device id:") + QString::number(id));
        return;
    }

    if (m_id != id) {
        m_id = id;
        qInfo() << "device id:" << getIdInt();
        emit idChanged(getIdInt());
    }
}

void SpectrAbstract::setStatus(const DeviceStatus status)
{
    qInfo() << "SpectrDevice::setStatus";

    if (m_statusCode != status) {
        m_statusCode = status;
        qInfo() << "device-status:" << getStatusInt();
        emit statusChanged(getStatusInt());
    }
}

void SpectrAbstract::toggleInput(const int inputNum)
{
    qInfo() << "SpectrDevice::toggleInput";

    if (0 < inputNum && inputNum < inputsMax) {
        mArr_inputs[inputNum] = !mArr_inputs[inputNum];
        emit inputValChanged(getInputsValInt());
    } else {
        emit errorOccured(QStringLiteral(
                              "Попытка получить доступ ко входу, за диапазоном\n"
                              "%1 << %2 << %3\n"
                              ).arg(0).arg(inputNum).arg(inputsMax)
                          );
    }
}

