#ifndef SIGNIN_H
#define SIGNIN_H
#include "linkin.h"
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class signin;
}

class signin : public QMainWindow
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
    explicit signin(QWidget *parent = nullptr);
    ~signin();

private slots:
    void on_Signup_clicked();

private:
    Ui::signin *ui;
    linkin *l;
    bool isPasswordValid(const QString& password);


};

#endif // SIGNIN_H
