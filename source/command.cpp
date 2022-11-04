#include "command.h"

Command::Command(const QString &cmdData, QObject* parent)
    : QObject{ parent }
{
    qInfo() << "Command construction...";

    if (cmdData.isEmpty()) {
        emit errorMessage(tr("Передана пустая строка в качестве аргумента для конструктора Command"));
        return;
    }
    auto list_cmdData{ cmdData.split(QRegularExpression("( |;)"), Qt::SkipEmptyParts) };

    setId(list_cmdData.at(0).sliced(list_cmdData.at(0).indexOf('=') + 1).toInt());

    if (const auto delIndex{ list_cmdData.at(1).indexOf('=') }; 0 <= delIndex) {
        setName(list_cmdData.at(1).first(delIndex));
        setArguments(list_cmdData.at(1).sliced(delIndex + 1), list_cmdData.at(1).contains(',') ? "" : "");
        qInfo() << getArguments();
    } else {
        setName(list_cmdData.at(1));
    }
    qInfo() << "/Command constructed";
}

Command::Command(QObject *parent)
    : QObject{ parent }
{
    setStatus(Status::NoCommand);
    setErrorCode(Error::NoError);
    setId(0);
}

void Command::setId(const int id)
{
    qInfo() << "Command::setId";

    if (id == m_id) { return; }
    m_id = id;
    emit idChanged(getId());
}

void Command::setName(QStringView name)
{
    qInfo() << "Command::setName";

    if (name == m_name) { return; }
    m_name = std::move(name.toString());
    emit nameChanged(getName());
}

void Command::setStatus(const Command::Status status)
{
    qInfo() << "Command::setStatus";

    if (status == m_status) { return; }
    m_status = status;
    emit statusChanged(getStatusCode());
}

void Command::setErrorCode(const Command::Error errorCode)
{
    qInfo() << "Command::setErrorCode";

    if (m_errorCode == errorCode) { return; }
    m_errorCode = errorCode;
    emit errorCodeChanged(getErrorCode());
}

void Command::setArguments(const Arguments &argv)
{
    qInfo() << "Command::setArguments";

    m_arguments = argv;
}

void Command::setArguments(QStringView strv_argv, const QString &delimeter)
{
    qInfo() << "Command::setArguments";

    qInfo() << strv_argv;

    m_arguments.clear();
    for (auto argv : strv_argv) {
        m_arguments.append(argv.digitValue());
    }
}

//void Command::setType(const Type &type)
//{
//    if (type == m_type) { return; }
//    m_type = type;
//}

//void Command::setType(const QString &type)
//{
//    if (type == "SetRele") {
//        setType(Type::SetRele);
//    } else if (type == "") {
//        setType(Type::CrlRele);
//    } else if (type == "outall") {
//        setType(Type::SetGroupRele);
//    } else if (type == "getfile") {
//        setType(Type::GetFile);
//    } else if (type == "play") {
//        setType(Type::Play);
//    } else if (type == "quiet") {
//        setType(Type::Quiet);
//    } else if (type == "stop")

//}

