#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "sqlite_functions.h"
#include "remover.h"
#include "edit.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
}


void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Zapisz dane biblioteki"), "",
            tr("Plik bazy danych (*.db);;Wszystkie pliki (*)"));
}


void MainWindow::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Wczytaj dane biblioteki"), "",
            tr("Plik bazy danych (*.db);;Wszystkie pliki (*)"));
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
}


void MainWindow::on_pushButton_9_clicked()
{
    SQLBook book;
    edit edit;
    edit.setModal(true);
    edit.setWindowTitle("Edycja");
    edit.exec();
}

