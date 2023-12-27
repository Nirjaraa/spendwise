#include "linkin.h"
#include "ui_linkin.h"

linkin::linkin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::linkin)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("SpendWise");
    setWindowIcon(QIcon(":/resources/logo.png"));
}

linkin::~linkin()
{
    delete ui;
}

void linkin::on_pushButton_clicked()
{   hide();
    c=new dashboard();
    c ->show();
}

