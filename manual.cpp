#include "manual.h"
#include "ui_manual.h"

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
