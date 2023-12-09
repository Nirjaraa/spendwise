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

