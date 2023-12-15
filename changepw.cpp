#include "changepw.h"
#include "ui_changepw.h"
#include "dashboard.h"
dashboard *t;

changepw::changepw(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::changepw)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
}

changepw::~changepw()
{
    delete ui;
}

void changepw::on_back_clicked()
{
    hide();
    t=new dashboard();
    t->show();
}

