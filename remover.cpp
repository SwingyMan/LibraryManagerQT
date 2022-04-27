/*
Autor: Marcin Bogus, Tobiasz Syguda, Wiktoria Koman
Nazwa pliku: remover.cpp
*/


#include "remover.h"
#include "ui_remover.h"
#include "sqlite_functions.h"
remover::remover(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::remover)
{
    ui->setupUi(this);
}

remover::~remover()
{
    delete ui;
}

void remover::on_buttonBox_accepted() // Usuwanie danego rekordu.
{
    SQLBook book;
   int row = ui->lineEdit->text().toInt();
   book.drop_row(row);
}

