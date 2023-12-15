#ifndef EDITPROFILE_H
#define EDITPROFILE_H

#include <QMainWindow>

namespace Ui {
class editprofile;
}

class editprofile : public QMainWindow
{
    Q_OBJECT

public:
    explicit editprofile(QWidget *parent = nullptr);
    ~editprofile();

private slots:
    void on_back_clicked();

private:
    Ui::editprofile *ui;
};

#endif // EDITPROFILE_H
