#include "command.h"

Command::Command(QObject *parent)
    : QObject{parent}
{
    setStatus(CommandStatuses::NoCommand);
    setErrorCode(ErrorCode::NoError);
    setId(0);
}

void Command::setId(const int id) {
    if (m_id != id) {
        m_id = id;
        emit idChanged(getIdInt());
    }
}

void Command::setStatus(const CommandStatuses status)
{
    if (m_statusCode != status) {
        m_statusCode = status;
        emit statusChanged(getStatusCodeInt());
    }
}

void Command::setErrorCode(const ErrorCode errorCode)
{
    if (m_errorCode != errorCode) {
        m_errorCode = errorCode;
        emit errorCodeChanged(getErrorCodeInt());
    }
}
