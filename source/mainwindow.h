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
#include "spectremulator.h"


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
    void initLogGroupBox();

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
    QComboBox *mComboBox_requestNames{ nullptr };
    QStackedWidget *mStackedWidget_requestParameters{ nullptr };
    QPushButton *mPushButton_sendRequest{ nullptr };
    QPushButton *mPushButton_emulationSwitcher{ nullptr };

    QList<QList<PairLabelLineedit>> mListListPair_requestRows;

    QGroupBox *mGroupBox_log{ nullptr };
    QTextBrowser *mTextBrowser_log{ nullptr };

    QAction *mAction_openSettings{ nullptr };

    SettingsDialog *m_settingsDialog{ nullptr };
    // ===

    SpectrEmulator *m_emulator{ nullptr };

    QFile mFile_requestNames;
    QList<QString> mList_requestNames;

    QFile mFile_requestQueries;
    QList<QUrlQuery> mList_requestQueries;

};
#endif // MAINWINDOW_H
