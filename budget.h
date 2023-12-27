#ifndef BUDGET_H
#define BUDGET_H
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <userdata.h>



namespace Ui {
class budget;
}

class budget : public QMainWindow
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
    explicit budget(QWidget *parent = nullptr);
    ~budget();

private slots:


    void on_back_clicked();


private:
    Ui::budget *ui;

};

#endif // BUDGET_H
