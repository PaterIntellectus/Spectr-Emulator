#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>

class Command : public QObject
{
    Q_OBJECT
public:
    explicit Command(QObject *parent = nullptr);

    enum class CommandStatuses {
        NoCommand = 0,
        Completed = 3, ErrorOccured = 4,
        WrongSyntax = 5, UploadingFile = 6
    };
    enum class ErrorCode {
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

    const int getIdInt() { return m_id; }
    const int getStatusCodeInt() { return static_cast<int>(m_statusCode); }
    const int getErrorCodeInt() { return static_cast<int>(m_errorCode); }

    const QString getIdStr() { return QString::number(getIdInt());}
    const QString getStatusCodeStr() { return QString::number(getStatusCodeInt()); }
    const QString getErrorCodeStr() { return QString::number(getErrorCodeInt()); }

signals:
    void idChanged(int id);
    void statusChanged(int status);
    void errorCodeChanged(int errorCode);

    void errorOccured(const QString& error);

public slots:

    void setId(const int id);
    void setStatus(const CommandStatuses status);
    void setErrorCode(const ErrorCode errorCode);

private:
//    QString m_name;
    int m_id;
    CommandStatuses m_statusCode;
    ErrorCode m_errorCode;
};

#endif // COMMAND_H
