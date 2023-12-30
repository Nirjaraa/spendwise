#ifndef RECORDS_H
#define RECORDS_H
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMainWindow>
#include <userdata.h>

namespace Ui {
class records;
}

class records : public QMainWindow
{
    Q_OBJECT

public:
    explicit records(QWidget *parent = nullptr);
    ~records();

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

private slots:
    void on_back_clicked();


private:
    Ui::records *ui;

};

#endif // RECORDS_H
