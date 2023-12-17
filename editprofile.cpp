#include "editprofile.h"
#include "ui_editprofile.h"
#include "dashboard.h"
#include<userdata.h>
dashboard *g;

editprofile::editprofile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editprofile)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    connOpen();
    QSqlQuery fetch;
    fetch.prepare("SELECT * FROM logininfoo WHERE username='"+username+"'");
    QString initialusername, initialfname, initiallname, initialemail;
    fetch.exec();


    while(fetch.next())
    {
        initialfname=fetch.value(0).toString();
        initiallname=fetch.value(1).toString();
        initialusername=fetch.value(2).toString();
        initialemail=fetch.value(3).toString();

    }

    ui->uname->setText(initialusername);
    ui->fname->setText(initialfname);
    ui->lname->setText(initiallname);
    ui->email->setText(initialemail);


    connClose();

}




editprofile::~editprofile()
{
    delete ui;
}

void editprofile::on_back_clicked()
{
    hide();
    g=new dashboard;
    g->show();
}

