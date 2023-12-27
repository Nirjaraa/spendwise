#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include "mainwindow.h"
#include "linkin.h"
#include <userdata.h>
linkin *l;

MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{       //MainWindow conn;

    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("SpendWise");
    setWindowIcon(QIcon(":/resources/logo.png"));

}

MainWindow1::~MainWindow1()
{
    delete ui;
}

void MainWindow1::on_pushButton_clicked()
{
    hide();
    signinn =new signin(this);
    signinn->show();
}


void MainWindow1::on_login_clicked()
{
  //connection with database-----------------------------------------------------------------------------------------------

    qDebug() << "Hey";

    QString userId = ui->uname->text();
    QString passwrd = ui->pw->text();

    if (!connOpen()) {
        qDebug()<<"Not connected to the database";
        return;  // Exit the function if not connected
    }

    QSqlQuery qry;
    qry.prepare("SELECT * FROM logininfoo WHERE username = :userId AND pw = :passwrd");
    qry.bindValue(":userId", userId);
    qry.bindValue(":passwrd", passwrd);

    if (qry.exec()) {
        int count = 0;
        while (qry.next()) {
            count++;
            qDebug() << "1";
        }

        if (count == 1) {
            userdata=qry.record();
            username=userdata.value("username").toString();
            username=userId;
            hide();
            l = new linkin();
            l->show();
        } else {
            ui->error2->setText("Incorrect Password");
            ui->error1->setText("Incorrect Username");
        }
    } else {
        qDebug() << "Query failed to execute! Error: " << qry.lastError().text();
    }

    connClose();
}



