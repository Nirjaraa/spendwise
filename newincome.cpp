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
    setWindowTitle("SpendWise");
    setWindowIcon(QIcon(":/resources/logo.png"));

    connOpen();
    int initialincome=0;
    QSqlQuery fetch;
    fetch.prepare("SELECT * FROM income WHERE username='"+username+"'");  
    fetch.exec();

    while(fetch.next())
    {
        initialincome=fetch.value(0).toInt();
    }

    ui->currentincome->setText(QString::number(initialincome));
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
    int initialincome=0;

    if (incometext.isEmpty() || income == 0) {
        QMessageBox::critical(this, tr("Error"), tr("Please enter a valid non-zero integer for income"));
        return;
    }

    if (!connOpen()) {
        qDebug() << "Not Connected";
        return;
    }

    QSqlQuery insert,update,check;
    insert.prepare("INSERT INTO income (income,username) VALUES ('" + QString::number(income) + "', '" + username + "')");
     check.prepare("SELECT * FROM income WHERE username='"+username+"'");

    if(check.exec()){
        int count = 0;
        while (check.next()) {
            count++;
            initialincome=check.value(0).toInt();
            income=income+initialincome;
        }
        if(count >= 1)
        {
            if(update.exec("UPDATE income SET income='"+QString::number(income)+"' WHERE username='"+username+"'")){
                ui->currentincome->setText(QString::number(income));
                QMessageBox::information(this, tr("Updated"), tr("income updated"));
                ui->newincome_2->setText(QString::number(income=0));

                return;
            }
        }
        if(count == 0){
            if(insert.exec())
            {
                ui->currentincome->setText(QString::number(income));
                QMessageBox::information(this, tr("Added"), tr("Income added"));
                ui->newincome_2->setText(QString::number(income=0));

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

