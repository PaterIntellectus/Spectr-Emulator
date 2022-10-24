#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QDir>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "russianTranslation_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    QDir::current().mkdir("requests");
    QDir::current().mkdir("settings");

    MainWindow w {
        QStringLiteral("requests/names.txt"),
        QStringLiteral("requests/queries.txt")
    };
    w.show();
    return a.exec();
}
