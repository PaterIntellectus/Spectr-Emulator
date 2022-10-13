#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(
        const QString &connectionSettingsFilePath,
        const QString &masterSettingsFilePath,
        const QString &requestsNamesFilePath,
        const QString &requestsQueriesFilePath,
        QWidget *parent
        )
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_settingsDialog{ new SettingsDialog(connectionSettingsFilePath, masterSettingsFilePath, this) }
    , m_master{ new SpectrMaster(connectionSettingsFilePath, m_settingsDialog->masterId(), this)}
    , mFile_requestNames{ requestsNamesFilePath }
    , mFile_requestQueries{ requestsQueriesFilePath }
{
    qInfo() << "MainWindow construction...";

    ui->setupUi(this);

    // получение данных из файлов
    updateRequestNamesList();
    updateQueriesList();

    // инициализация виджетов
    initMenuWidget();
    initCentralWidget();
    initConnections();

    // внешний вид окна
    setWindowTitle(tr("Эмулятор устройства Spectr"));
    adjustSize();

    qInfo() << "/MainWindow constructed";
}

MainWindow::~MainWindow()
{
    qInfo() << "~MainWindow";
    updateQueriesFile();
    delete ui;
}

// инициализация основного виджета окна
void MainWindow::initCentralWidget()
{
    qInfo() << "MainWindow::initCentralWidget";

    if (centralWidget()->layout()) { delete centralWidget()->layout(); }
    auto layout{ new QHBoxLayout(centralWidget()) };

    initRequestGroupBox();
    initReplyGroupBox();

    // добавление ранее сгенерированных виджетов
    layout->addWidget(mGroupBox_request);
    layout->addWidget(groupBox_reply);
}

// связываение Сигналов и Слотов
void MainWindow::initConnections()
{
    qInfo() << "MainWindow::initConnections";

    // кнопки меню инструментов
    connect(mAction_openSettings, &QAction::triggered, m_settingsDialog, &SettingsDialog::exec);

    // переключение запросов
    connect(comboBox_requestNames, &QComboBox::currentIndexChanged,
            stackedWidget_requestParameters, &QStackedWidget::setCurrentIndex);

    // изменение настроек
    connect(m_settingsDialog, &SettingsDialog::masterSettingsChanged, m_master, &SpectrMaster::setId);
    connect(m_settingsDialog, &SettingsDialog::connectionSettingsChanged,
            m_master, &SpectrMaster::updateConnectionSettings);

    // сигналы мастера
    connect(m_master, &SpectrMaster::errorOccured, statusBar(), [this](const QString &message){
        statusBar()->showMessage(message);
    });
    connect(m_master, &SpectrMaster::newMessage, this, &MainWindow::logWriteLine);

    // отправка запроса
    connect(pushButton_sendRequest, &QPushButton::clicked, [this](){ m_master->sendRequest(createQuery()); });

    // включение и отключение режима эмуляции
    connect(pushButton_emulationSwitcher, &QPushButton::toggled, [this](bool checked) {
        // смена стиля кнопки
        QString buttonText = checked ? "Прекратить эмуляцию" : "Начать эмуляцию";
        pushButton_emulationSwitcher->setText(buttonText);

        // отключение виджетов
        mAction_openSettings->setDisabled(checked);
        comboBox_requestNames->setDisabled(checked);
        stackedWidget_requestParameters->setDisabled(checked);
        pushButton_sendRequest->setDisabled(checked);

        // переключение эмуляции
        m_master->toggleEmulationMode(checked);
    });
}


// инициализация поля инструментов
void MainWindow::initMenuWidget()
{
    qInfo() << "MainWindow::initMenuWidget";

    mAction_openSettings = new QAction(QIcon(QStringLiteral("assets/icons/settings.svg")), tr("Настроки"), this);

    menuWidget()->addAction(mAction_openSettings);
}

// создание группы с запросом
void MainWindow::initRequestGroupBox()
{
    qInfo() << "MainWindow::initRequestGroupBox";

    if (mGroupBox_request) { delete mGroupBox_request; }
    mGroupBox_request = new QGroupBox(tr("Запрос:"), this);

    auto layout{ new QGridLayout(mGroupBox_request) };

    initRequestComboBox();
    initRequestStackedWidget();
    initRequestButtons();

    layout->addWidget(comboBox_requestNames);
    layout->addWidget(stackedWidget_requestParameters);
    layout->addWidget(pushButton_emulationSwitcher);
    layout->addWidget(pushButton_sendRequest);
}

// создание группы с ответом от сервера
void MainWindow::initReplyGroupBox()
{
    qInfo() << "MainWindow::initReplyGroupBox";

    if (groupBox_reply) { delete groupBox_reply; }
    groupBox_reply = new QGroupBox(tr("Ответ:"), this);

    auto layout{ new QVBoxLayout(groupBox_reply) };

    textBrowser_log = new QTextBrowser(groupBox_reply);
    textBrowser_log->setMinimumWidth(500);

    layout->addWidget(textBrowser_log);
}

// создание группы со списками запросов
void MainWindow::initRequestComboBox()
{
    qInfo() << "MainWindow::initRequestComboBox";

    if (comboBox_requestNames) { delete comboBox_requestNames; }
    comboBox_requestNames = new QComboBox(this);

    for (auto &requestName : mList_requestNames) {
        comboBox_requestNames->addItem(requestName);
    }
}

// should be remade
// создание виджета с группами параметров
void MainWindow::initRequestStackedWidget()
{
    qInfo() << "MainWindow::initRequestStackedWidget";

    if (stackedWidget_requestParameters) { delete stackedWidget_requestParameters; }
    stackedWidget_requestParameters = new QStackedWidget(this);

    auto request_count{ mList_requestNames.count() };
    auto queries_count{ mList_requestQueries.count() };

    // заполнение списка виджетов, и их инициализация, по количеству запросов
    for (int i{}; i < request_count; ++i) {
        auto *newWidget{ new QWidget(stackedWidget_requestParameters) };
        auto *newLayout{ new QFormLayout(newWidget) };

        if (i < queries_count) {
            listListPair_requestRows.append(QList<PairLabelLineedit>());
            for (auto &pair_parameter : mList_requestQueries.at(i).queryItems()) {
                auto newLabel{ new QLabel(pair_parameter.first, newWidget) };
                auto newLineEdit{ new QLineEdit(pair_parameter.second, newWidget) };

                listListPair_requestRows[i].append(PairLabelLineedit(newLabel, newLineEdit));
                newLayout->addRow(newLabel, newLineEdit);
            }
        }
        stackedWidget_requestParameters->addWidget(newWidget);
    }
}

void MainWindow::initRequestButtons()
{
    qInfo() << "MainWindow::initRequestButtons";

    pushButton_sendRequest = new QPushButton("Отправить запрос", this);

    pushButton_emulationSwitcher = new QPushButton(mGroupBox_request);
    pushButton_emulationSwitcher->setText("Включить эмуляцию");
    pushButton_emulationSwitcher->setCheckable(true);
}

// обновление списка имён запросов
void MainWindow::updateRequestNamesList()
{
    qInfo() << "MainWindow::updateRequestNamesList";

    mFile_requestNames.open(QIODevice::ReadOnly);
    QTextStream stream{ &mFile_requestNames };

    QString line;
    while (stream.readLineInto(&line)) {
            if (line.isEmpty()) { continue; }
        mList_requestNames.append(line.trimmed());
    }
    mFile_requestNames.close();
}

// обновление списка query
void MainWindow::updateQueriesList()
{
    qInfo() << "MainWindow::updateQueriesList";

    mFile_requestQueries.open(QIODevice::ReadOnly);
    QTextStream stream{ &mFile_requestQueries };

    QString line;
    while (stream.readLineInto(&line)) {
        if (line.isEmpty()) { continue; }
        mList_requestQueries.append(QUrlQuery(line));
    }
    mFile_requestQueries.close();
}

void MainWindow::updateQueriesFile()
{
    qInfo() << "MainWindow::updateQueriesFile";

    mFile_requestQueries.open(QIODevice::WriteOnly);
    QTextStream stream{ &mFile_requestQueries };

    for (auto &query : mList_requestQueries) {
        stream << query.query() << '\n';
    }
    mFile_requestQueries.close();
}

const QUrlQuery MainWindow::createQuery()
{
    qInfo() << "SpectrMaster::createQuery";
    auto requestIndex{ stackedWidget_requestParameters->currentIndex() };

    auto labels{ stackedWidget_requestParameters->widget(requestIndex)->findChildren<QLabel *>() };
    auto lineEdits{ stackedWidget_requestParameters->widget(requestIndex)->findChildren<QLineEdit *>() };

    QUrlQuery query;
    query.addQueryItem(QStringLiteral("id"), QString::number(m_master->getIdInt()));
    for (int i{}; i < labels.count(); ++i) {
        query.addQueryItem(labels.at(i)->text(), lineEdits.at(i)->text());
    }
    mList_requestQueries[requestIndex] = query;


    return query;
}


//void MainWindow::processReply(QNetworkReply *reply)
//{
//    qInfo() << "SpectrMaster::processReply";
//    reply->deleteLater();

//    auto bArr_replyData{ reply->readAll() };
//    auto page{ m_lastQuery.queryItemValue(QStringLiteral("page")) };
//    if (page == QStringLiteral("getcmd")) {
//        if (bArr_replyData.contains("id=")) {
//            QMap<QString, QString> map_cmdData;
//            for (auto &bArr_parameter : bArr_replyData.split(';')) {
//                if (bArr_parameter.isEmpty()) { continue; }
//                auto keyVal{ bArr_parameter.split('=') };
//                map_cmdData.insert(keyVal[0].trimmed(), keyVal[1].trimmed());
//            }
//            processCommand(map_cmdData);
//        } else {
//            qInfo() << "no new command";
//        }
//    } else if (page == QStringLiteral("download")) {
//        auto str_dispositionHeader{ reply->header(QNetworkRequest::ContentDispositionHeader).toString() };
//        QString filename{ "track_file.mp3" };
//        for (auto &str : str_dispositionHeader.split(';')) {
//            if (str.isEmpty()) { continue; }
//            if (str.contains(QStringLiteral("filename="))) {
//                filename = str.split('=').at(1);
//            }
//        }
//        // создание директории и аудио файла
//        QDir::current().mkdir(QStringLiteral("audio"));
//        QFile file_audio{ QStringLiteral("audio/") + filename };

//        // запись полученных данных в файл
//        file_audio.open(QIODevice::WriteOnly);
//        file_audio.write(bArr_replyData);
//        file_audio.close();

//        qInfo() << "audio file downloaded:" << filename;
//    }

//    qInfo() << bArr_replyData;
//    logWriteLine(QStringLiteral("Reply: %1").arg(bArr_replyData));
//    pushButton_sendRequest->setDisabled(false);
//}

void MainWindow::logWriteLine(const QString &line)
{
    qInfo() << "MainWindow::logWriteLine";

    textBrowser_log->moveCursor(QTextCursor::End);
    textBrowser_log->insertPlainText(line + '\n');
}
