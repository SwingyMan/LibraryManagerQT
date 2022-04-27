/*
Autor: Marcin Bogus, Tobiasz Syguda, Wiktoria Koman
Nazwa pliku: remover.h
Funkcjonalność pliku: Deklaracja klasy, która obsługuje okienko po wciśnięciu usuń
Używane w: mainwindow.cpp, remover.cpp
*/


#ifndef REMOVER_H
#define REMOVER_H

#include <QDialog>

namespace Ui {
class remover;
}

class remover : public QDialog
{
    Q_OBJECT

public:
    explicit remover(QWidget *parent = nullptr);
    ~remover();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::remover *ui;
};

#endif // REMOVER_H
