#include "checkbalance.h"
#include "ui_checkbalance.h"

checkbalance::checkbalance(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::checkbalance)
{
    ui->setupUi(this);
}

checkbalance::~checkbalance()
{
    delete ui;
}
