#ifndef BUDGET_H
#define BUDGET_H

#include <QMainWindow>

namespace Ui {
class budget;
}

class budget : public QMainWindow
{
    Q_OBJECT

public:
    explicit budget(QWidget *parent = nullptr);
    ~budget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::budget *ui;

};

#endif // BUDGET_H
