#ifndef CHECKBALANCE_H
#define CHECKBALANCE_H

#include <QMainWindow>

namespace Ui {
class checkbalance;
}

class checkbalance : public QMainWindow
{
    Q_OBJECT

public:
    explicit checkbalance(QWidget *parent = nullptr);
    ~checkbalance();

private:
    Ui::checkbalance *ui;
};

#endif // CHECKBALANCE_H
