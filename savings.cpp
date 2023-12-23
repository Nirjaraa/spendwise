#include "savings.h"
#include "ui_savings.h"
#include"dashboard.h"
#include<QMessageBox>
#include <userdata.h>
dashboard *j;

savings::savings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::savings)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    connOpen();
    QSqlQuery fetch;
    fetch.prepare("SELECT * FROM savings WHERE username='"+username+"'");
    QString initialsavings;
    fetch.exec();


    while(fetch.next())
    {
        initialsavings=fetch.value(0).toString();

    }

    ui->savings_2->setText(initialsavings);

    connClose();
}

savings::~savings()
{
    delete ui;
}

void savings::on_back_clicked()
{   hide();
    j= new dashboard(this);
    j->show();

}


void savings::on_save_clicked()
{



    QString savingtext = ui->savings_2->text();
    bool areFieldsInteger = true;  // Assuming it's true by default


    if (savingtext.isEmpty()) {
        areFieldsInteger = false;
    }

    if (!areFieldsInteger) {
        QMessageBox::critical(this, tr("Error"), tr("Please enter valid non-zero integers for all fields"));
        return;
    }

    // Now you can convert the fields to integers if needed
    int savings = savingtext.toInt();
    // Perform further operations with the obtained integer values


    connOpen();

    if (!connOpen()) {
        qDebug() << "Not Connected";
        return;
    }

    QSqlQuery qry,qry1,qry2;
    qry.prepare("INSERT INTO savings (username,savings) VALUES ('"+username + "','" + QString::number(savings) +"')");
    qry1.prepare("UPDATE savings SET savings = '" + QString::number(savings) + "'");

    qry2.prepare("SELECT * FROM savings WHERE username='"+username+"'");

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

                QMessageBox::information(this, tr("Updated"), tr("Savings  updated"));
                return;
            }
        }
        if(count == 0){

            if(qry.exec())
            {
                QMessageBox::information(this, tr("Added"), tr("Savings added"));
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
