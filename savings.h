#ifndef SAVINGS_H
#define SAVINGS_H

#include <QMainWindow>

namespace Ui {
class savings;
}

class savings : public QMainWindow
{
    Q_OBJECT

public:
    explicit savings(QWidget *parent = nullptr);
    ~savings();

private slots:

private:
    Ui::savings *ui;
};

#endif // SAVINGS_H
