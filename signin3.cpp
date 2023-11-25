#include "signin3.h"
#include "ui_signin3.h"

signin3::signin3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signin3)
{
    ui->setupUi(this);
}

signin3::~signin3()
{
    delete ui;
}

void signin3::on_pushButton_clicked()
{
    b=new linkin;
    b ->show();
}

