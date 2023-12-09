#ifndef DASHBOARD_H
#define DASHBOARD_H
#include <QMainWindow>
#include "checkbalance.h"
#include "budget.h"
#include "expenses.h"
#include "savings.h"
#include"myprofile.h"
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

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::dashboard *ui;
    checkbalance *check;
    budget *bud;
    expenses *ex;
    savings *save;
    myprofile *neww;
};

#endif // DASHBOARD_H
