#ifndef SAVINGS_H
#define SAVINGS_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <userdata.h>


namespace Ui {
class savings;
}

class savings : public QMainWindow
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
    explicit savings(QWidget *parent = nullptr);
    ~savings();

private slots:

    void on_back_clicked();

    void on_save_clicked();

private:
    Ui::savings *ui;
};

#endif // SAVINGS_H
