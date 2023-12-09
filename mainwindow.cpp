#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLabel"
#include "mainwindow1.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    QLabel *label1 = new QLabel(this);
    label1->setText("");
//    label1->setGeometry(QRectF(340,100,30,80));


}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked()
{     hide();
    Mainwindow1=new MainWindow1(this);
    Mainwindow1->show();
}



