#ifndef CHECKBALANCE_H
#define CHECKBALANCE_H

#include <QMainWindow>
#include"newincome.h"

namespace Ui {
class checkbalance;
}

class checkbalance : public QMainWindow
{
    Q_OBJECT

public:
    explicit checkbalance(QWidget *parent = nullptr);
    ~checkbalance();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::checkbalance *ui;
    newincome *n;
};

#endif // CHECKBALANCE_H
