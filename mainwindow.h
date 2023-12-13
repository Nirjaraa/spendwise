#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow1.h"
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_previous3_clicked();

    void on_previous2_clicked();

    void on_pushButton_7_clicked();

    void on_next4_clicked();

    void on_next3_clicked();

    void on_next2_clicked();

    void on_next1_clicked();

private:
    Ui::MainWindow *ui;
    MainWindow1 *Mainwindow1;
};
#endif // MAINWINDOW_H
