#include "login2.h"
#include "ui_login2.h"
#include "sqlite_functions.h"
login2::login2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login2)
{
    ui->setupUi(this);
}

login2::~login2()
{
    delete ui;
}

void login2::on_buttonBox_accepted()
{
    QString login1;
    QString password;
    login1 = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    SQLBook book;
    book.changeLogin(login1,password);
}

