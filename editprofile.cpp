#include "editprofile.h"
#include "ui_editprofile.h"

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
