#ifndef SPECTRABSTRACT_H
#define SPECTRABSTRACT_H

#include <QObject>

#include <QFile>
#include <QDir>
#include <QMediaPlayer>
#include <QAudioOutput>

#include <QDebug>

#include "trackmanager.h"

static const int relaysMin{};
static const int relaysMax{ 8 };

class SpectrAbstract : public QObject
{
    Q_OBJECT
public:
    enum class DeviceStatus{
        // общие статусы
        Pending = 0, PlayingAudio = 1, AccidentOccurred = 3,
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

    ~SpectrAbstract() = 0;

    const SpectrAbstract &operator=(const SpectrAbstract& anotherDevice);

    const auto& getName() const { return m_name; }
    const auto getId() const { return m_id; }
    const auto getStatus() const { return m_status; }
    const int getRelaysVal() const;

    const int statusInt() const { return static_cast<int>(m_status); };

    friend bool operator==(const SpectrAbstract& left, const SpectrAbstract& right) {
        return left.getId() == right.getId();
    }

private:
    void initConnections();

signals:
    void errorMessage(QStringView str_error) const;
    void newMessage(QStringView message) const;

    void idChanged(const int id) const;
    void statusChanged(const int status) const;
    void relayValChanged(const int inputsVal) const;

private slots:

public slots:
    virtual void setId(const int id);
    virtual void setStatus(const DeviceStatus status);
    bool toggleRelay(const int relayNum, bool onOff);

protected:
    TrackManager *m_trackManager{ nullptr };

private:
    QString m_name;
    int m_id;
    DeviceStatus m_status;
    bool mArr_relays[relaysMax]; // массив входов устройства

};

#endif // SPECTRABSTRACT_H
