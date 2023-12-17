#include "savings.h"
#include "ui_savings.h"
#include"dashboard.h"
dashboard *j;

savings::savings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::savings)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
}

savings::~savings()
{
    delete ui;
}

void savings::on_back_clicked()
{   hide();
    j= new dashboard(this);
    j->show();

}

