#include "manual.h"
#include "ui_manual.h"

manual::manual(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manual)
{
    ui->setupUi(this);
}

manual::~manual()
{
    delete ui;
}
