#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(const QString &connectionSettingsFilePath, const QString &masterSettingsFileName, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SettingsDialog)
    , mFile_connectionSettings{ connectionSettingsFilePath }
    , mFile_masterSettings{ masterSettingsFileName }
{
    qInfo() << "SettingsDialog construction...";

    ui->setupUi(this);

    initMainLayout();
    initConnections();

    setWindowTitle(tr("Настройки эмулятора"));
    // корректировка размера окна
    adjustSize();

    qInfo() << "/SettingsDialog constructed";
}

SettingsDialog::~SettingsDialog()
{
    qInfo() << "~SettingsDialog";
    delete ui;
}

// инициализация основого макета
void SettingsDialog::initMainLayout()
{
    qInfo() << "SettingsDialog::initMainLayout";

    // создание основного макета
    this->setLayout(new QVBoxLayout);

    createWidgets();
    // добавление сгенерированных виджетов
    this->layout()->addWidget(mGroupBox_master);
    this->layout()->addWidget(mGroupBox_server);
    this->layout()->addWidget(mButtonBox);
}

// инициализация виджетов окна
void SettingsDialog::createWidgets()
{
    qInfo() << "SettingsDialog::createWidgets";

    // создание групп
    createMasterGroupBox();
    createServerGroupBox();
    rejectSettings();

    // создание кнопок принятия и отмены
    mButtonBox = new QDialogButtonBox(this);
    mButtonBox->addButton(tr("Сохранить"), QDialogButtonBox::AcceptRole);
    mButtonBox->addButton(tr("Отмена"), QDialogButtonBox::RejectRole);
}

// создание группы настроек устройства
void SettingsDialog::createMasterGroupBox()
{
    qInfo() << "SettingsDialog::createMasterGroupBox";

    if (mGroupBox_master) { delete mGroupBox_master; }
    // создание группы
    mGroupBox_master = new QGroupBox(tr("Мастер"), this);

    // создание макета
    auto *layout{ new QFormLayout(mGroupBox_master) };

    mLabel_masterId = new QLabel(tr("id:"), mGroupBox_master);
    mLineEdit_masterId = new QLineEdit(mGroupBox_master);
    mLineEdit_masterId->setMaxLength(5);

    layout->addRow(mLabel_masterId, mLineEdit_masterId);
}

// создание группы настроек сервера
void SettingsDialog::createServerGroupBox()
{
    qInfo() << "SettingsDialog::createServerGroupBox";

    if (mGroupBox_master) { delete mGroupBox_server; }
    // создание группы
    mGroupBox_server = new QGroupBox(tr("Сервер"), this);

    // создание макета
    auto *layout{ new QFormLayout(mGroupBox_server) };

    // заполнение макета
    mLabel_serverAddress = new QLabel(tr("Адрес:"), mGroupBox_server);
    mLineEdit_serverAddress = new QLineEdit(mGroupBox_server);
    layout->addRow(mLabel_serverAddress, mLineEdit_serverAddress);

    mLabel_serverPort = new QLabel(tr("Порт:"), mGroupBox_server);
    mLineEdit_serverPort = new QLineEdit(mGroupBox_server);
    layout->addRow(mLabel_serverPort, mLineEdit_serverPort);
}

// связываение сигналов и слотов
void SettingsDialog::initConnections()
{
    qInfo() << "SettingsDialog::initConnections";

    // действие кнопки принятия
    connect(mButtonBox, &QDialogButtonBox::accepted, this, &SettingsDialog::accept);
    // действие кнопки отмены
    connect(mButtonBox, &QDialogButtonBox::rejected, this, &SettingsDialog::reject);
}

// принятие натсроек
void SettingsDialog::accept()
{
    qInfo() << "SettingsDialog::accept";
    acceptSettings();
    this->hide();
}

// отмена настроек
void SettingsDialog::reject()
{
    qInfo() << "SettingsDialog::reject";
    rejectSettings();
    this->hide();
}

// сохранение настроек в файл
void SettingsDialog::acceptSettings()
{
    qInfo() << "SettingsDialog::acceptSettings";

    auto newDeviceId{ mLineEdit_masterId->text().trimmed() };
    auto newServerAddress{ mLineEdit_serverAddress->text().trimmed() };
    auto newServerPort{ mLineEdit_serverPort->text().trimmed() };

    if (m_settings.serverAddress != newServerAddress || m_settings.serverPort != newServerPort) {
        m_settings.serverAddress = newServerAddress;
        m_settings.serverPort = newServerPort;

        mFile_connectionSettings.open(QIODevice::WriteOnly);
        QTextStream stream{ &mFile_connectionSettings };
        stream << m_settings.serverAddress << '\n' << m_settings.serverPort;
        mFile_connectionSettings.close();

        emit connectionSettingsChanged();
    }

    if (m_settings.masterId != newDeviceId) {
        m_settings.masterId = newDeviceId;

        mFile_masterSettings.open(QIODevice::WriteOnly);
        QTextStream stream{ &mFile_masterSettings };
        stream << m_settings.masterId;
        mFile_connectionSettings.close();

        emit masterSettingsChanged(m_settings.masterId.toInt());
    }
}

// заполнение полей ввода из файла
void SettingsDialog::rejectSettings()
{
    qInfo() << "SettingsDialog::rejectSettings";

    QTextStream stream;

    mFile_connectionSettings.open(QIODevice::ReadOnly);
    stream.setDevice(&mFile_connectionSettings);
    stream >> m_settings.serverAddress >> m_settings.serverPort;
    mFile_connectionSettings.close();

    mFile_masterSettings.open(QIODevice::ReadOnly);
    stream.setDevice(&mFile_masterSettings);
    stream >> m_settings.masterId;
    mFile_masterSettings.close();

    // обновление полей ввода
    mLineEdit_masterId->setText(m_settings.masterId);
    mLineEdit_serverAddress->setText(m_settings.serverAddress);
    mLineEdit_serverPort->setText(m_settings.serverPort);
}