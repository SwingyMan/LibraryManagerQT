/*
Autor: Marcin Bogus, Tobiasz Syguda, Wiktoria Koman
Nazwa pliku: login.cpp
*/


#include "login.h"
#include "ui_login.h"
#include "sqlite_functions.h"
QString login1;
QString password;
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    SQLBook book;
    book.initialize(); // Otwarcie bazy danych.
}

login::~login()
{
    delete ui;
}

void login::on_buttonBox_accepted()
{
    login1 = ui->lineEdit->text(); // Zapisanie danych logowania w zmiennej.
    password = ui->lineEdit_2->text();
}


void login::on_buttonBox_rejected()
{
    exit(EXIT_FAILURE); // Dodanie możliwości wyjścia z programu.
}

