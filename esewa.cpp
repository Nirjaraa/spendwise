#include "esewa.h"
#include "ui_esewa.h"

esewa::esewa(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::esewa)
{
    ui->setupUi(this);
}

esewa::~esewa()
{
    delete ui;
}
