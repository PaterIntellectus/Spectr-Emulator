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

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(
            const QString &connectionSettingsFileName,
            const QString &masterSettingsFileName,
            QWidget *parent = nullptr
            );
    ~SettingsDialog();

    const int masterId() { return m_settings.masterId.toInt(); }

signals:
    void masterSettingsChanged(const int newId);
    void connectionSettingsChanged();

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
        QString serverAddress;
        QString serverPort;
    } m_settings;

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
