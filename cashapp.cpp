#include "cashapp.h"
#include "ui_cashapp.h"

cashapp::cashapp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cashapp)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);

}

cashapp::~cashapp()
{
    delete ui;
}
