#ifndef EXPENSES_H
#define EXPENSES_H
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMainWindow>

namespace Ui {
class expenses;
}

class expenses : public QMainWindow
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
        logindb.setDatabaseName("C:/New Folder/spendwise/db/login.db");

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
    explicit expenses(QWidget *parent = nullptr);
    ~expenses();

private slots:
    void on_pushButton_7_clicked();

    void on_save_clicked();

    void on_update_clicked();

    void on_back_clicked();

private:
    Ui::expenses *ui;
};

#endif // EXPENSES_H
