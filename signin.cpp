#include "signin.h"
#include "ui_signin.h"

signin::signin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);
}

signin::~signin()
{
    delete ui;
}

void signin::on_pushButton_clicked()
{

    signn2 = new sign2(this);
    signn2->show();
}


