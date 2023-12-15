#include "aboutus.h"
#include "ui_aboutus.h"
#include "dashboard.h"
dashboard *f;

aboutus::aboutus(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::aboutus)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);

}


aboutus::~aboutus()
{
    delete ui;
}

void aboutus::on_back_clicked()
{
    hide();
    f=new dashboard();
    f->show();
}

