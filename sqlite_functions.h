/*
Autor: Marcin Bogus, Tobiasz Syguda, Wiktoria Koman
Nazwa pliku: sqlite_functions.h
Funkcjonalność pliku: Plik z deklaracją klasy służącej obsługiwaniu żądań SQL
Używane w: dialog.cpp, edit.cpp, edit2.cpp, login.cpp, login2.cpp, main.cpp, mainwindow.cpp, remover.cpp, sqlite_functions.cpp
*/


#ifndef SQLITE_FUNCTIONS_H
#define SQLITE_FUNCTIONS_H
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include "dialog.h"
class SQLBook
{

public:
    QSqlDatabase db;
void initialize(); // Funkcja podstawowej inicjalizacji.

void put_records(QString name,QString isbn,QString author,QString yop,QString quantity); // Funkcja do wprowadzania kolejnych rekordów.

void drop_row(int row); // Funkcja do usuwania wierszy.

bool getData(int id,QString *title,QString *author,QString *isbn,QString *quantity,QString *yop); // Funkcja pobierające dane wybranego rekordu.

void update_data(int id,QString title,QString author,QString isbn,QString quantity,QString yop); // Funkcja umożliwiająca modyfikację danego rekordu.

void close(); // Funkcja zamykająca połączenia z bazą danych.

bool isLoggedIn(QString login,QString password); //  Funkcja sprawdzająca poprawność danych logowania.

void changeLogin(QString login,QString password); // Funkcja służąca do zmiany danych logowania.

};
#endif // SQLITE_FUNCTIONS_H
