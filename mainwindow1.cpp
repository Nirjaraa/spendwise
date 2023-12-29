#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include "mainwindow.h"
#include "linkin.h"
#include <userdata.h>
#include <QMessageBox>
linkin *l;

MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{       //MainWindow conn;

    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("SpendWise");
    setWindowIcon(QIcon(":/resources/logo.png"));

    ui->view->setCheckable(true);

}

MainWindow1::~MainWindow1()
{
    delete ui;
}

void MainWindow1::on_pushButton_clicked()
{
    hide();
    signinn =new signin(this);
    signinn->show();
}


void MainWindow1::on_login_clicked()
{
    QString userId = ui->uname->text();
    QString passwrd = ui->pw->text();

    if (!connOpen()) {
        qDebug()<<"Not connected to the database";
        return;  // Exit the function if not connected
    }

    QSqlQuery qry;
    qry.prepare("SELECT * FROM logininfoo WHERE username = '" + userId + "' AND pw = '" + passwrd + "'");

    if (qry.exec()) {
        while (qry.next()) {
            if(qry.value(0).toBool()){
                username=userId;
                hide();
                l = new linkin();
                l->show();

            }else if(!qry.value(0).toBool()){
                ui->error2->setText("Username and Password doesn't match!");
                ui->error1->setText("Username and Password doesn't match!");
            }
        }

    }

    connClose();
}


void MainWindow1::on_view_clicked(bool checked)
{
    if (checked) {
        ui->view->setStyleSheet("QPushButton{border-image: url(:/resources/eye-open.svg);background:transparent;}");
        ui->pw->setEchoMode(QLineEdit::Normal);
    }
    else{
        ui->view->setStyleSheet("QPushButton{border-image: url(:/resources/eye-closed.svg);background:transparent;}");
        ui->pw->setEchoMode(QLineEdit::Password);
    }

}

