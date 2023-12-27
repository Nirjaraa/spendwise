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
    setWindowTitle("SpendWise");
    setWindowIcon(QIcon(":/resources/logo.png"));

    connOpen();
    QSqlQuery fetchWater, fetchElectricity, fetchEducation, fetchFood, fetchOthers;
    int water= 0, electricity=0, education=0, food=0, others=0;

    if (fetchWater.exec("SELECT * FROM expenses WHERE username='" + username + "' and category='Water'")) {
        qDebug() << "Q1: " << fetchWater.lastQuery();
        while (fetchWater.next()) {
            water = fetchWater.value(0).toInt();
        }
    }

    if (fetchElectricity.exec("SELECT * FROM expenses WHERE username='" + username + "' and category='Electricity'")) {
        qDebug() << "Q2: " << fetchElectricity.lastQuery();
        while (fetchElectricity.next()) {
            electricity = fetchElectricity.value(0).toInt();
        }
    }

    if (fetchEducation.exec("SELECT * FROM expenses WHERE username='" + username + "' and category='Education'")) {
        qDebug() << "Q3: " << fetchEducation.lastQuery();
        while (fetchEducation.next()) {
            education = fetchEducation.value(0).toInt();
        }
    }

    if (fetchFood.exec("SELECT * FROM expenses WHERE username='" + username + "' and category='Food'")) {
        qDebug() << "Q4: " << fetchFood.lastQuery();
        while (fetchFood.next()) {
            food = fetchFood.value(0).toInt();
        }
    }

    if (fetchOthers.exec("SELECT * FROM expenses WHERE username='" + username + "' and category='Others'")) {
        qDebug() << "Q5: " << fetchOthers.lastQuery();
        while (fetchOthers.next()) {
            others = fetchOthers.value(0).toInt();
        }
    }


    ui->food->setText(QString::number(food));
    ui->electricity->setText(QString::number(electricity));
    ui->education->setText(QString::number(education));
    ui->water->setText(QString::number(water));
    ui->others->setText(QString::number(others));

    ui->food->setReadOnly(true);
    ui->food->setEnabled(false);
    ui->electricity->setEnabled(false);
    ui->education->setEnabled(false);
    ui->water->setEnabled(false);
    ui->others->setEnabled(false);
    ui->electricity->setReadOnly(true);
    ui->education->setReadOnly(true);
    ui->water->setReadOnly(true);
    ui->others->setReadOnly(true);

    connClose();
}

budget::~budget()
{
    delete ui;
}
void budget::on_back_clicked()
{
    hide();
    d=new dashboard(this);
    d->show();
}




