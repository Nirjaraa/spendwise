#include "dashboard.h"
#include "ui_dashboard.h"
#include<QMessageBox>
#include <userdata.h>

dashboard::dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dashboard)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("SpendWise");
    setWindowIcon(QIcon(":/resources/logo.png"));

    connOpen();
    QSqlQuery fetch;
    fetch.prepare("SELECT * FROM logininfoo WHERE username='"+username+"'");
    QString initialusername;
    if(fetch.exec()){
        while(fetch.next())
        {
            initialusername=fetch.value(0).toString();
        }
    }
    ui->name->setText(initialusername);
    connClose();
}

void dashboard::on_reset_clicked()
{
    connOpen();

    int initialexpense=0,currentexpense=0,currentsavings=0,currentincome=0,extrasavings=0;
    QSqlQuery savings,income,expenses,records,deleteSavings,deleteIncome,deleteExpenses;

    savings.prepare("SELECT * FROM savings WHERE username='"+username+"'");
    income.prepare("SELECT * FROM income WHERE username='"+username+"'");
    expenses.prepare("SELECT * FROM expenses WHERE username='"+username+"'");

    deleteSavings.prepare("DELETE FROM savings WHERE username='"+username+"'");
    deleteIncome.prepare("DELETE FROM income WHERE username='"+username+"'");
    deleteExpenses.prepare("DELETE FROM expenses WHERE username='"+username+"'");

    savings.exec();
    income.exec();
    expenses.exec();

    while(savings.next())
    {
        currentsavings=savings.value(0).toInt();
    }
    while(income.next())
    {
        currentincome=income.value(0).toInt();
    }
    while(expenses.next())
    {
        initialexpense=expenses.value(0).toInt();
        currentexpense=currentexpense+initialexpense;
    }

    extrasavings = currentincome-currentsavings-currentexpense;
    records.prepare("INSERT INTO records (username, expenses, savings, income, extra) VALUES ('" + username + "', " + QString::number(currentexpense) + ", " + QString::number(currentsavings) + ", " + QString::number(currentincome) + ", " + QString::number(extrasavings) + ")");

    QMessageBox confirmationBox;
    confirmationBox.setIcon(QMessageBox::Question);
    confirmationBox.setWindowTitle("Confirmation");
    confirmationBox.setText("Are you sure you want to reset?");

    // Add buttons to the QMessageBox
    confirmationBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    confirmationBox.setDefaultButton(QMessageBox::No);
    int buttonPressed = confirmationBox.exec();

    if (buttonPressed == QMessageBox::Yes) {
        if(records.exec())
        {
            deleteSavings.exec();
            deleteIncome.exec();
            deleteExpenses.exec();
        }
    }
    else if (buttonPressed == QMessageBox::No) {
        return;
    }
    connClose();
}


dashboard::~dashboard()
{
    delete ui;
}

void dashboard::on_pushButton_clicked()
{       hide();
    check=new checkbalance();
    check->show();
}

void dashboard::on_pushButton_2_clicked()
{
    hide();
    bud=new budget();
    bud->show();
}

void dashboard::on_pushButton_3_clicked()
{
    hide();
    ex=new expenses();
    ex->show();
}

void dashboard::on_pushButton_5_clicked()
{
    hide();
    save=new savings();
    save->show();
}

void dashboard::on_pushButton_7_clicked()
{
    hide();
    neww= new editprofile();
    neww->show();

}

void dashboard::on_pushButton_8_clicked()
{
    hide();
    s=new changepw();
    s->show();

}

void dashboard::on_pushButton_10_clicked()
{
    hide();
    m=new manual();
    m->show();

}

void dashboard::on_pushButton_9_clicked()
{
    hide();
    a=new aboutus();
    a->show();

}

void dashboard::on_pushButton_11_clicked()
{
    hide();
    l=new logout();
    l->show();
}

void dashboard::on_pushButton_4_clicked()
{
    hide();
    r=new records();
    r->show();

}



