#include "sign2.h"
#include "ui_sign2.h"

sign2::sign2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sign2)
{
    ui->setupUi(this);
}

sign2::~sign2()
{
    delete ui;
}

void sign2::on_pushButton_clicked()
{
    a=new signin3(this);
    a-> show();
}

