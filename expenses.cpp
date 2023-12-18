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

    if (!connOpen()) {
        qDebug() << "Not Connected";
        return;
    }

    QSqlQuery qry,qry1,qry2;
    qry.prepare("INSERT INTO expenses (expenses,username,category) VALUES ('" + QString::number(expenses) + "', '" + username + "','"+category+"')");
    qry1.prepare("UPDATE expenses SET expenses='"+QString::number(expenses)+"' WHERE username='"+username+"' AND category='"+category+"'");
    qry2.prepare("SELECT * FROM expenses WHERE username='"+username+"' AND category='"+category+"'");

     if(qry2.exec()){

        int count = 0;
        while (qry2.next()) {
            count++;
        }
        if(count >= 1)
        {
            if(qry1.exec()){

                QMessageBox::critical(this, tr("Updated"), tr("Expenses updated"));
                return;
            }
        }
        if(count == 0){

            if(qry.exec())
            {
                QMessageBox::information(this, tr("Added"), tr("Expenses added"));
                return;
            }
            else
            {
                QMessageBox::critical(this, tr("Error"), tr("Not Added"));
            }
        }
    }
    connClose();
}
void expenses::on_back_clicked()
{
    hide();
    h=new dashboard(this);
    h->show();
}
