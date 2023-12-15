#include "editprofile.h"
#include "ui_editprofile.h"
#include "dashboard.h"
dashboard *g;

editprofile::editprofile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editprofile)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
}

editprofile::~editprofile()
{
    delete ui;
}

void editprofile::on_back_clicked()
{
    hide();
    g=new dashboard;
    g->show();
}

