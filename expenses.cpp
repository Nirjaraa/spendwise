#include "expenses.h"
#include "ui_expenses.h"
#include "dashboard.h"
dashboard *h;

expenses::expenses(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::expenses)
{
    ui->setupUi(this);
}

expenses::~expenses()
{
    delete ui;
}


void expenses::on_pushButton_7_clicked()
{
    hide();
    h=new dashboard(this);
    h->show();
}
