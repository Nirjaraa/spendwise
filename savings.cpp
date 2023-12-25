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
    QString initialsavings;
    QSqlQuery fetch;

    fetch.prepare("SELECT * FROM savings WHERE username='"+username+"'");
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

    connOpen();

    if (!connOpen()) {
        qDebug() << "Not Connected";
        return;
    }

    int currentincome;
    int savings = savingtext.toInt();
    QSqlQuery addSavings,updateSavings,checkSavings,getIncome;

    addSavings.prepare("INSERT INTO savings (username,savings) VALUES ('"+username + "','" + QString::number(savings) +"')");
    updateSavings.prepare("UPDATE savings SET savings = '" + QString::number(savings) + "'");
    checkSavings.prepare("SELECT * FROM savings WHERE username='"+username+"'");
    getIncome.prepare("SELECT * FROM income WHERE username='"+username+"'");

    qDebug() << "Executed query 1: " << updateSavings.lastQuery();
    qDebug() << "Executed query 2: " << checkSavings.lastQuery();
    qDebug() << "Executed query: " << addSavings.lastQuery();

    if (getIncome.exec()){
        int count = 0;
        while(getIncome.next()){
            currentincome = getIncome.value(0).toInt();
            count++;
        }
        if(count == 0)
        {
            QMessageBox::critical(this, tr("Error"), tr("No Income Added"));
            return;
        }
    }

    if(checkSavings.exec())
    {
        int count = 0;
        while (checkSavings.next()) {
            count++;
        }

        if(count >= 1)
        {
            qDebug() << "Income " << currentincome;
            if (currentincome < savings) {
                QMessageBox::critical(this, tr("Error"), tr("Income is less than savings. Cannot update."));
                return;
            }
            else{
                if(updateSavings.exec()){
                    QMessageBox::information(this, tr("Updated"), tr("Savings  updated"));
                    return;
                }
            }
        }

        if(count == 0)
        {
            if (currentincome < savings) {
                QMessageBox::critical(this, tr("Error"), tr("Income is less than savings. Cannot update."));
                return;
            }
            else if(addSavings.exec()){
                QMessageBox::information(this, tr("Added"), tr("Savings added"));
                return;
            }
            else{
                QMessageBox::critical(this, tr("Error"), tr("Not Added"));
            }
        }
        connClose();
    }
}
