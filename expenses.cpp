#include "expenses.h"
#include "ui_expenses.h"
#include "dashboard.h"
#include <userdata.h>
#include <QMessageBox>

QString username;
QSqlRecord userdata;

dashboard *h;

expenses::expenses(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::expenses)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
}

expenses::~expenses()
{
    delete ui;
}


void expenses::on_pushButton_7_clicked()
{

}

void expenses::on_save_clicked()
{
    QString expensesText = ui->enterexpenses->text();
    QString category = ui->comboBox->currentText();

    // Check if expensesText is a valid integer
    bool isExpensesInteger = true;  // Assuming it's true by default

    if (expensesText.isEmpty() || expensesText.toInt(&isExpensesInteger) == 0) {
        isExpensesInteger = false;
    }

    if (!isExpensesInteger) {
        QMessageBox::critical(this, tr("Error"), tr("Please enter a valid non-zero integer for expenses"));
        return;
    }

    // Now expensesText has been successfully converted to an integer
    int expenses = expensesText.toInt();

    connOpen();
    qDebug() << "a";


    if (!connOpen()) {
        qDebug() << "Not Connected";
        return;
    }

    QSqlQuery qry,qry1,qry2;
    //qry.prepare("INSERT INTO expenses (expenses) VALUES ('"[expenses]+"')");
    qry.prepare("INSERT INTO expenses (expenses,username,category) VALUES ('" + QString::number(expenses) + "', '" + username + "','"+category+"')");
    qry1.prepare("UPDATE expenses SET expenses='"+QString::number(expenses)+"' WHERE username='"+username+"' AND category='"+category+"')");
    qry2.prepare("SELECT * FROM expenses WHERE username="+username+"' AND category='"+category+"')");

    int count=1;
    qDebug() << "b";

    if(qry2.exec())
    {
        qDebug() << "10";

        qDebug() << "1"<<count;
        QMessageBox::information(this, tr("Error"), qry2.lastError().text());
        if(count)
        {
         qDebug() << "2";
        }
        if(qry1.exec()){
         qDebug()<<"3";

        }

        else {
        ui->label_4->setText("Incorrect");
        }
        QMessageBox::information(this, tr("Error"), qry2.lastError().text());
        connClose();  // Close the connection before returning
        return;
    }

    if (!qry.exec()) {
        qDebug() << "5";
        qDebug() << "Query failed to execute! Error: " << qry.lastError().text();

            return;
    }
        count = qry.numRowsAffected();







    qDebug() << "Prepared Query:" << qry.lastQuery();
    qDebug() << "Prepared Query:" << qry1.lastQuery();
    connClose();
}



void expenses::on_update_clicked()
{
    QString expensesText = ui->enterexpenses->text();

    // Check if expensesText is a valid integer
    bool isExpensesInteger = true;  // Assuming it's true by default

    if (expensesText.isEmpty() || expensesText.toInt(&isExpensesInteger) == 0) {
        isExpensesInteger = false;
    }

    if (!isExpensesInteger) {
        QMessageBox::critical(this, tr("Error"), tr("Please enter a valid non-zero integer for expenses"));
        return;
    }

    // Now expensesText has been successfully converted to an integer
    int expenses = expensesText.toInt();

    connOpen();

    if (!connOpen()) {
        qDebug() << "Not Connected";
        return;
    }

    QSqlQuery qry;
    qry.prepare("UPDATE expenses SET expenses='"+QString::number(expenses)+"' WHERE username='"+username+"'");


    qry.bindValue(":expenses", expenses);
    qDebug() << "Prepared Query:" << qry.lastQuery();
    qDebug() << "Bound Values:" << qry.boundValues();


    if (!qry.exec()) {
        qDebug() << "Query failed to execute! Error: " << qry.lastError().text();
        connClose();  // Close the connection before returning
        return;
    }

    int count = qry.numRowsAffected();
    if (count >= 1) {
        qDebug() << "Data has been saved";
        QMessageBox::information(this, tr("Save"), tr("Your data has been saved"));
    } else {
        ui->label_4->setText("Incorrect");
    }

    connClose();
}






void expenses::on_back_clicked()
{
    hide();
    h=new dashboard(this);
    h->show();
}

