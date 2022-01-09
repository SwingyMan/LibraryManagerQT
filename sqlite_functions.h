#ifndef SQLITE_FUNCTIONS_H
#define SQLITE_FUNCTIONS_H
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtSql>
#include <QDebug>
#include "dialog.h"
class SQLBook
{

public:
    QSqlDatabase db;
void initialize()
{
    const QString DRIVER("QSQLITE");
 db = QSqlDatabase::addDatabase(DRIVER);
      db.setDatabaseName("database.sql");
      if(!db.open())
      {
          qDebug()<<"Error opening database" << db.lastError();
      }else{
          qDebug()<<"Connection Established.";
      }
      QSqlQuery query;
      query.exec("CREATE TABLE book(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, isbn TEXT, author TEXT, year_of_production TEXT, quantity TEXT)");
}
void put_records(QString name,QString isbn,QString author,QString yop,QString quantity)
{
  QSqlQuery query;
  query.prepare("INSERT INTO book (name, isbn, author, year_of_production, quantity)"
                "VALUES (:name, :isbn, :author, :yop, :quantity)");
  query.bindValue(":name", name);
  query.bindValue(":isbn", isbn);
  query.bindValue(":author", author);
  query.bindValue(":yop", yop);
  query.bindValue(":quantity", quantity);
          if(query.exec())
            {
                qDebug() <<"Succesfull";
            }
            else
            {
                 qDebug() << "addPerson error:"
                          << query.lastError();
            }
}
void export_records()
{
QSqlQuery query("SELECT * FROM book");
}
void close()
{
    db.close();
    qDebug()<<"Connection closed";
}
};
#endif // SQLITE_FUNCTIONS_H
