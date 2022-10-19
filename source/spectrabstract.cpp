#include "spectrabstract.h"

SpectrAbstract::SpectrAbstract(const int id, const DeviceStatus status, QObject *parent)
    : QObject{ parent }
    , mMediaPlayer{ new QMediaPlayer(this) }
    , mAudioOutput{ new QAudioOutput(mMediaPlayer) }
{
    qInfo() << "SpectrAbstract construction...";

    setId(id);
    setStatus(status);
    for (int i{}; i < sizeof(mArr_inputs); ++i) {
        mArr_inputs[i] = false;
    }

    mMediaPlayer->setAudioOutput(mAudioOutput);
    mAudioOutput->setVolume(50);

    // создание директории с треками
    QDir::current().mkdir(tracksDir);

    qInfo() << "/SpectrAbstract constructed";
}

SpectrAbstract::SpectrAbstract(const SpectrAbstract &spectrObject)
    : SpectrAbstract{ spectrObject.getId(), spectrObject.getStatus(), spectrObject.parent() }
{}

SpectrAbstract::SpectrAbstract(const SpectrAbstract &&spectrDevice)
{
    qInfo() << "SpectrAbstract moving...";

    m_id = std::move(spectrDevice.m_id);
    m_statusCode = std::move(spectrDevice.m_statusCode);
    for (int i{}; i < sizeof(mArr_inputs); ++i) {
        mArr_inputs[i] = spectrDevice.mArr_inputs[i];
    }
    setParent(spectrDevice.parent());

    qInfo() << "/SpectrAbstract moved";
}

SpectrAbstract::SpectrAbstract(QObject *parent)
    : SpectrAbstract{ 0, DeviceStatus::FirstRequest, parent }
{}

const SpectrAbstract &SpectrAbstract::operator=(const SpectrAbstract &anotherDevice)
{
    if (this != &anotherDevice) {
        setId(anotherDevice.getId());
        qInfo() << getId();
        setStatus(anotherDevice.getStatus());
        for (int i{}; i < sizeof(mArr_inputs); ++i) { mArr_inputs[i] = anotherDevice.mArr_inputs[i]; }
    }
    return *this;
}

const int SpectrAbstract::getInputsValInt() const
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
    qInfo() << "SpectrAbstract::setId";

    if (id < 0 || 255 < id) {
        emit errorOccured(tr("Не верное id устройства:") + QString::number(id));
        return;
    }

    if (m_id != id) {
        m_id = id;
//        qInfo() << "device id:" << getId();
        emit idChanged(getId());
    }
}

void SpectrAbstract::setStatus(const DeviceStatus status)
{
    qInfo() << "SpectrDevice::setStatus";

    if (m_statusCode != status) {
        m_statusCode = status;
//        qInfo() << "device-status:" << getStatusInt();
        emit statusChanged(getStatusInt());
    }
}

void SpectrAbstract::toggleInput(const int inputNum, bool onOff)
{
    qInfo() << "SpectrAbstract::toggleInput";

    if (0 <= inputNum && inputNum < inputsMax) {
        if (mArr_inputs[inputNum] != onOff) {
            mArr_inputs[inputNum] = onOff;
            emit inputValChanged(getInputsValInt());
            emit newMessage(QStringLiteral("Вход под номером '%1' был переключен в состояние '%2'")
                            .arg(inputNum).arg(onOff ? "Включено" : "Выключено"));
        } else {
            emit newMessage(QStringLiteral("Вход под номером '%1' уже находится в состоянии '%2'")
                            .arg(inputNum).arg(onOff ? "Включено" : "Выключено"));
        }
    } else {
        emit errorOccured(tr(
                              "Попытка получить доступ ко входу, за диапазоном\n"
                              "%1 << %2 << %3\n"
                              ).arg(0).arg(inputNum).arg(inputsMax)
                          );
    }
}

bool SpectrAbstract::playAudioFile(const int fileNum, const int seconds, const int miliseconds)
{
    qInfo() << "SpectrAbstractr::playFile";

    const QFile audio{ tracksDir + getTrackName(fileNum) };
    qInfo() << audio.fileName();

    if (!audio.exists()) {
        emit errorOccured(tr("Не найден файл для воспроизведения!"));
        return false;
    }
    mMediaPlayer->setSource(audio.fileName());
    mMediaPlayer->play();

    emit newMessage(tr("Проигрывается трек: '%1'").arg(getTrackName(fileNum)));
    return true;
}
