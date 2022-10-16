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

    qInfo() << "/SpectrAbstract constructed";
}

SpectrAbstract::SpectrAbstract(const SpectrAbstract &spectrObject)
    : SpectrAbstract{ spectrObject.getId(), spectrObject.getStatus(), spectrObject.parent() }
{}

SpectrAbstract::SpectrAbstract(QObject *parent)
    : SpectrAbstract{ 0, DeviceStatus::FirstRequest, parent }
{}

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
    qInfo() << "SpectrDevice::setId";

    if (0 > id || id > 255) {
        emit errorOccured(tr("Не верное id устройства:") + QString::number(id));
        return;
    }

    if (m_id != id) {
        m_id = id;
        qInfo() << "device id:" << getId();
        emit idChanged(getId());
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
        emit errorOccured(tr(
                              "Попытка получить доступ ко входу, за диапазоном\n"
                              "%1 << %2 << %3\n"
                              ).arg(0).arg(inputNum).arg(inputsMax)
                          );
    }
}

bool SpectrAbstract::playFile(const QString &fileNum, QStringView seconds, QStringView miliseconds)
{
    qInfo() << "SpectrAbstractr::playFile";

    QFile audio{ "audio/track" + fileNum.rightJustified(2, '0') + ".mp3" };
    qInfo() << audio.fileName();

    if (!audio.exists()) {
        emit errorOccured(tr("Не найден файл для воспроизведения!"));
        return false;
    }
    mMediaPlayer->setAudioOutput(mAudioOutput);
    mAudioOutput->setVolume(50);

    mMediaPlayer->setSource(audio.fileName());
    mMediaPlayer->play();

    emit newMessage(tr("Проигрывается трек 'track %1'").arg(fileNum.rightJustified(2, '0') + ".mp3"));

    return true;
}
