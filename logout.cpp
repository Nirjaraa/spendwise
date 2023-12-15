#include "logout.h"
#include "ui_logout.h"
#include"dashboard.h"
dashboard *s;

logout::logout(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::logout)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
}

logout::~logout()
{
    delete ui;
}

void logout::on_pushButton_clicked()
{
    hide();
    s=new dashboard();
    s->show();
}

