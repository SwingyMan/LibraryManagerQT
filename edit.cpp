/*
Autor: Marcin Bogus, Tobiasz Syguda, Wiktoria Koman
Nazwa pliku: edit.cpp
*/




#include "edit.h"
#include "ui_edit.h"
#include "sqlite_functions.h"
#include "edit2.h"
QString name; // Przygotowanie zmiennych do uzupełniania rekordu.
QString author;
QString isbn;
QString quantity;
QString yop;
   QString *name_poi =&name;
   QString *author_poi = &author;
   QString *isbn_poi = &isbn;
   QString *quantity_poi = &quantity;
   QString *yop_poi = &yop;
   int id;
edit::edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit)
{
    ui->setupUi(this);
}

edit::~edit()
{
    delete ui;
}

void edit::on_buttonBox_accepted()
{
    SQLBook book;

     id = ui->lineEdit->text().toInt(); // Pobranie id rekordu.

    if(book.getData(id,name_poi,author_poi,isbn_poi,quantity_poi,yop_poi)) // Sprawdzenie czy rekord jest "pusty".
 {edit2 edit2;
    edit2.setModal(true);
    this->hide();
    edit2.setWindowTitle("Edycja");
    edit2.exec();}
    else
{
        QMessageBox msgBox;
        msgBox.setText("Błędny rekord");
        msgBox.exec();
    }
}

