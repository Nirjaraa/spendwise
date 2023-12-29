#include <QRegularExpression>
#include "signin.h"
#include "ui_signin.h"
#include <QMessageBox>
#include "mainwindow1.h"
MainWindow1 *mn;

signin::signin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::signin)
{
    ui->setupUi(this);
     setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
}

signin::~signin()
{
    delete ui;
}

void signin::on_Signup_clicked()
{
    QString userId="", passwrd="",first="",last="",email="";
    userId = ui->uname->text();
    passwrd= ui->pw->text();
    first= ui->firstname->text();
    last= ui->lastname->text();
    email= ui->emaill->text();

    ui->fname_error->setText("");
    ui->lname_error->setText("");
    ui->uname_error->setText("");
    ui->pw_error->setText("");
    ui->email_error->setText("");
    //Open database
    connOpen();
    if(!connOpen()){qDebug() << "Not Connected";}

    QRegularExpression emailRegex("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}");
    QRegularExpression specialCharsRegex("[!@#$%^&*(),.?\":{}|<>\\d]");
    bool validator = true;
//Check Firstname Validity
    if(first.isEmpty()){
        ui->fname_error->setText("First name is empty!");
        validator = false;
    } else if(first.contains(specialCharsRegex)){
        ui->fname_error->setText("Firstname cannot have number!");
        validator = false;
    }

    //Check Lastname Validity
    if(last.isEmpty()){
        ui->lname_error->setText("Last name is empty!");
        validator = false;
    } else if(last.contains(specialCharsRegex)){
        ui->lname_error->setText("Last name cannot have number!");
        validator = false;
    }
    //Check Password Validity
    if(passwrd.isEmpty()){
        ui->pw_error->setText("Password is empty!");
        validator = false;
    } else {
        if (passwrd.length() < 8) {
            ui->pw_error->setText("Less than 8 characters!");
            validator = false;
        }
        else if(!passwrd.contains(specialCharsRegex)){
            ui->pw_error->setText("No special characters!");
            validator = false;
        }
    }

    if (email.isEmpty()) {
        ui->email_error->setText("Email is empty!");
        validator = false;
    } else if (!emailRegex.match(email).hasMatch()) {
        ui->email_error->setText("Invalid email format!");
        validator = false;
    }

    //Check Username Validity
    if(userId.isEmpty()){
        ui->uname_error->setText("Username is empty!");
        validator = false;
    } else {
        QSqlQuery fetch;
        fetch.prepare("SELECT * FROM logininfoo WHERE username='"+userId+"'");
        if(fetch.exec() && fetch.next()){
               ui->uname_error->setText("This username already exists!");
                validator = false;
            }

    }

    if (!validator) return;

    QSqlQuery qry;
    qry.prepare("INSERT INTO logininfoo (username, pw, fname, lname, email) VALUES (:userId, :passwrd, :first, :last, :email)");
    qry.bindValue(":userId", userId);
    qry.bindValue(":passwrd", passwrd);
    qry.bindValue(":first", first);
    qry.bindValue(":last", last);
    qry.bindValue(":email", email);

    if (qry.exec()) {
        QMessageBox::information(this, tr("Save"), tr("Your data has been saved"));
        hide();
        mn=new MainWindow1(this);
        mn->show();
    }
    connClose();
}


void signin::on_pushButton_clicked()
{
    hide();
    mn=new MainWindow1(this);
    mn->show();
}

