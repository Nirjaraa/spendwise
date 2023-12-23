#include "budget.h"
#include "ui_budget.h"
#include "dashboard.h"
#include<QMessageBox>
#include <userdata.h>
dashboard *d;
budget::budget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::budget)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    connOpen();
     QSqlQuery fetch;
    fetch.prepare("SELECT * FROM budget WHERE username='"+username+"'");
     QString initialwater, initialelectricity, initialeducation, initialfood, initialothers;
    fetch.exec();


     while(fetch.next())
    {
           initialwater=fetch.value(0).toString();
           initialelectricity=fetch.value(1).toString();
           initialeducation=fetch.value(2).toString();
           initialfood=fetch.value(3).toString();
           initialothers=fetch.value(4).toString();

    }

     ui->food->setText(initialfood);
     ui->electricity->setText(initialelectricity);
     ui->education->setText(initialeducation);
     ui->water->setText(initialwater);
     ui->others->setText(initialothers);

    connClose();

}

budget::~budget()
{
    delete ui;
}

//void budget::on_pushButton_clicked()
//{   hide();
//    d=new dashboard(this);
//    d->show();
//}



void budget::on_back_clicked()
{
    hide();
    d=new dashboard(this);
    d->show();
}


void budget::on_pushButton_clicked()
{
     QString foodText = ui->food->text();
     QString electricityText = ui->electricity->text();
     QString educationText = ui->education->text();
     QString waterText = ui->water->text();
     QString othersText = ui->others->text();
     bool areFieldsInteger = true;  // Assuming it's true by default


     if (foodText.isEmpty() && electricityText.isEmpty() && educationText.isEmpty() && waterText.isEmpty() && othersText.isEmpty() ) {
         areFieldsInteger = false;
     }

     if (!areFieldsInteger) {
         QMessageBox::critical(this, tr("Error"), tr("Please enter valid non-zero integers for all fields"));
         return;
     }

     // Now you can convert the fields to integers if needed
     int food = foodText.toInt();
     int education = educationText.toInt();
     int others = othersText.toInt();
     int electricity = electricityText.toInt();
     int water = waterText.toInt();

     // Perform further operations with the obtained integer values


     connOpen();

     if (!connOpen()) {
         qDebug() << "Not Connected";
         return;
     }

     QSqlQuery qry,qry1,qry2;
     qry.prepare("INSERT INTO budget (food, username, electricity, education, water, others) VALUES ('" + QString::number(food)+ "','" + username + "','" + QString::number(electricity) + "','" + QString::number(education) + "','" + QString::number(water) + "','" + QString::number(others) + "')");
     qry1.prepare("UPDATE budget SET food='" + QString::number(food) + "', electricity='" + QString::number(electricity) + "', education='" + QString::number(education) + "', water='" + QString::number(water) + "', others='" + QString::number(others) + "' WHERE username='" + username + "'");

     qry2.prepare("SELECT * FROM budget WHERE username='"+username+"'");

     qDebug() << "Executed query 1: " << qry1.lastQuery();
     qDebug() << "Executed query 2: " << qry2.lastQuery();
     qDebug() << "Executed query: " << qry.lastQuery();


     if(qry2.exec()){

         int count = 0;
         while (qry2.next()) {
             count++;
         }
         if(count >= 1)
         {
             if(qry1.exec()){

                 QMessageBox::information(this, tr("Updated"), tr("Budget  updated"));
                 return;
             }
         }
         if(count == 0){

             if(qry.exec())
             {
                 QMessageBox::information(this, tr("Added"), tr("Budget added"));
                 return;
             }
             else
             {
                 QMessageBox::critical(this, tr("Error"), tr("Not Added"));
             }
         }
     }
     connClose();

}



