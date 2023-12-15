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
//    int expensesText = ui->enterexpenses->text();
//    expenses = expensesText.toInt();

//    // Check if expenses is a valid integer
//    bool isExpensesInteger = true;  // Assuming it's true by default

//    if (expensesText.isEmpty() || expensesText == 0) {
//        isExpensesInteger = false;
//    }

//    if (!isExpensesInteger) {
//        QMessageBox::critical(this, tr("Error"), tr("Please enter a valid non-zero integer for expenses"));
//        return;
//    }

//    connOpen();

//    if (!connOpen()) {
//        qDebug() << "Not Connected";
//        return;
//    }

//    QSqlQuery qry;
//    qry.prepare("INSERT INTO expenses (expenses) VALUES (:expenses)");
//    qry.bindValue(":expenses", expenses);

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


//}
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
    //qry.prepare("INSERT INTO expenses (expenses) VALUES ('"[expenses]+"')");
    qry.prepare("INSERT INTO expenses (expenses, username) VALUES ('" + QString::number(expenses) + "', '" + username + "')");


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



void expenses::on_update_clicked()
{}
//    void updateExpenses(int updatedExpenses)
//    {
//        // Check if updatedExpenses is a valid integer
//        bool isUpdatedExpensesInteger = true;  // Assuming it's true by default

//        if (updatedExpenses == 0) {
//            isUpdatedExpensesInteger = false;
//        }

//        if (!isUpdatedExpensesInteger) {
//            QMessageBox::critical(this, tr("Error"), tr("Please enter a valid non-zero integer for expenses"));
//            return;
//        }

//        connOpen();

//        if (!connOpen()) {
//            qDebug() << "Not Connected";
//            return;
//        }

//        QSqlQuery qry;
//        qry.prepare("UPDATE expenses SET expenses = :updatedExpenses WHERE your_condition_here");
//        qry.bindValue(":updatedExpenses", updatedExpenses);

//        if (!qry.exec()) {
//            qDebug() << "Query failed to execute! Error: " << qry.lastError().text();
//            connClose();  // Close the connection before returning
//            return;
//        }

//        int count = qry.numRowsAffected();
//        if (count >= 1) {
//            qDebug() << "Data has been updated";
//            QMessageBox::information(this, tr("Update"), tr("Your data has been updated"));
//        } else {
//            ui->label_4->setText("Incorrect");
//        }

//        connClose();
//    }


//}


void expenses::on_back_clicked()
{
    hide();
    h=new dashboard(this);
    h->show();
}

