#include "myprofile.h"
#include "ui_myprofile.h"

myprofile::myprofile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myprofile)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
}

myprofile::~myprofile()
{
    delete ui;
}

void myprofile::on_pushButton_8_clicked()
{

}

