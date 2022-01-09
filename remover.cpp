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

void remover::on_buttonBox_accepted()
{
    SQLBook book;
    int id = ui->lineEdit->text().toInt();
    book.drop_row(id);
}

