#include "db.h"
#include <QtSql>

 DB::DB()
{

}
void DB::addvalues(QString Item,int Progress)
{
    if(!db.open()) qDebug()<<"FAILED";
    QSqlQuery qry;
    qry.prepare("INSERT INTO todoDB ("
                "Item,"
                "Progress)"
                "VALUES (?,?);");
    qry.addBindValue(Item);
    qry.addBindValue(Progress);
    if(!qry.exec())qDebug()<<"qruy failed";
    db.close();
}
void DB::update(QString Item,int Progress)
{
    if(!db.open()) qDebug()<<"FAILED";
    QSqlQuery qry;
    qry.prepare("update todoDB set Item=?,Progress=? where Item=?" );
    qry.addBindValue(Item);
    qry.addBindValue(Progress);
    qry.addBindValue(Item);
    if(!qry.exec())qDebug()<<"Doesn't work";
    db.close();
}
void DB::deleted(QString Item)
{

    if(!db.open()) qDebug()<<"FAILED";
    QSqlQuery qry;
    qry.prepare("delete from todoDB where Item=?");
    qry.addBindValue(Item);
    if(!qry.exec())qDebug()<<"GG";
    db.close();
}

void DB::pull()
{
    if(!db.open()) qDebug()<<"FAILED";
    QSqlQuery qry;
    qry.prepare("SELECT Item,Progress FROM todoDB");
    qry.exec();
    while (qry.next()) {
            QSqlRecord record = qry.record();
            qDebug() <<record.value("Item").toString()<<record.value("Progress").toInt();

        }
    db.close();
}
void DB::makeDB(QString path)
{
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);//"C:/Users/Gerald/Desktop/orbitaltest/db.sqlite"
    if(!db.open()) qDebug()<<"FAILED";
    QString query="CREATE TABLE todoDB ("
                  "Item VARCHAR(150),"
                   "Progress integer);";
    QSqlQuery qry;
    if(!qry.exec(query)) qDebug()<<"Query failed or Database already created";
    db.close();
}
