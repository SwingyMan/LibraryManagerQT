#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "sqlite_functions.h"
#include "remover.h"
#include "edit.h"
#include "login.h"
#include <QCryptographicHash>
#include "login2.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QUrl>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    login login;
    SQLBook book;
    extern QString login1;
    extern QString password;
    while(true)
    {
    login.setModal(true);
    login.setWindowTitle("Logowanie");
    login.exec();
    if(book.isLoggedIn(login1,password))
    {
        break;
    }
    else
    {}
}
    QSqlTableModel *modal= new QSqlTableModel;
    modal->setTable("book");
    modal->select();
ui->tableView->setModel(modal);
modal->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Nazwa Książki"));
modal->setHeaderData(2, Qt::Horizontal, QObject::tr("ISBN"));
modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Autor"));
modal->setHeaderData(4, Qt::Horizontal, QObject::tr("Rok wydania"));
modal->setHeaderData(5, Qt::Horizontal, QObject::tr("Ilość"));
    }
MainWindow::~MainWindow()
{    
    delete ui;
}


void MainWindow::on_pushButton_5_clicked()
{
    Dialog dialog;
    dialog.setModal(true);
    dialog.setWindowTitle("Dodawanie");
    dialog.exec();
    QSqlTableModel *modal= new QSqlTableModel;
    modal->setTable("book");
    modal->select();
ui->tableView->setModel(modal);
modal->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Nazwa Książki"));
modal->setHeaderData(2, Qt::Horizontal, QObject::tr("ISBN"));
modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Autor"));
modal->setHeaderData(4, Qt::Horizontal, QObject::tr("Rok wydania"));
modal->setHeaderData(5, Qt::Horizontal, QObject::tr("Ilość"));
}


void MainWindow::on_pushButton_clicked()
{
login2 login2;
login2.setModal(true);
login2.setWindowTitle("Edycja logowania");
login2.exec();
}


void MainWindow::on_pushButton_8_clicked()
{
        QSqlTableModel *modal= new QSqlTableModel;
    modal->setTable("book");
    modal->select();
ui->tableView->setModel(modal);
modal->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Nazwa Książki"));
modal->setHeaderData(2, Qt::Horizontal, QObject::tr("ISBN"));
modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Autor"));
modal->setHeaderData(4, Qt::Horizontal, QObject::tr("Rok wydania"));
modal->setHeaderData(5, Qt::Horizontal, QObject::tr("Ilość"));
}


void MainWindow::on_pushButton_4_clicked()
{
    SQLBook book;
    remover remover;
    remover.setModal(true);
    remover.setWindowTitle("Usuwanie");
    remover.exec();
    QSqlTableModel *modal= new QSqlTableModel;
    modal->setTable("book");
    modal->select();
ui->tableView->setModel(modal);
modal->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Nazwa Książki"));
modal->setHeaderData(2, Qt::Horizontal, QObject::tr("ISBN"));
modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Autor"));
modal->setHeaderData(4, Qt::Horizontal, QObject::tr("Rok wydania"));
modal->setHeaderData(5, Qt::Horizontal, QObject::tr("Ilość"));
}


void MainWindow::on_pushButton_9_clicked()
{
    edit edit;
    edit.setModal(true);
    edit.setWindowTitle("Edycja");
    edit.exec();
    QSqlTableModel *modal= new QSqlTableModel;
    modal->setTable("book");
    modal->select();
ui->tableView->setModel(modal);
modal->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Nazwa Książki"));
modal->setHeaderData(2, Qt::Horizontal, QObject::tr("ISBN"));
modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Autor"));
modal->setHeaderData(4, Qt::Horizontal, QObject::tr("Rok wydania"));
modal->setHeaderData(5, Qt::Horizontal, QObject::tr("Ilość"));
}


void MainWindow::on_pushButton_2_clicked()
{
    login login;
    SQLBook book;
    extern QString login1;
    extern QString password;
    while(true)
    {
    login.setModal(true);
    login.setWindowTitle("Logowanie");
    login.exec();
    if(book.isLoggedIn(login1,password))
    {
        break;
    }
    else
    {}
}
}

