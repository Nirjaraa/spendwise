#include "newincome.h"
#include "ui_newincome.h"
#include "checkbalance.h"
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

void newincome::on_pushButton_8_clicked()
{   hide();
    c=new checkbalance();
    c->show();

}

