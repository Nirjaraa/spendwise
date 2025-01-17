#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H
#include <QMainWindow>
#include "signin.h"
#include "dashboard.h"
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>


namespace Ui {
class MainWindow1;
}

class MainWindow1 : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase logindb; //database created
    void connClose()
    {
        logindb.close();
        logindb.removeDatabase(QSqlDatabase::defaultConnection); //removing any connections
    }
    bool connOpen()//this function will check if database is open or not
    {
        logindb = QSqlDatabase::addDatabase("QSQLITE");
        logindb.setDatabaseName("C:/Users/USER/git1/spendwise/db/login.db");

        // to see if the database is connected to the program
        if(!logindb.open()){
            qDebug()<<("Failed to open the databse");
            return false;
        }
        else{
            qDebug()<<("Connected");\
                return true;
        }
    }


public:
    explicit MainWindow1(QWidget *parent = nullptr);
    ~MainWindow1();

private slots:
    void on_pushButton_clicked();

    void on_login_clicked();

    void on_view_clicked(bool checked);

private:
    Ui::MainWindow1 *ui;
    signin *signinn;
    dashboard *d;
};

#endif // MAINWINDOW1_H
