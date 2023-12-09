#include "logout.h"
#include "ui_logout.h"

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
