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
    setWindowTitle("SpendWise");
    setWindowIcon(QIcon(":/resources/logo.png"));

    connOpen();
    QSqlQuery savings,income,expenses;
    savings.prepare("SELECT * FROM savings WHERE username='"+username+"'");
    income.prepare("SELECT * FROM income WHERE username='"+username+"'");
    expenses.prepare("SELECT * FROM expenses WHERE username='"+username+"'");

    QString currentsavings,currentincome;
    int initialmoneyspent = 0,moneyspent=0,available=0,currentbalance=0;

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

    qDebug()<<"InMon1"<<initialmoneyspent;
    qDebug()<<"Mon1"<<moneyspent;
    available=currentincome.toInt()-moneyspent-currentsavings.toInt();
    currentbalance=currentincome.toInt()-moneyspent;

    ui->currentbalance->setText( QString::number(currentbalance));
    ui->currentsavings->setText(currentsavings);
    ui->moneyspent->setText( QString::number(moneyspent));
    ui->availablebalance->setText( QString::number(available));
    ui->income->setText(currentincome);

    ui->currentbalance->setReadOnly(true);
    ui->currentbalance->setEnabled(false);
    ui->currentsavings->setReadOnly(true);
    ui->currentsavings->setEnabled(false);
    ui->moneyspent->setReadOnly(true);
    ui->moneyspent->setEnabled(false);
    ui->availablebalance->setReadOnly(true);
    ui->availablebalance->setEnabled(false);
    ui->income->setReadOnly(true);
    ui->income->setEnabled(false);

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

