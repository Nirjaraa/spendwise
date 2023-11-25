#ifndef SIGNIN3_H
#define SIGNIN3_H

#include <QMainWindow>
#include "linkin.h"
namespace Ui {
class signin3;
}

class signin3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit signin3(QWidget *parent = nullptr);
    ~signin3();

private slots:
    void on_pushButton_clicked();

private:
    Ui::signin3 *ui;
    linkin *b;
};

#endif // SIGNIN3_H
