#ifndef ABOUTUS_H
#define ABOUTUS_H

#include <QMainWindow>

namespace Ui {
class aboutus;
}

class aboutus : public QMainWindow
{
    Q_OBJECT

public:
    explicit aboutus(QWidget *parent = nullptr);
    ~aboutus();

private:
    Ui::aboutus *ui;
};

#endif // ABOUTUS_H
