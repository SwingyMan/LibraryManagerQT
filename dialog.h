/*
Autor: Marcin Bogus, Tobiasz Syguda, Wiktoria Koman
Nazwa pliku: dialog.h
Funkcjonalność pliku: Dodawanie nowych rekordów do tabeli
Używane w: sqlite_functions.h, dialog.cpp, mainwindow.cpp
*/


#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();


private slots:

    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
