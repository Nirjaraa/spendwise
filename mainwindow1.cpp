#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include "mainwindow.h"
#include "linkin.h"


/*QString userId;
QSqlRecord userdata*/;
linkin *l;
MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{       //MainWindow conn;

    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);

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
  //connection with database-----------------------------------------------------------------------------------------------

    qDebug() << "Hey";

    QString userId = ui->uname->text();
    QString passwrd = ui->pw->text();

    if (!connOpen()) {
        ui->label_4->setText("Not connected to the database");
        return;  // Exit the function if not connected
    }

    QSqlQuery qry;
    qry.prepare("SELECT * FROM logininfoo WHERE username = :userId AND pw = :passwrd");
    qry.bindValue(":userId", userId);
    qry.bindValue(":passwrd", passwrd);

    if (qry.exec()) {
        int count = 0;
        while (qry.next()) {
            count++;
            qDebug() << "1";
        }

        if (count == 1) {
            ui->label_4->setText("Username and password are correct");
            hide();
            l = new linkin();
            l->show();
        } else {
            ui->label_4->setText("Incorrect username or password");
        }
    } else {
        qDebug() << "Query failed to execute! Error: " << qry.lastError().text();
    }

    connClose();
}



