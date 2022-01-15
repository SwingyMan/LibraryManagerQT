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
      query.clear();
      query.exec("CREATE TABLE account(id INTEGER PRIMARY KEY AUTOINCREMENT, login TEXT NOT NULL, password TEXT NOT NULL)");
      query.clear();
      query.exec("SELECT * FROM account");
      if(query.isValid())
      {
          query.clear();
          query.exec("INSERT INTO account(login, password)"
                 "VALUES ('admin','admin')");
}
else
{}
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
void drop_row(int row)
{
QSqlQuery query;
query.prepare("DELETE FROM book WHERE id= :id");
query.bindValue(":id",row);
if(query.exec())
{
    qDebug() <<"success";
}
else{
    qDebug() <<"fail";
}
}
void getData(int id,QString *title,QString *author,QString *isbn,QString *quantity,QString *yop)
{
QSqlQuery query;
query.prepare("SELECT id, name, isbn, author, year_of_production, quantity FROM book WHERE id= :id");
query.bindValue(":id",id);
query.exec();
query.first();
qDebug() << query.size();
* title = query.value(1).toString();
* author = query.value(2).toString();
* isbn = query.value(3).toString();
* quantity = query.value(4).toString();
* yop = query.value(5).toString();
}
void update_data(int id,QString title,QString author,QString isbn,QString quantity,QString yop)
{
    QSqlQuery query;
    query.clear();
    query.prepare("UPDATE book SET name= :name, isbn= :isbn, author = :author, year_of_production= :yop, quantity= :quantity WHERE id= :id");
    query.bindValue(":id",id);
    query.bindValue(":name",title);
    query.bindValue(":isbn",isbn);
    query.bindValue(":author",author);
    query.bindValue(":yop",yop);
    query.bindValue(":quantity",quantity);
    if(query.exec())
      {
          qDebug() <<"Succesfull";
      }
      else
      {
           qDebug() << "addPerson error:"
                    << query.lastError();
      }
    if(query.isValid())
    {
        QMessageBox msgBox;
        msgBox.setText("Błędny rekord");
        msgBox.exec();
    }
    else
    {

    }
}
void close()
{
    db.close();
    qDebug()<<"Connection closed";
}
bool isLoggedIn(QString login,QString password)
{
    QSqlQuery query;
    QByteArray pass = password.toUtf8();
    QCryptographicHash::hash(pass,QCryptographicHash::Sha512);
    query.prepare("SELECT login,password FROM account WHERE login= :login AND password= :password");
    query.bindValue(":login",login);
    query.bindValue(":password",password);
    query.exec();
    if(query.next())
    {
        qDebug() <<"Succesfull";
        return true;
    }
    else
    {
         qDebug() << "addPerson error:"
                  << query.lastError();
         return false;
    }
}
void changeLogin(QString login,QString password)
{
    QSqlQuery query;
    QByteArray pass = password.toUtf8();
    QCryptographicHash::hash(pass,QCryptographicHash::Sha512);
    query.prepare("UPDATE account SET login= :login, password = :password WHERE id=1");
    query.bindValue(":login",login);
    query.bindValue(":password",password);
    query.exec();
}
};
#endif // SQLITE_FUNCTIONS_H
