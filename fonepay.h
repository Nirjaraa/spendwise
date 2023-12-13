#ifndef FONEPAY_H
#define FONEPAY_H

#include <QMainWindow>

namespace Ui {
class fonepay;
}

class fonepay : public QMainWindow
{
    Q_OBJECT

public:
    explicit fonepay(QWidget *parent = nullptr);
    ~fonepay();

private:
    Ui::fonepay *ui;
};

#endif // FONEPAY_H
