#include "edit2.h"
#include "ui_edit2.h"
#include "sqlite_functions.h"
edit2::edit2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit2)
{
    ui->setupUi(this);
    QString id2;
    extern QString name;
    extern int id;
    extern QString quantity;
    extern QString yop;
    extern QString author;
    extern QString isbn;
    id2 = QString::number(id);
    ui->lineEdit->setText(id2);
    ui->lineEdit_2->setText(name);
    ui->lineEdit_3->setText(author);
    ui->lineEdit_4->setText(isbn);
    ui->lineEdit_5->setText(quantity);
    ui->lineEdit_6->setText(yop);
}

edit2::~edit2()
{
    delete ui;
}
