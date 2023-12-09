#include "financial.h"
#include "ui_financial.h"

financial::financial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::financial)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
}

financial::~financial()
{
    delete ui;
}
