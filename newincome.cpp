#include "newincome.h"
#include "expenses.h"
#include "ui_newincome.h"
#include "checkbalance.h"
#include <userdata.h>
#include<QMessageBox>
QString username;
QSqlRecord userdata;
checkbalance *c;

newincome::newincome(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newincome)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
}

newincome::~newincome()
{
    delete ui;
}

void newincome::on_back_clicked()
{
    hide();
    c=new checkbalance();
    c->show();
}


void newincome::on_pushButton_8_clicked()
{
//    QString incometext = ui->newincome_2->text();
//    int income = incometext.toInt();  // Declare income directly

//    // Check if income is a valid integer
//    bool isIncomeInteger = true;  // Assuming it's true by default

//    if (incometext.isEmpty() || income == 0) {
//        isIncomeInteger = false;
//    }

//    if (!isIncomeInteger) {
//        QMessageBox::critical(this, tr("Error"), tr("Please enter a valid non-zero integer for income"));
//        return;
//    }

//    connOpen();

//    if (!connOpen()) {
//        qDebug() << "Not Connected";
//        return;
//    }

//    QSqlQuery qry;
//    qry.prepare("INSERT INTO income (income,username) VALUES ('" + QString::number(expenses) + "', '" + username + "')");
//    qry.bindValue(":income", income);

//    if (!qry.exec()) {
//        qDebug() << "Query failed to execute! Error: " << qry.lastError().text();
//        connClose();  // Close the connection before returning
//        return;
//    }

//    int count = qry.numRowsAffected();
//    if (count >= 1) {
//        qDebug() << "Data has been saved";
//        QMessageBox::information(this, tr("Save"), tr("Your data has been saved"));
//    } else {
//        ui->label_4->setText("Incorrect");
//    }

//    connClose();
//
}
