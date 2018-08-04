#ifndef DB_H
#define DB_H
#include <QtSql>
#include <QLayout>
class DB
{
public:
    DB();
    void makeDB(QString path);
    void addvalues(QString,int);
    void update(QString,int);
    void deleted(QString);
    void pull();
private:
    QSqlDatabase db;
};

#endif // DB_H
