#ifndef MYPROFILE_H
#define MYPROFILE_H

#include <QMainWindow>

namespace Ui {
class myprofile;
}

class myprofile : public QMainWindow
{
    Q_OBJECT

public:
    explicit myprofile(QWidget *parent = nullptr);
    ~myprofile();

private slots:
    void on_pushButton_8_clicked();

private:
    Ui::myprofile *ui;
};

#endif // MYPROFILE_H
