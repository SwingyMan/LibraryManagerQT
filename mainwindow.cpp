#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
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

}

