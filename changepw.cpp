#include "changepw.h"
#include "ui_changepw.h"

changepw::changepw(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::changepw)
{
    ui->setupUi(this);
}

changepw::~changepw()
{
    delete ui;
}
