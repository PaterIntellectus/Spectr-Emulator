#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QGroupBox>
#include <QFormLayout>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>

#include <QFile>

static const QString settingsFolder{ "settings/" };
static const QString connectionSettingsPath{ settingsFolder + "connectionSettings.txt" };
static const QString masterSettingsPath{ settingsFolder + "masterSettings.txt" };

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

    const int masterId() { return mSettings.masterId.toInt(); }
    const auto connectionSettings() {
        return QPair<QString, quint16>(mSettings.serverHost, mSettings.serverPort.toShort());
    }

signals:
    void masterSettingsChanged(const int newId);
    void connectionSettingsChanged(const QPair<QString, quint16> pair_hostPort);

private slots:
    // принятие / отмена изменений
    void accept();
    void reject();

    // сохранение настроек
    void acceptSettings();

    // обновление полей ввода по данным из файла
    void rejectSettings();

private:
    // инициализация внешнего вида окна
    void initMainLayout();
    void createWidgets();
    // создание групп настроек
    void createMasterGroupBox();
    void createServerGroupBox();
    // связываение сигналов и слотов
    void initConnections();

    Ui::SettingsDialog *ui{ nullptr };

    // настройки
    QFile mFile_connectionSettings;
    QFile mFile_masterSettings;
    struct Settings {
        QString masterId;
        QString serverHost;
        QString serverPort;
    } mSettings;

    // группы настроек
    QGroupBox *mGroupBox_master{ nullptr };
    QGroupBox *mGroupBox_server{ nullptr };

    // поля настроек устройства
    QLabel *mLabel_masterId{ nullptr };
    QLineEdit *mLineEdit_masterId{ nullptr };

    // поля настроек сервера
    QLabel *mLabel_serverAddress{ nullptr };
    QLineEdit *mLineEdit_serverAddress{ nullptr };
    QLabel *mLabel_serverPort{ nullptr };
    QLineEdit *mLineEdit_serverPort{ nullptr };

    // блок с кнопками
    QDialogButtonBox *mButtonBox{ nullptr };
};

#endif // SETTINGSDIALOG_H
