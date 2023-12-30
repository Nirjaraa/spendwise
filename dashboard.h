#ifndef DASHBOARD_H
#define DASHBOARD_H
#include <QMainWindow>
#include "checkbalance.h"
#include "budget.h"
#include "expenses.h"
#include "savings.h"
#include"editprofile.h"
#include"changepw.h"
#include"manual.h"
#include"aboutus.h"
#include"logout.h"
#include"records.h"
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
namespace Ui {
class dashboard;
}

class dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent = nullptr);
    ~dashboard();
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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_4_clicked();

    void on_reset_clicked();

    void reload();

private:
    Ui::dashboard *ui;
    checkbalance *check;
    budget *bud;
    expenses *ex;
    savings *save;
    editprofile *neww;
    changepw *s;
    manual *m;
    aboutus *a;
    logout *l;
    records *r;



};

#endif // DASHBOARD_H
