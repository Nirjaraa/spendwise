#ifndef ESEWA_H
#define ESEWA_H

#include <QMainWindow>

namespace Ui {
class esewa;
}

class esewa : public QMainWindow
{
    Q_OBJECT

public:
    explicit esewa(QWidget *parent = nullptr);
    ~esewa();

private:
    Ui::esewa *ui;
};

#endif // ESEWA_H
