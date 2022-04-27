/*
Autor: Marcin Bogus, Tobiasz Syguda, Wiktoria Koman
Funkcjonalność pliku: Główny plik przy kompilacji programu
Nazwa pliku: main.cpp
*/



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
    w.setWindowTitle("Librarian");
    w.show();
    return a.exec();
    book.close();
}
