/*
Autor: Marcin Bogus, Tobiasz Syguda, Wiktoria Koman
Nazwa pliku: edit.h
Funkcjonalność pliku: Plik z klasą odpowiadający za pierwsze okno edycji
Używane w: edit.cpp, mainwindow.cpp
*/

#ifndef EDIT_H
#define EDIT_H

#include <QDialog>

namespace Ui {
class edit;
}

class edit : public QDialog
{
    Q_OBJECT

public:
    explicit edit(QWidget *parent = nullptr);
    ~edit();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::edit *ui;
};

#endif // EDIT_H
