#ifndef LOGOUT_H
#define LOGOUT_H

#include <QMainWindow>

namespace Ui {
class logout;
}

class logout : public QMainWindow
{
    Q_OBJECT

public:
    explicit logout(QWidget *parent = nullptr);
    ~logout();

private:
    Ui::logout *ui;
};

#endif // LOGOUT_H