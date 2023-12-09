#include "budget.h"
#include "ui_budget.h"
#include "dashboard.h"
dashboard *d;
budget::budget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::budget)
{
    ui->setupUi(this);
}

budget::~budget()
{
    delete ui;
}

void budget::on_pushButton_clicked()
{       hide();
    d=new dashboard(this);
    d->show();
}


