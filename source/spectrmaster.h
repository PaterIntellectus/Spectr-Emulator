#ifndef SPECTRMASTER_H
#define SPECTRMASTER_H

#include "spectrabstract.h"
#include <QObject>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QUrl>

#include <QTimer>

#include "spectrnetworkmanager.h"
#include "spectrslave.h"
#include "command.h"

static const QString slaveListFileName{ "slist.txt" };
using SlaveList = QList<SpectrSlave>;


class SpectrMaster : public SpectrAbstract
{
    Q_OBJECT
public:
    SpectrMaster(const int id, const DeviceStatus status = DeviceStatus::FirstRequest, QObject *parent = nullptr);
    SpectrMaster(const SpectrMaster &spectrMaster);
    explicit SpectrMaster(QObject *parent = nullptr);

    ~SpectrMaster();

private:
    virtual void initConnections();

signals:
    void cmdReceived(const int id);

public slots:
    virtual void setStatus(const DeviceStatus status);

    // slaves
    void initSlaveList(QList<int> list_slaveId);

    void addSlave(const int id, const DeviceStatus status = DeviceStatus::FirstRequest);
    void removeSlave(const int id);

    const std::optional<SpectrSlave> findSlave(const int id) const;
    const int countSlaves() { return mList_slaves.count(); }

//    void saveSlaveList();
    // ==========

private slots:

protected:
    // параметры получаемой команды
    Command *m_cmd{ nullptr };

private:
    QFile mFile_slaves;
    SlaveList mList_slaves;
};

#endif // SPECTRMASTER_H
