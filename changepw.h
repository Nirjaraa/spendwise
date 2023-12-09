#ifndef CHANGEPW_H
#define CHANGEPW_H

#include <QMainWindow>

namespace Ui {
class changepw;
}

class changepw : public QMainWindow
{
    Q_OBJECT

public:
    explicit changepw(QWidget *parent = nullptr);
    ~changepw();

private:
    Ui::changepw *ui;
};

#endif // CHANGEPW_H
