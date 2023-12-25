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
void budget::on_back_clicked()
{
    hide();
    d=new dashboard(this);
    d->show();
}




