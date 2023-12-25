#include "dashboard.h"
#include "ui_dashboard.h"
#include<QMessageBox>
#include <userdata.h>

dashboard::dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dashboard)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    connOpen();
    QSqlQuery fetch;
    fetch.prepare("SELECT * FROM logininfoo WHERE username='"+username+"'");
    QString   initialusername;


    while(fetch.next())
    {

        initialusername=fetch.value(0).toString();
    }

    ui->name->setText(initialusername);


    connClose();

}



dashboard::~dashboard()
{
    delete ui;
}

void dashboard::on_pushButton_clicked()
{       hide();
    check=new checkbalance();
    check->show();
}


void dashboard::on_pushButton_2_clicked()
{
    hide();
    bud=new budget();
    bud->show();
}


void dashboard::on_pushButton_3_clicked()
{
    hide();
    ex=new expenses();
    ex->show();
}


void dashboard::on_pushButton_5_clicked()
{
    hide();
    save=new savings();
    save->show();
}


void dashboard::on_pushButton_7_clicked()
{
    hide();
    neww= new editprofile();
    neww->show();

}


void dashboard::on_pushButton_8_clicked()
{
    hide();
    s=new changepw();
    s->show();

}


void dashboard::on_pushButton_10_clicked()
{
    hide();
    m=new manual();
    m->show();

}



void dashboard::on_pushButton_9_clicked()
{
    hide();
    a=new aboutus();
    a->show();

}



void dashboard::on_pushButton_11_clicked()
{
    hide();
    l=new logout();
    l->show();
}


void dashboard::on_pushButton_4_clicked()
{
    hide();
    r=new records();
    r->show();

}






