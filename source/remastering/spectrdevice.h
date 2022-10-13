#ifndef SPECTRDEVICE_H
#define SPECTRDEVICE_H

#include <QObject>

#include <QDir>
#include <QFile>
#include <QDebug>

class SpectrDevice : public QObject
{
    Q_OBJECT
public:
    explicit SpectrDevice(const int devId = 0, QObject *parent = nullptr);
    ~SpectrDevice();

    const int id() { return m_id; }

private:
    void initConnections();

signals:
    void errorOccured(const QString& str_error);

public slots:
    void setId(const int id);
    virtual void setStatus(DeviceStatuses status);

private slots:

private:

    int m_id;
    bool arr_inputs[8]{ 0, 0, 0, 0, 0, 0, 1, 0 }; // входы

    enum class DeviceStatuses{
        // общие статусы
        Pending = 0, PlayingAudio = 1, AccidentOccured = 3,
        FirstRequest = 14,
        // slave only
        ReceivingFile = 4,
        // master only
        DownloadingFile = 2, SpottingDifferences = 5, UploadingFile = 6,
        Verification = 7, Paused = 8, Sinchronization = 9
    } m_status;
};

#endif // SPECTRDEVICE_H
