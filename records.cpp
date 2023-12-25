#include "records.h"
#include "ui_records.h"
#include "dashboard.h"
dashboard *gg;

records::records(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::records)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);

}

records::~records()
{
    delete ui;
}



void records::on_back_clicked()
{
    hide();
    gg=new dashboard(this);
    gg->show();
}

