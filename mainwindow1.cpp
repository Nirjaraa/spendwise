#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include "mainwindow.h"

MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{       //MainWindow conn;

    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    if(!connOpen())
        ui->label_8->setText("Failed to open the databse");
    else
        ui->label_8->setText("Connected");

}

MainWindow1::~MainWindow1()
{
    delete ui;
}

void MainWindow1::on_pushButton_clicked()
{

    signinn =new signin(this);
    signinn->show();
}


void MainWindow1::on_pushButton_2_clicked()
{/*
*/
  //connection with database-----------------------------------------------------------------------------------------------

   // MainWindow conn;
    QString userId, passwrd;
    userId = ui->uname->text();
    passwrd= ui->pw->text();

    if(!connOpen())
    {
         ui->label_8->setText("Not connected to database");
            //add a fucntion to end the application
    }
    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from logininfoo where username='"+userId+"' and password='"+passwrd+"'");

    if(qry.exec()) // executing querry in
    {
        int count=0;          //this will the count the number of time it executes the querry
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            ui->label_8->setText("username and pw correct");
            connClose();
            hide();
            d=new dashboard();
            d->show();
        }

        if(count<1)
        {
            ui->label_8->setText("Username or password is not correct");
        }

    }



}









