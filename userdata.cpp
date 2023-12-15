#include "userdata.h"
#include "ui_userdata.h"

userdata::userdata(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userdata)
{
    ui->setupUi(this);
}

userdata::~userdata()
{
    delete ui;
}
