#include "editprofile.h"
#include "ui_editprofile.h"
#include "dashboard.h"
#include<userdata.h>
#include <QMessageBox>
dashboard *g;

editprofile::editprofile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editprofile)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("SpendWise");
    setWindowIcon(QIcon(":/resources/logo.png"));

    connOpen();
    QSqlQuery fetch;
    fetch.prepare("SELECT * FROM logininfoo WHERE username='"+username+"'");
    QString initialusername, initialfname, initiallname, initialemail;
    fetch.exec();


    while(fetch.next())
    {
        initialfname=fetch.value(1).toString();
        initiallname=fetch.value(2).toString();
        initialusername=fetch.value(0).toString();
        initialemail=fetch.value(3).toString();

    }

    ui->uname->setText(initialusername);
    ui->fname->setText(initialfname);
    ui->lname->setText(initiallname);
    ui->email->setText(initialemail);
    ui->uname->setReadOnly(true);
    ui->uname->setEnabled(false);
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


void editprofile::on_pushButton_clicked()
{
    QString username = ui->uname->text();
    QString fname = ui->fname->text();
    QString lname = ui->lname->text();
    QString email = ui->email->text();

    connOpen();
    QSqlQuery update;
    update.prepare("UPDATE logininfoo SET fname = '" + fname + "', lname = '" + lname + "', email = '" + email + "' WHERE username = '" + username + "'");
    qDebug()<<"okayy"<<update.lastQuery();
    if (update.exec()) {
         QMessageBox::information(this, tr("Updated"), tr("Your profile has been updated"));
    } else {
        qDebug() << "Error updating record:" << update.lastError().text();
    }

    connClose();


}

