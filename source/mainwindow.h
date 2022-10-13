#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QTextEdit>
#include <QTextBrowser>
#include <QComboBox>
#include <QStackedWidget>

#include <QVBoxLayout>
#include <QGridLayout>

#include <QIcon>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>

#include <QFile>
#include <QDir>

#include "settingsdialog.h"
#include "spectrmaster.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using PairLabelLineedit = QPair<QLabel *, QLineEdit *>;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(
            const QString &connectionSettingsFilePath,
            const QString &masterSettingsFilePath,
            const QString &requestsNamesFilePath,
            const QString &requestsQueriesFilePath,
            QWidget *parent = nullptr
            );
    ~MainWindow();

private:
    // UI initialization ===
    void initMenuWidget();
    void initCentralWidget();
    void initRequestGroupBox();

    void initReplyGroupBox();
    void initRequestComboBox();
    void initRequestStackedWidget();

    void initRequestButtons();
    // ===
    void initConnections();

    void updateRequestNamesList();
    void updateQueriesList();
    void updateQueriesFile();



signals:
//    void queryPrepared();

public slots:

private slots:
    const QUrlQuery createQuery();

//    void processCommand(const QMap<QString, QString> &map_cmdData);

    void logWriteLine(const QString& line);


private:
    // UI objects ===
    Ui::MainWindow *ui{ nullptr };

    QGroupBox *mGroupBox_request{ nullptr };
    QComboBox *comboBox_requestNames{ nullptr };
    QStackedWidget *stackedWidget_requestParameters{ nullptr };
    QPushButton *pushButton_sendRequest{ nullptr };
    QPushButton *pushButton_emulationSwitcher{ nullptr };

    QList<QList<PairLabelLineedit>> listListPair_requestRows;

    QGroupBox *groupBox_reply{ nullptr };
    QTextBrowser *textBrowser_log{ nullptr };

    QAction *mAction_openSettings{ nullptr };

    SettingsDialog *m_settingsDialog{ nullptr };
    // ===

    SpectrMaster *m_master{ nullptr };

    QFile mFile_requestNames;
    QList<QString> mList_requestNames;

    QFile mFile_requestQueries;
    QList<QUrlQuery> mList_requestQueries;

};
#endif // MAINWINDOW_H
