#ifndef CHECKBALANCE_H
#define CHECKBALANCE_H

#include <QMainWindow>
#include"newincome.h"
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>


namespace Ui {
class checkbalance;
}

class checkbalance : public QMainWindow
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
        logindb.setDatabaseName("C:/New folder/spendwise/db/login.db");
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
    explicit checkbalance(QWidget *parent = nullptr);
    ~checkbalance();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::checkbalance *ui;
    newincome *n;
};

#endif // CHECKBALANCE_H
