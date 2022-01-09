#include "dialog.h"
#include "ui_dialog.h"
#include "sqlite_functions.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    SQLBook book;
    QString name = ui->lineEdit->text();
    QString author = ui->lineEdit_2->text();
    QString quantity = ui->lineEdit_3->text();
    QString isbn = ui->lineEdit_4->text();
    QString year_of_production = ui->lineEdit_5->text();
book.put_records(name,isbn,author,year_of_production,quantity);
}

