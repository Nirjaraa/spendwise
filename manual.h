#ifndef MANUAL_H
#define MANUAL_H

#include <QMainWindow>

namespace Ui {
class manual;
}

class manual : public QMainWindow
{
    Q_OBJECT

public:
    explicit manual(QWidget *parent = nullptr);
    ~manual();

private:
    Ui::manual *ui;
};

#endif // MANUAL_H
