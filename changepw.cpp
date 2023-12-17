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
    QString cpemp = ui->current->text();
    QString npemp = ui->neww->text();
    QString cfnwemp = ui->re->text();

    if (!cpemp.isEmpty() && !npemp.isEmpty()) {
        connOpen();

        // Check if the current password is correct
        QSqlQuery qrycheck;
        qrycheck.prepare("SELECT * FROM logininfoo WHERE username = :username AND pw = :password");
        qrycheck.bindValue(":username", username);
        qrycheck.bindValue(":password", cpemp);

        if (qrycheck.exec() && qrycheck.next()) {
            // Current password is correct, proceed with password update
            if (npemp == cfnwemp) {
                QSqlQuery qrychange;
                qrychange.prepare("UPDATE logininfoo SET pw = :newPassword WHERE username = :username");
                qrychange.bindValue(":newPassword", cfnwemp);
                qrychange.bindValue(":username", username);

                if (qrychange.exec()) {
                    QMessageBox::critical(this, tr("Edit"), tr("Password Updated Successfully"));
                } else {
                    QMessageBox::critical(this, tr("ERROR!!!!"), qrychange.lastError().text());
                }
            } else {
                QMessageBox::information(this, "Mismatched", "New Password and Confirm New Password didn't match. Please check it again");
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

