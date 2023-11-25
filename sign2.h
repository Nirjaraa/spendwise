#ifndef SIGN2_H
#define SIGN2_H

#include <QMainWindow>
#include "signin3.h"

namespace Ui {
class sign2;
}

class sign2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit sign2(QWidget *parent = nullptr);
    ~sign2();

private slots:
    void on_pushButton_clicked();

private:
     Ui::sign2 *ui;
    signin3 *a;
};

#endif // SIGN2_H
