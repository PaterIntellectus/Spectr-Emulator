#ifndef SPECTRABSTRACT_H
#define SPECTRABSTRACT_H

#include <QObject>

#include <QFile>
#include <QDir>
#include <QMediaPlayer>
#include <QAudioOutput>

#include <QDebug>

#include "trackmanager.h"

static const int inputsMax{ 8 };

class SpectrAbstract : public QObject
{
    Q_OBJECT
public:
    enum class DeviceStatus{
        // общие статусы
        Pending = 0, PlayingAudio = 1, AccidentOccured = 3,
        FirstRequest = 14,
        // slave only
        ReceivingFile = 4,
        // master only
        DownloadingFile = 2, SpottingDifferences = 5, UploadingFile = 6,
        Verification = 7, Paused = 8, Sinchronization = 9
    };

    SpectrAbstract(const int id, const DeviceStatus status, QObject *parent = nullptr);
    SpectrAbstract(const SpectrAbstract &spectrDevice);
    SpectrAbstract(const SpectrAbstract &&spectrDevice);
    explicit SpectrAbstract(QObject *parent = nullptr);

    const SpectrAbstract &operator=(const SpectrAbstract& anotherDevice);

    const int getId() const { return m_id; }
    const DeviceStatus getStatus() const { return m_statusCode; }
    const int getInputsValInt() const;

    const int getStatusInt() const { return static_cast<int>(m_statusCode); };

private:
    virtual void initConnections() = 0;

    unsigned int countCrc32(const QString &fileName);

signals:
    void errorMessage(const QString& str_error);
    void newMessage(const QString& message);

    void idChanged(const int id);
    void statusChanged(const int status);
    void inputValChanged(const int inputsVal);

private slots:

public slots:
    virtual void setId(const int id);
    virtual void setStatus(const DeviceStatus status);
    virtual void toggleInput(const int inputNum, bool onOff);

//    bool playTrack(const int fileNum, const int seconds, const int miliseconds);

protected:
    TrackManager *mTrackManager{ nullptr };

private:
    int m_id;
    DeviceStatus m_statusCode;
    bool mArr_inputs[inputsMax]; // массив входов устройства

};

#endif // SPECTRABSTRACT_H
