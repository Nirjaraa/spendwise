#include "manual.h"
#include "ui_manual.h"
#include "dashboard.h"
dashboard *dd;

manual::manual(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manual)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
}

manual::~manual()
{
    delete ui;
}

void manual::on_back_clicked()
{
    hide();
    dd=new dashboard();
    dd->show();

}

