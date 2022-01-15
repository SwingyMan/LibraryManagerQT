#include "edit2.h"
#include "ui_edit2.h"
#include "sqlite_functions.h"
QString id2;
extern QString name;
extern int id;
extern QString quantity;
extern QString yop;
extern QString author;
extern QString isbn;

edit2::edit2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit2)
{
    ui->setupUi(this);

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

void edit2::on_buttonBox_accepted()
{
    SQLBook book;
    name = ui->lineEdit_2->text();
    author =ui->lineEdit_3->text();
    isbn =ui->lineEdit_4->text();
    quantity = ui->lineEdit_5->text();
    yop =ui->lineEdit_6->text();
    book.update_data(id,name,author,isbn,yop,quantity);
}

