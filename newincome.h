#ifndef NEWINCOME_H
#define NEWINCOME_H
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMainWindow>


namespace Ui {
class newincome;
}

class newincome : public QMainWindow
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
    explicit newincome(QWidget *parent = nullptr);
    ~newincome();

private slots:

    void on_back_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::newincome *ui;
};

#endif // NEWINCOME_H
