#include "mainwindow1.h"
#include "ui_mainwindow1.h"

MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{
    ui->setupUi(this);
}

MainWindow1::~MainWindow1()
{
    delete ui;
}

void MainWindow1::on_pushButton_clicked()
{

    signinn =new signin(this);
    signinn->show();
}


void MainWindow1::on_pushButton_2_clicked()
{
    d=new dashboard();
    d->show();
}

