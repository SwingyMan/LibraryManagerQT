#ifndef SQLITE_FUNCTIONS_H
#define SQLITE_FUNCTIONS_H
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
typedef struct sqlite3 sqlite3;
#include<iostream>
class Book
{
    std::string name;
    int id;
    std::string isbn;
    std::string author;
    int year_of_production;
    int quantity;
};
class SQLBook
{
void initialize()
{
    const QString DRIVER("QSQLITE");
    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
      db.setDatabaseName(":memory:");
      QSqlQuery query("CREATE TABLE book(id INTEGER PRIMARY KEY, name TEXT,isbn TEXT,author TEXT,year_of_production INTEGER,quantity INTEGER)");
}
void put_records()
{
 QSqlQuery query("INSERT INTO BOOK "+);
}
void export_records();
};
#endif // SQLITE_FUNCTIONS_H
