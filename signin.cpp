#include "signin.h"
#include "ui_signin.h"
#include<QMessageBox>

signin::signin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
}

signin::~signin()
{
    delete ui;
}



        //connection with database-----------------------------------------------------------------------------------------------

void signin::on_Signup_clicked()
{

        QString userId, passwrd,first,last,email;
        userId = ui->uname->text();
        passwrd= ui->pw->text();
        first= ui->firstname->text();
        last= ui->lastname->text();
        email= ui->emaill->text();

        if(!connOpen())
        {
            ui->label_4->setText("Not connected to database");
                //add a fucntion to end the application
        }
        connOpen();

        QSqlQuery qry;
         qry.prepare("insert into  logininfoo (username,pw,fname,lname,email ) values ('"+userId+"','"+passwrd+"','"+first+"','"+last+"','"+email+"')");
        if(qry.exec())  // executing querry in
        {
        int count=0;          //this will the count the number of time it executes the querry
            while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            QMessageBox::critical(this,tr("Save"),tr("Your data has been saved"));
            hide();
            l=new linkin(this);
            l->show();
        }

        if(count<1)
        {
            ui->label_4->setText("incorrect");
        }
        connClose();







}
}

