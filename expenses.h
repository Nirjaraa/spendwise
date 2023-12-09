#ifndef EXPENSES_H
#define EXPENSES_H

#include <QMainWindow>

namespace Ui {
class expenses;
}

class expenses : public QMainWindow
{
    Q_OBJECT

public:
    explicit expenses(QWidget *parent = nullptr);
    ~expenses();

private slots:
    void on_pushButton_7_clicked();

private:
    Ui::expenses *ui;
};

#endif // EXPENSES_H
