#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "item.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QPushButton>
#include <QRadioButton>
#include "dialog.h"
#include <QtSql>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    makeDB("C:/Users/Gerald/Desktop/orbitaltest/db.sqlite");
    //addvalues("LOLO",100);
    //deleted("KKK");
    pull();

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Dialog add;
    add.exec();
    QString item=add.GetText();
    Item *i=new Item;
    connect(i,SIGNAL(itemdeleted(QString)),this,SLOT(deleted(QString)));
    connect(i,SIGNAL(changeVal(QString,int)),this,SLOT(update(QString,int)));
    i->setText(item);
    i->setProgress(0);
    ui->verticalLayout->addWidget(i);
    addvalues(item,0);
}
void MainWindow::addvalues(QString Item,int Progress)
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
void MainWindow::update(QString Item,int Progress)
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
void MainWindow::deleted(QString Item)
{
    if(!db.open()) qDebug()<<"FAILED";
    QSqlQuery qry;
    qry.prepare("delete from todoDB where Item=?");
    qry.addBindValue(Item);
    if(!qry.exec())qDebug()<<"GG";
    db.close();
}

void MainWindow::pull()
{
    if(!db.open()) qDebug()<<"FAILED";
    QSqlQuery qry;
    qry.prepare("SELECT Item,Progress FROM todoDB");
    qry.exec();
    //int num=1;
    //QString str="i";
    while (qry.next()){
            QSqlRecord record = qry.record();
            qDebug() <<record.value("Item").toString()<<record.value("Progress").toInt();
            Item *i=new Item;
            connect(i,SIGNAL(itemdeleted(QString)),this,SLOT(deleted(QString)));
            i->setText(record.value("Item").toString());
            i->setProgress(record.value("Progress").toInt());
            connect(i,SIGNAL(changeVal(QString,int)),this,SLOT(update(QString,int)));
            ui->verticalLayout->addWidget(i);
        }
    db.close();
}
void MainWindow::makeDB(QString path)
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
