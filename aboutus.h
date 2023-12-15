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

private slots:
    void on_back_clicked();

private:
    Ui::aboutus *ui;
};

#endif // ABOUTUS_H
