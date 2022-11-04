#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>
#include <QUrlQuery>

#include <QRegularExpression>

using Arguments = QList<int>;


class Command : public QObject
{
    Q_OBJECT
public:

    // errorProne construcor!!!
    Command(int id, QStringView name, Arguments argv, QObject *parent = nullptr);
    explicit Command(const QString &cmdData, QObject* parent = nullptr);
    explicit Command(QObject *parent = nullptr);

    enum class Type {
        NoType = 0,
        SetRele = 1, CrlRele = 2, SetGroupRele = 3,
        GetFile = 4, Play = 5, Quiet = 6,
        Stop = 7
    };
    enum class Status {
        NoCommand = 0,
        Completed = 3, ErrorOccured = 4,
        WrongSyntax = 5, UploadingFile = 6
    };
    enum class Error {
        NoError = 0,
        WrongParameter = 1, UnknownCommand = 2,
        SDCardError = 3, CannotOpenAudioFile = 4,
        CannotCopyFile = 5, CannotOpenTemporaryFile = 6,
        CannotSyncronyze = 7, CannotMoveFilePointer = 8,
        CannotCreateConenctionObject = 9,
        CannotConnect = 10, ConnectionTimeout = 11,
        FileWriteError = 12, FileNotAvailableToDownload = 13,
        WrongSlaveAddress = 14, SlaveDataTimeout = 15
    };


    const int getId() const { return m_id; }
    const QString getName() const { return m_name; }
    const Arguments getArguments() const { return m_arguments; }
//    const int getType() const { return static_cast<int>(m_type); }
    const int getStatusCode() const { return static_cast<int>(m_status); }
    const int getErrorCode() const { return static_cast<int>(m_errorCode); }

    const QString getIdStr() const { return QString::number(getId());}
    const QString getStatusCodeStr() const { return QString::number(getStatusCode()); }
    const QString getErrorCodeStr() const { return QString::number(getErrorCode()); }

signals:
    void idChanged(int) const;
    void nameChanged(QStringView) const;
//    void typeChanged(QStringView) const;
    void statusChanged(int) const;
    void errorCodeChanged(int) const;

    void errorMessage(const QString&) const;

public slots:

    void setId(const int id);
    void setName(QStringView name);
    void setStatus(const Command::Status status);
    void setErrorCode(const Command::Error errorCode);

//    void setType(const Type &type);
//    void setType(const QString &type);

    void setArguments(const Arguments &argv);
    void setArguments(QStringView argv, const QString &delimeter = ",");

private:
    int m_id;
    QString m_name;
//    Type m_type;
    Arguments m_arguments;

    Status m_status;
    Error m_errorCode;
};

#endif // COMMAND_H
