#include "fonepay.h"
#include "ui_fonepay.h"

fonepay::fonepay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fonepay)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);

}

fonepay::~fonepay()
{
    delete ui;
}
