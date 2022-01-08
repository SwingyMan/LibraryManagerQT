#include "dialog.h"
#include "ui_dialog.h"

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

void Dialog::on_lineEdit_editingFinished()
{
    QLineEdit lineEdit;
    QString name = lineEdit.text();
}


void Dialog::on_lineEdit_2_editingFinished()
{
    QLineEdit lineEdit2;
    QString name2 = lineEdit2.text();
}


void Dialog::on_lineEdit_3_editingFinished()
{
    QLineEdit lineEdit3;
    QString name3 = lineEdit3.text();
}


void Dialog::on_lineEdit_4_editingFinished()
{
    QLineEdit lineEdit4;
    QString name4 = lineEdit4.text();
}


void Dialog::on_lineEdit_5_editingFinished()
{
    QLineEdit lineEdit5;
    QString name5 = lineEdit5.text();
}

