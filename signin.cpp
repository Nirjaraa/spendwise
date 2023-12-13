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

void signin::on_Signup_clicked()
{

        QString userId, passwrd,first,last,email;
        userId = ui->uname->text();
        passwrd= ui->pw->text();
        first= ui->firstname->text();
        last= ui->lastname->text();
        email= ui->emaill->text();

        // Check if any of the values is empty
        if (userId.isEmpty() || passwrd.isEmpty() || first.isEmpty() || last.isEmpty() || email.isEmpty()) {
            // Show an error message
            QMessageBox::critical(this, "Error", "Please fill in all the fields.");

            // Return from the function, preventing further execution
            return;
        }

        connOpen();
        if(!connOpen()){qDebug() << "Not Connected";}

        hide();
        l=new linkin(this);
        l->show();

        QSqlQuery qry;
        qry.prepare("insert into  logininfoo (username,pw,fname,lname,email ) values ('"+userId+"','"+passwrd+"','"+first+"','"+last+"','"+email+"')");

        if(qry.exec())  // executing querry in
        {
            qDebug() << "Heeel";
            int count=0;          //this will the count the number of time it executes the querry
            while(qry.next()){
                qDebug() << "Heeel";
                count++;
            }

            if(count>=1){
            qDebug() << "Heeel";
            QMessageBox::critical(this,tr("Save"),tr("Your data has been saved"));

            }

            if(count<1){
            ui->label_4->setText("incorrect");
            }
        }

        if (!qry.exec())
        {
            qDebug() << "Query failed to execute! Error: " << qry.lastError().text();
        }

        connClose();

}

