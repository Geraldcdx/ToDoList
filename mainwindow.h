#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void makeDB(QString path);
    void addvalues(QString,int);
    void pull();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
public slots:
    void deleted(QString);
    void update(QString,int);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
};

#endif // MAINWINDOW_H
