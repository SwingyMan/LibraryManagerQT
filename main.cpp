#include "mainwindow.h"
#include "sqlite_functions.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
QLocale::setDefault(QLocale(QLocale::Polish));
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Library_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    SQLBook book;
    book.initialize();
    w.setWindowTitle("Librarian");
    w.show();
    book.close();
    return a.exec();
}
