#include "logout.h"
#include "ui_logout.h"
#include"dashboard.h"
#include "mainwindow1.h"
MainWindow1 *m;
dashboard *s;

logout::logout(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::logout)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("SpendWise");
    setWindowIcon(QIcon(":/resources/logo.png"));
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


void logout::on_pushButton_2_clicked()
{
    hide();
    m=new MainWindow1();
    m->show();
}

