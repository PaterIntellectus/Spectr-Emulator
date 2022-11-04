#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(
        const QString &requestsNamesFilePath,
        const QString &requestsQueriesFilePath,
        QWidget *parent
        )
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_settingsDialog{ new SettingsDialog(this) }
    , m_emulator{ new SpectrEmulator(m_settingsDialog->masterId(), this) }
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
    initLogGroupBox();

    // добавление ранее сгенерированных виджетов
    layout->addWidget(mGroupBox_request);
    layout->addWidget(mGroupBox_log);
}

// связываение Сигналов и Слотов
void MainWindow::initConnections()
{
    qInfo() << "MainWindow::initConnections";

    // кнопки меню инструментов
    connect(mAction_openSettings, &QAction::triggered, m_settingsDialog, &SettingsDialog::exec);

    // переключение запросов
    connect(mComboBox_requestNames, &QComboBox::currentIndexChanged,
            mStackedWidget_requestParameters, &QStackedWidget::setCurrentIndex);

    // изменение настроек
    connect(m_settingsDialog, &SettingsDialog::masterNameChanged, [this](QStringView name) {
        setWindowTitle(tr("Эмулятор устройства Spectr (%1)").arg(name));
    });
    connect(m_settingsDialog, &SettingsDialog::masterIdChanged, m_emulator, &SpectrEmulator::setId);
    connect(m_settingsDialog, &SettingsDialog::serverHostUpdated, m_emulator, &SpectrEmulator::updateHost);
    connect(m_settingsDialog, &SettingsDialog::serverPortUpdated, m_emulator, &SpectrEmulator::updatePort);

    // сигналы мастера
    connect(m_emulator, &SpectrEmulator::newMessage, this, &MainWindow::logWriteLine);
    connect(m_emulator, &SpectrEmulator::errorMessage, this, &MainWindow::logWriteError);
    connect(m_emulator, &SpectrEmulator::errorMessage, [this](QStringView message){
        statusBar()->showMessage(QStringLiteral("%1").arg(message));
    });

    connect(mPushButton_sendRequest, &QPushButton::clicked, &QPushButton::setDisabled);
    connect(m_emulator,  &SpectrEmulator::finished, mPushButton_sendRequest, &QPushButton::setEnabled);

    // смена значения поля id команды, в запросе - Подтверждение команды,
    connect(m_emulator, &SpectrEmulator::cmdReceived, [this](const int idcmd) {
        mListListPair_requestRows.at(1).at(1).second->setText(QString::number(idcmd));
    });
    // смена значения поля 'st'(статус устройства)
    connect(m_emulator, &SpectrEmulator::statusChanged, [this](const int st) {
        mListListPair_requestRows.at(0).at(2).second->setText(QString::number(st));
    });

    // отправка запроса
    connect(mPushButton_sendRequest, &QPushButton::clicked, [this](){
        m_emulator->sendRequest(
                    static_cast<SpectrEmulator::RequestType>(mComboBox_requestNames->currentIndex())
                    , createQuery()
                    );
    });

    // блокировка интерфейса
    connect(mPushButton_emulationSwitcher, &QPushButton::toggled, this, &MainWindow::onEmulationModeSwitched);
    // включение эмуляции
    connect(mPushButton_emulationSwitcher, &QPushButton::toggled, m_emulator, &SpectrEmulator::toggleAutomaticMode);
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
    qInfo() << "MainWindow::initLogGroupBox";

    if (mGroupBox_request) { delete mGroupBox_request; }
    mGroupBox_request = new QGroupBox(tr("Запрос:"), this);

    auto layout{ new QGridLayout(mGroupBox_request) };

    initRequestComboBox();
    initRequestStackedWidget();
    initRequestButtons();

    layout->addWidget(mComboBox_requestNames);
    layout->addWidget(mStackedWidget_requestParameters);
    layout->addWidget(mPushButton_emulationSwitcher);
    layout->addWidget(mPushButton_sendRequest);
}

// создание группы с ответом от сервера
void MainWindow::initLogGroupBox()
{
    qInfo() << "MainWindow::initReplyGroupBox";

    if (mGroupBox_log) { delete mGroupBox_log; }
    mGroupBox_log = new QGroupBox(tr("Лог:"), this);

    auto layout{ new QVBoxLayout(mGroupBox_log) };

    mTextBrowser_log = new QTextBrowser(mGroupBox_log);
    mTextBrowser_log->setMinimumWidth(500);

    layout->addWidget(mTextBrowser_log);
}

// создание группы со списками запросов
void MainWindow::initRequestComboBox()
{
    qInfo() << "MainWindow::initRequestComboBox";

    if (mComboBox_requestNames) { delete mComboBox_requestNames; }
    mComboBox_requestNames = new QComboBox(this);

    for (const auto &requestName : mList_requestNames) {
        mComboBox_requestNames->addItem(requestName);
    }
}

// should be remade
// создание виджета с группами параметров
void MainWindow::initRequestStackedWidget()
{
    qInfo() << "MainWindow::initRequestStackedWidget";

    if (mStackedWidget_requestParameters) { delete mStackedWidget_requestParameters; }
    mStackedWidget_requestParameters = new QStackedWidget(this);

    auto request_count{ mList_requestNames.count() };
    auto queries_count{ mList_requestQueries.count() };

    // заполнение списка виджетов, и их инициализация, по количеству запросов
    for (int i{}; i < request_count; ++i) {
        auto *newWidget{ new QWidget(mStackedWidget_requestParameters) };
        auto *newLayout{ new QFormLayout(newWidget) };

        if (i < queries_count) {
            mListListPair_requestRows.append(QList<PairLabelLineedit>());
            for (const auto &pair_parameter : mList_requestQueries.at(i).queryItems()) {
                auto newLabel{ new QLabel(pair_parameter.first, newWidget) };
                auto newLineEdit{ new QLineEdit(pair_parameter.second, newWidget) };

                mListListPair_requestRows[i].append(PairLabelLineedit(newLabel, newLineEdit));
                newLayout->addRow(newLabel, newLineEdit);
            }
        }
        mStackedWidget_requestParameters->addWidget(newWidget);
    }
}

void MainWindow::initRequestButtons()
{
    qInfo() << "MainWindow::initRequestButtons";

    mPushButton_sendRequest = new QPushButton(tr("Отправить запрос"), this);

    mPushButton_emulationSwitcher = new QPushButton(mGroupBox_request);
    mPushButton_emulationSwitcher->setText(tr("Включить эмуляцию"));
    mPushButton_emulationSwitcher->setCheckable(true);
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

    for (const auto &query : mList_requestQueries) {
        stream << query.query() << '\n';
    }
    mFile_requestQueries.close();
}

const QUrlQuery MainWindow::createQuery()
{
    qInfo() << "SpectrMaster::createQuery";

    auto requestIndex{ mStackedWidget_requestParameters->currentIndex() };

    auto labels{ mStackedWidget_requestParameters->widget(requestIndex)->findChildren<QLabel *>() };
    auto lineEdits{ mStackedWidget_requestParameters->widget(requestIndex)->findChildren<QLineEdit *>() };

    QUrlQuery query;
    for (int i{}; i < labels.count(); ++i) {
        auto key{ labels.at(i)->text() }, value{ lineEdits.at(i)->text() };
        query.addQueryItem(key, value);

        // запись во внутреннюю структуру, для дальнейшего сохранения после выхода
        if (mList_requestQueries[requestIndex].hasQueryItem(key)) {
            mList_requestQueries[requestIndex].removeQueryItem(key);
        }
        mList_requestQueries[requestIndex].addQueryItem(key, value);

        // помещение параметра id сразу после первого параметра(page)
        if (!i) { query.addQueryItem(QStringLiteral("id"), QString::number(m_emulator->getId())); }
    }
    return query;
}

void MainWindow::logWriteLine(QStringView line)
{
    qInfo() << line;

    mTextBrowser_log->moveCursor(QTextCursor::End);
    mTextBrowser_log->insertPlainText(QStringLiteral("%1\n").arg(line));
}

void MainWindow::logWriteError(QStringView strv_error)
{
    logWriteLine(QStringLiteral("Error: %1").arg(strv_error));
}

// блокировка интерфейса при включении режима эмуляции
void MainWindow::onEmulationModeSwitched(bool checked)
{
    // смена стиля кнопки
    mPushButton_emulationSwitcher->setText(
                checked ? QStringLiteral("Прекратить эмуляцию") : QStringLiteral("Начать эмуляцию")
                          );

    // отключение виджетов
    mAction_openSettings->setDisabled(checked);
    mComboBox_requestNames->setDisabled(checked);
    mStackedWidget_requestParameters->setDisabled(checked);
    mPushButton_sendRequest->setDisabled(checked);
}
