#ifndef NEWINCOME_H
#define NEWINCOME_H

#include <QMainWindow>


namespace Ui {
class newincome;
}

class newincome : public QMainWindow
{
    Q_OBJECT

public:
    explicit newincome(QWidget *parent = nullptr);
    ~newincome();

private slots:
    void on_pushButton_8_clicked();

private:
    Ui::newincome *ui;
};

#endif // NEWINCOME_H
