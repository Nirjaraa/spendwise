#ifndef SIGNIN_H
#define SIGNIN_H

#include <QMainWindow>
#include "sign2.h"
namespace Ui {
class signin;
}

class signin : public QMainWindow
{
    Q_OBJECT

public:
    explicit signin(QWidget *parent = nullptr);
    ~signin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::signin *ui;
    sign2 *signn2;

};

#endif // SIGNIN_H
