#ifndef FINANCIAL_H
#define FINANCIAL_H

#include <QMainWindow>

namespace Ui {
class financial;
}

class financial : public QMainWindow
{
    Q_OBJECT

public:
    explicit financial(QWidget *parent = nullptr);
    ~financial();

private:
    Ui::financial *ui;
};

#endif // FINANCIAL_H
