#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include "checkbalance.h"

namespace Ui {
class dashboard;
}

class dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent = nullptr);
    ~dashboard();

private slots:
    void on_pushButton_clicked();

private:
    Ui::dashboard *ui;
    checkbalance *check;
};

#endif // DASHBOARD_H
