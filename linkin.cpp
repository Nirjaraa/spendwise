#include "linkin.h"
#include "ui_linkin.h"

linkin::linkin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::linkin)
{
    ui->setupUi(this);
}

linkin::~linkin()
{
    delete ui;
}

void linkin::on_pushButton_clicked()
{
    c=new dashboard();
    c ->show();
}

