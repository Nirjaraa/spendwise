#include "aboutus.h"
#include "ui_aboutus.h"

aboutus::aboutus(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::aboutus)
{
    ui->setupUi(this);

}


aboutus::~aboutus()
{
    delete ui;
}
