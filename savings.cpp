#include "savings.h"
#include "ui_savings.h"
#include"dashboard.h"
dashboard *dd;

savings::savings(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::savings)
{
    ui->setupUi(this);
}

savings::~savings()
{
    delete ui;
}

void savings::on_pushButton_clicked()
{
    hide();
    dd= new dashboard(this);
    dd->show();
}

