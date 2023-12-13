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
    //QLabel *label1 = new QLabel(this);
    //label1->setText("");
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




void MainWindow::on_previous3_clicked()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() - 1);

}


void MainWindow::on_previous2_clicked()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() - 1);

}


void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() - 1);

}


void MainWindow::on_next4_clicked()
{
    hide();
    Mainwindow1=new MainWindow1(this);
    Mainwindow1->show();

}


void MainWindow::on_next3_clicked()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() + 1);

}


void MainWindow::on_next2_clicked()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() + 1);
}


void MainWindow::on_next1_clicked()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() + 1);
}

