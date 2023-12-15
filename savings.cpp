#include "savings.h"
#include "ui_savings.h"
#include"dashboard.h"
//dashboard *dd;

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

//void savings::on_pushButton_clicked()
//{

//    dd= new dashboard(this);
//    dd->show();
//    hide();
//}

