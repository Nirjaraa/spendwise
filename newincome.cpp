#include "newincome.h"
#include "expenses.h"
#include "ui_newincome.h"
#include "checkbalance.h"
#include <userdata.h>
#include<QMessageBox>

checkbalance *c;

newincome::newincome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newincome)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    connOpen();
    QSqlQuery fetch;
    fetch.prepare("SELECT * FROM income WHERE username='"+username+"'");
    QString initialincome;
    fetch.exec();


    while(fetch.next())
    {
        initialincome=fetch.value(0).toString();

    }

    ui->newincome_2->setText(initialincome);


    connClose();

}




newincome::~newincome()
{
    delete ui;
}

void newincome::on_back_clicked()
{
    hide();
    c=new checkbalance();
    c->show();
}


void newincome::on_pushButton_8_clicked()
{
    QString incometext = ui->newincome_2->text();
    int income = incometext.toInt();

    if (incometext.isEmpty() || income == 0) {
        QMessageBox::critical(this, tr("Error"), tr("Please enter a valid non-zero integer for income"));
        return;
    }

    if (!connOpen()) {
        qDebug() << "Not Connected";
        return;
    }

    QSqlQuery qry,qry1,qry2;
    qry.prepare("INSERT INTO income (income,username) VALUES ('" + QString::number(income) + "', '" + username + "')");
    qry1.prepare("UPDATE income SET income='"+QString::number(income)+"' WHERE username='"+username+"'");
    qry2.prepare("SELECT * FROM income WHERE username='"+username+"'");

    if(qry2.exec()){

        int count = 0;
        while (qry2.next()) {
            count++;
        }
        if(count >= 1)
        {
            if(qry1.exec()){

                QMessageBox::information(this, tr("Updated"), tr("income updated"));
                return;
            }
        }
        if(count == 0){

            if(qry.exec())
            {
                QMessageBox::information(this, tr("Added"), tr("Income added"));
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

