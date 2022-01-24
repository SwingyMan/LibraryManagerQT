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
void initialize() // podstawowa inicjalizacja
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
      QSqlQuery query; // tworzenie podstawowych rekordów
      query.exec("CREATE TABLE book(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, isbn TEXT, author TEXT, year_of_production TEXT, quantity TEXT)");
      query.clear();
      query.exec("CREATE TABLE account(id INTEGER PRIMARY KEY AUTOINCREMENT, login TEXT NOT NULL, password TEXT NOT NULL)");
      query.clear();
      query.exec("SELECT * FROM account");
      if(query.first()) // stworzenia uniwersalnego konta w razie braku jakiegokolwiek
      {
}
else
{
          query.clear();
          query.exec("INSERT INTO account(login, password)"
                 "VALUES ('admin','8c6976e5b5410415bde908bd4dee15dfb167a9c873fc4bb8a81f6f2ab448a918')");
      }
}
void put_records(QString name,QString isbn,QString author,QString yop,QString quantity) // funkcja do wkładania rekordów
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
void drop_row(int row) // funkcja do wyrzucania wierszy
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
bool getData(int id,QString *title,QString *author,QString *isbn,QString *quantity,QString *yop) // funkcja do wyciągania danych z wiersza
{
QSqlQuery query;
query.prepare("SELECT id, name, isbn, author, year_of_production, quantity FROM book WHERE id= :id");
query.bindValue(":id",id);
query.exec();
if(query.first()) // kontrola prawidłowości rekordu
{* title = query.value(1).toString();
* author = query.value(3).toString();
* isbn = query.value(2).toString();
* quantity = query.value(5).toString();
* yop = query.value(4).toString();
return true;}
else
{
    return false;
}
}
void update_data(int id,QString title,QString author,QString isbn,QString quantity,QString yop) // funkcja do modyfikacji wiersza
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
}
void close() // zamykanie połączenia z bazą danych
{
    db.close();
    qDebug()<<"Connection closed";
}
bool isLoggedIn(QString login,QString password) // sprawdzenie poprawności zalogowania
{
    QSqlQuery query;
    QByteArray pass(password.toStdString().c_str());
    pass = QCryptographicHash::hash(pass,QCryptographicHash::Sha256).toHex(); // szyfrowanie hasła
    password = pass;
    query.prepare("SELECT id,login,password FROM account WHERE id=1 AND login= :login AND password= :password");
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
void changeLogin(QString login,QString password) // funkcja do zmiany danych logowania
{
    QSqlQuery query;
    QByteArray pass(password.toStdString().c_str());
    pass = QCryptographicHash::hash(pass,QCryptographicHash::Sha256).toHex(); //szyfrowanie hasła
    password = pass;
    query.prepare("UPDATE account SET login= :login, password = :password WHERE id=1");
    query.bindValue(":login",login);
    query.bindValue(":password",password);
    query.exec();
}
};
#endif // SQLITE_FUNCTIONS_H
