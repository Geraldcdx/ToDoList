#include "mainwindow.h"
#include <QApplication>
#include <QtSql>

//void addvalues(int ID,QString Item,int Progress)
//{
//    QSqlDatabase db;
//    db=QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:/Users/Gerald/Desktop/orbitaltest/db.sqlite");
//    if(!db.open()) qDebug()<<"FAILED";
//    QSqlQuery qry;
//    qry.prepare("INSERT INTO todoDB ("
//                "ID,"
//                "Item,"
//                "Progress)"
//                "VALUES (?,?,?);");
//    qry.addBindValue(ID);
//    qry.addBindValue(Item);
//    qry.addBindValue(Progress);
//    if(!qry.exec())qDebug()<<"qruy failed";
//    db.close();
//}
//void update(int ID,QString Item,int Progress)
//{
//    QSqlDatabase db;
//    db=QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:/Users/Gerald/Desktop/orbitaltest/db.sqlite");
//    if(!db.open()) qDebug()<<"FAILED";
//    QSqlQuery qry;
//    qry.prepare("update todoDB set ID=?,Item=?,Progress=? where Item=?" );
//    qry.addBindValue(ID);
//    qry.addBindValue(Item);
//    qry.addBindValue(Progress);
//    qry.addBindValue(ID);
//    if(!qry.exec())qDebug()<<"Doesn't work";
//    db.close();
//}
//void deleted(int ID)
//{
//    QSqlDatabase db;
//    db=QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:/Users/Gerald/Desktop/orbitaltest/db.sqlite");
//    if(!db.open()) qDebug()<<"FAILED";
//    QSqlQuery qry;
//    qry.prepare("delete from todoDB where ID=?");
//    qry.addBindValue(ID);
//    if(!qry.exec())qDebug()<<"GG";
//    db.close();
//}
//int id,pro;
//QString name;
//void pull()
//{
//    QSqlDatabase db;
//    db=QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:/Users/Gerald/Desktop/orbitaltest/db.sqlite");
//    if(!db.open()) qDebug()<<"FAILED";
//    QSqlQuery qry;
//    qry.prepare("SELECT ID,Item,Progress FROM todoDB");
//    qry.exec();
//    while (qry.next()) {
//            QSqlRecord record = qry.record();
//            qDebug() <<record.value("ID").toString()<<record.value("Item").toString()<<record.value("Progress").toInt();
//        }
//    db.close();
//}
//void makeDB()
//{
//    QSqlDatabase db;
//    db=QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("C:/Users/Gerald/Desktop/orbitaltest/db.sqlite");
//    if(!db.open()) qDebug()<<"FAILED";
//    QString query="CREATE TABLE todoDB ("
//                  "ID integer,"
//                  "Item VARCHAR(150),"
//                   "Progress integer);";
//    QSqlQuery qry;
//    if(!qry.exec(query)) qDebug()<<"Query failed or Database already created";
//    db.close();
//}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
