#ifndef LINKIN_H
#define LINKIN_H

#include <QMainWindow>
#include "dashboard.h"
namespace Ui {
class linkin;
}

class linkin : public QMainWindow
{
    Q_OBJECT

public:
    explicit linkin(QWidget *parent = nullptr);
    ~linkin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::linkin *ui;
    dashboard *c;
};

#endif // LINKIN_H
