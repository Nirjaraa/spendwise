#include "records.h"
#include "ui_records.h"
#include "dashboard.h"
#include <QTableWidget>
#include <userdata.h>
dashboard *gg;

void addTableData(QTableWidget* tableWidget);

records::records(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::records)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    setWindowTitle("SpendWise");
    setWindowIcon(QIcon(":/resources/logo.png"));

    connOpen();
    addTableData(ui->tableWidget);
}


void addTableData(QTableWidget* tableWidget)
{
    QSqlQuery getRecords;
    getRecords.prepare("SELECT expenses, savings, income, extra FROM records WHERE username='"+username+"'");

    if (getRecords.exec())
    {
        int row = 0;
        while (getRecords.next())
        {
            tableWidget->setColumnCount(4);
            tableWidget->setHorizontalHeaderLabels({"Expenses", "Savings", "Income", "Extra"});
            // tableWidget->clearContents();

            int expenses = getRecords.value(0).toInt();
            int savings = getRecords.value(1).toInt();
            int income = getRecords.value(2).toInt();
            int extra = getRecords.value(3).toInt();

            tableWidget->insertRow(row);

            QTableWidgetItem *expensesItem = new QTableWidgetItem(QString::number(expenses));
            expensesItem->setTextAlignment(Qt::AlignCenter);
            tableWidget->setItem(row, 0, expensesItem);

            QTableWidgetItem *savingsItem = new QTableWidgetItem(QString::number(savings));
            savingsItem->setTextAlignment(Qt::AlignCenter);
            tableWidget->setItem(row, 1, savingsItem);

            QTableWidgetItem *incomeItem = new QTableWidgetItem(QString::number(income));
            incomeItem->setTextAlignment(Qt::AlignCenter);
            tableWidget->setItem(row, 2, incomeItem);

            QTableWidgetItem *extraItem = new QTableWidgetItem(QString::number(extra));
            extraItem->setTextAlignment(Qt::AlignCenter);
            tableWidget->setItem(row, 3, extraItem);

            QString tableStyleSheet = "QTableView::item"
            "{"
                "background-color: white;"
                "border-radius: 8px;"
                "margin: 3px;"
            "}"
            "QTableView{"
                "gridline-color:transparent;"
                "border-radius: 8px;"
                "margin: 3px;"
            "}";

            QString horizontalHeaderStyleSheet = "QHeaderView::section:horizontal"
            "{"
                "border: none;"
                "border-radius: 7px;"
                "margin: 3px;"
                "height:30px;"
                "background-color: white;"
            "}";

            QString verticalHeaderStyleSheet = "QHeaderView::section:vertical"
            "{"
                "border: none;"
                "border-radius: 7px;"
                "padding:5px;"
                "margin: 3px;"
                "width:20px;"
                "background-color: white;"
            "}";

            QString cornerButtonStyleSheet = "QTableCornerButton::section"
            "{"
                "background-color:transparent;"
                "border: none;"
            "}";

            tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
            tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            tableWidget->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);

            QFont headerFont("Bahnschrift", 13, 500);
            tableWidget->horizontalHeader()->setFont(headerFont);
            tableWidget->verticalHeader()->setFont(headerFont);

            tableWidget->setStyleSheet(tableStyleSheet);
            tableWidget->horizontalHeader()->setStyleSheet(horizontalHeaderStyleSheet);
            tableWidget->verticalHeader()->setStyleSheet(verticalHeaderStyleSheet);
            tableWidget->findChild<QAbstractButton*>()->setStyleSheet(cornerButtonStyleSheet);

            ++row;
        }
    }
    else
    {
        qDebug() << "Error executing query:" << getRecords.lastError().text();
    }
}

records::~records()
{
    delete ui;
}

void records::on_back_clicked()
{
    hide();
    gg=new dashboard(this);
    gg->show();
}

