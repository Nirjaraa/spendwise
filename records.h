#ifndef RECORDS_H
#define RECORDS_H

#include <QMainWindow>

namespace Ui {
class records;
}

class records : public QMainWindow
{
    Q_OBJECT

public:
    explicit records(QWidget *parent = nullptr);
    ~records();

private slots:
    void on_back_clicked();

private:
    Ui::records *ui;


};

#endif // RECORDS_H
