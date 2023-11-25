#include "myprofile.h"
#include "ui_myprofile.h"

myprofile::myprofile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myprofile)
{
    ui->setupUi(this);
}

myprofile::~myprofile()
{
    delete ui;
}
