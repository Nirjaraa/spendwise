#ifndef CASHAPP_H
#define CASHAPP_H

#include <QMainWindow>

namespace Ui {
class cashapp;
}

class cashapp : public QMainWindow
{
    Q_OBJECT

public:
    explicit cashapp(QWidget *parent = nullptr);
    ~cashapp();

private:
    Ui::cashapp *ui;
};

#endif // CASHAPP_H
