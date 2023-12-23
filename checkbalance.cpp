#include "checkbalance.h"
#include "ui_checkbalance.h"
#include "dashboard.h"
dashboard *das;
checkbalance::checkbalance(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::checkbalance)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    connOpen();
    QSqlQuery savings,income,expenses;
    savings.prepare("SELECT * FROM savings WHERE username='"+username+"'");
    income.prepare("SELECT * FROM income WHERE username='"+username+"'");
    expenses.prepare("SELECT * FROM expenses WHERE username='"+username+"'");

    QString currentsavings,currentincome;
    int initialmoneyspent,moneyspent,available,currentbalance;

    savings.exec();
    while(savings.next())
    {
        currentsavings=savings.value(0).toString();
    }

    income.exec();
    while(income.next())
    {
        currentincome=income.value(0).toString();
    }

    expenses.exec();
    while(expenses.next())
    {
        initialmoneyspent=expenses.value(0).toInt();
        moneyspent=moneyspent+initialmoneyspent;
    }

    available=currentincome.toInt()-moneyspent-currentsavings.toInt();
    currentbalance=currentincome.toInt()-moneyspent;

    ui->currentbalance->setText( QString::number(currentbalance));
    ui->currentsavings->setText(currentsavings);
    ui->moneyspent->setText( QString::number(moneyspent));
    ui->availablebalance->setText( QString::number(available));
    connClose();

}

checkbalance::~checkbalance()
{
    delete ui;
}

void checkbalance::on_pushButton_clicked()
{
    hide();
    das=new dashboard(this);
    das->show();
}


void checkbalance::on_pushButton_8_clicked()
{   hide();
    n=new newincome();
    n->show();
}

