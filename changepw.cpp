#include "changepw.h"
#include "ui_changepw.h"
#include "dashboard.h"
#include<QMessageBox>
#include<userdata.h>
dashboard *t;

changepw::changepw(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::changepw)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("SpendWise");
    setWindowIcon(QIcon(":/resources/logo.png"));
     ui->view1->setCheckable(true);
     ui->view2->setCheckable(true);
     ui->view3->setCheckable(true);
}

changepw::~changepw()
{
    delete ui;
}

void changepw::on_back_clicked()
{
    hide();
    t=new dashboard();
    t->show();
}


void changepw::on_save_2_clicked()
{
    QString currentPassword = ui->current->text();
    QString newPassword = ui->neww->text();
    QString rePassword = ui->re->text();

    if (!currentPassword.isEmpty() && !newPassword.isEmpty()) {
        connOpen();

        // Check if the current password is correct
        QSqlQuery qrycheck;
        qrycheck.prepare("SELECT * FROM logininfoo WHERE username = :username AND pw = :password");
        qrycheck.bindValue(":username", username);
        qrycheck.bindValue(":password", currentPassword);

        if(newPassword.length() <= 8 && !newPassword.contains("[!@#$%^&*(),.?\":{}|<>]")){
            QMessageBox::critical(this, "Error", "Please enter a valid password");
            return;
        }

        if (qrycheck.exec() && qrycheck.next()) {
            // Current password is correct, proceed with password update
            if (newPassword == rePassword) {
                QSqlQuery qrychange;
                qrychange.prepare("UPDATE logininfoo SET pw = :newPassword WHERE username = :username");
                qrychange.bindValue(":newPassword", rePassword);
                qrychange.bindValue(":username", username);

                if (qrychange.exec()) {
                    QMessageBox::information(this, tr("updated!"), tr("Password Updated Successfully"));
                } else {
                    QMessageBox::critical(this, tr("ERROR!!!!"), qrychange.lastError().text());
                }
            } else {
                QMessageBox::critical(this, "Mismatched", "New Password and Confirm New Password didn't match. Please check it again");
            }
        } else {
            // Current password is incorrect
            QMessageBox::critical(this, tr("Incorrect Password"), tr("The entered current password is incorrect."));
        }

        connClose();
    } else {
        QMessageBox::information(this, "Empty Field", "Please fill the required fields!!");
    }
}



void changepw::on_view1_clicked(bool checked)
{
    if (checked) {
        ui->view1->setStyleSheet("QPushButton{border-image: url(:/resources/eye-open.svg);background:transparent;}");
        ui->current->setEchoMode(QLineEdit::Normal);
    }
    else{
        ui->view1->setStyleSheet("QPushButton{border-image: url(:/resources/eye-closed.svg);background:transparent;}");
        ui->current->setEchoMode(QLineEdit::Password);
    }
}



void changepw::on_view2_clicked(bool checked)
{
    if (checked) {
        ui->view2->setStyleSheet("QPushButton{border-image: url(:/resources/eye-open.svg);background:transparent;}");
        ui->neww->setEchoMode(QLineEdit::Normal);
    }
    else{
        ui->view2->setStyleSheet("QPushButton{border-image: url(:/resources/eye-closed.svg);background:transparent;}");
        ui->neww->setEchoMode(QLineEdit::Password);
    }
}


void changepw::on_view3_clicked(bool checked)
{
    if (checked) {
        ui->view3->setStyleSheet("QPushButton{border-image: url(:/resources/eye-open.svg);background:transparent;}");
        ui->re->setEchoMode(QLineEdit::Normal);
    }
    else{
        ui->view3->setStyleSheet("QPushButton{border-image: url(:/resources/eye-closed.svg);background:transparent;}");
        ui->re->setEchoMode(QLineEdit::Password);
    }
}

