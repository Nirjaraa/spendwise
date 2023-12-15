#include "signin.h"
#include "ui_signin.h"
#include<QMessageBox>
#include "mainwindow1.h"
MainWindow1 *mn;

signin::signin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
}

signin::~signin()
{
    delete ui;
}

void signin::on_Signup_clicked()
{
    QString userId, passwrd,first,last,email;
    userId = ui->uname->text();
    passwrd= ui->pw->text();
    first= ui->firstname->text();
    last= ui->lastname->text();
    email= ui->emaill->text();

    // Check if any of the values is empty
    if (userId.isEmpty() || passwrd.isEmpty() || first.isEmpty() || last.isEmpty() || email.isEmpty()) {
        // Show an error message
        QMessageBox::critical(this, "Error", "Please fill in all the fields.");

        // Return from the function, preventing further execution
        return;
    }

    connOpen();
    if(!connOpen()){qDebug() << "Not Connected";}

    hide();
    mn=new MainWindow1(this);
    mn->show();

    QSqlQuery qry;
    qry.prepare("INSERT INTO logininfoo (username, pw, fname, lname, email) VALUES (:userId, :passwrd, :first, :last, :email)");
    qry.bindValue(":userId", userId);
    qry.bindValue(":passwrd", passwrd);
    qry.bindValue(":first", first);
    qry.bindValue(":last", last);
    qry.bindValue(":email", email);

    if (qry.exec()) {
        int count = 0;
        while (qry.next()) {
            count++;
        }

        if (count >= 1) {
            qDebug() << "Data has been saved";
            QMessageBox::critical(this, tr("Save"), tr("Your data has been saved"));
        } else {
            ui->label_4->setText("Incorrect");
        }
    } else {
        qDebug() << "Query failed to execute! Error: " << qry.lastError().text();
    }

    connClose();

}
