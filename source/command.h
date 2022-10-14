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

    const int getIdInt() { return m_id; }
    const int getStatusCodeInt() { return static_cast<int>(m_statusCode); }
    const int getErrorCodeInt() { return m_errorCode; }

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
    void setErrorCode(const int errorCode);

private:
    int m_id;
//    QString m_name;
    CommandStatuses m_statusCode;
    int m_errorCode;
};

#endif // COMMAND_H
