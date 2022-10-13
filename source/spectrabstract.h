#ifndef SPECTRABSTRACT_H
#define SPECTRABSTRACT_H

#include <QObject>

#include <QDebug>

static const int inputsMax{ 8 };

class SpectrAbstract : public QObject
{
    Q_OBJECT
public:
    explicit SpectrAbstract(const int id, QObject *parent = nullptr);

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

private:
    virtual void initConnections() = 0;

signals:
    void errorOccured(const QString& str_error);
    void newMessage(const QString& message);

    void idChanged(const int id);
    void statusChanged(const int status);
    void inputValChanged(const int inputsVal);

public slots:
    const int getIdInt() { return m_id; }
    const int getStatusInt() { return static_cast<int>(m_statusCode); };
    const int getInputsValInt();

    virtual void setId(const int id);
    virtual void setStatus(const DeviceStatus status);
    virtual void toggleInput(const int inputNum);

private:
    int m_id;
    bool mArr_inputs[inputsMax]; // массив входов устройства
    DeviceStatus m_statusCode;
};

#endif // SPECTRABSTRACT_H
