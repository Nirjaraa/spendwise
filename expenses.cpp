#include "expenses.h"
#include "ui_expenses.h"
#include "dashboard.h"
#include <userdata.h>
#include <QMessageBox>

QString userId;
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
    hide();
    h=new dashboard(this);
    h->show();
}

void expenses::on_save_clicked()
{
    QString expensesText = ui->enterexpenses->text();
    expenses = expensesText.toInt();

    // Check if expenses is a valid integer
    bool isExpensesInteger = true;  // Assuming it's true by default

    if (expensesText.isEmpty() || expenses == 0) {
        isExpensesInteger = false;
    }

    if (!isExpensesInteger) {
        QMessageBox::critical(this, tr("Error"), tr("Please enter a valid non-zero integer for expenses"));
        return;
    }

    connOpen();

    if (!connOpen()) {
        qDebug() << "Not Connected";
        return;
    }

    QSqlQuery qry;
    qry.prepare("INSERT INTO expenses (expenses) VALUES (:expenses)");
    qry.bindValue(":expenses", expenses);

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

