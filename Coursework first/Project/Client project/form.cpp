#include "form.h"
#include "ui_form.h"

Form::Form(QTcpSocket* socket,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form)
{
    this->socket=socket;
    ui->setupUi(this);

    QRegExp login("^[a-zA-z0-9]{1,16}");
    QRegExp password("^[a-zA-z0-9]{1,22}");
    QRegExpValidator *validatorLogin = new QRegExpValidator(login, this);
    QRegExpValidator *validatorPassword = new QRegExpValidator(password, this);
    ui->logIn_login->setValidator(validatorLogin);
    ui->logIn_password->setValidator(validatorPassword);
    ui->reg_login->setValidator(validatorLogin);
    ui->reg_password1->setValidator(validatorPassword);
    ui->reg_password2->setValidator(validatorPassword);
}

Form::~Form()
{
    delete socket;
    delete ui;
}

void Form::reg_setColorLoginError()
{
    ui->reg_login->setStyleSheet("border: 2px solid red");
}

void Form::reg_setColorLoginSuccess()
{
    ui->reg_login->setStyleSheet("border: 1px solid black");
}

void Form::log_setColorFieldError()
{
    ui->logIn_login->setStyleSheet("border: 2px solid red");
    ui->logIn_password->setStyleSheet("border: 2px solid red");
}

void Form::log_setColorFieldSuccess()
{
    ui->logIn_login->setStyleSheet("border: 1px solid black");
}

void Form::cleanField()
{
    ui->reg_login->setText("");
    ui->reg_password1->setText("");
    ui->reg_password2->setText("");
}

void Form::switchTabAfterReg()
{
    ui->tabWidget->setCurrentIndex(0);
}

void Form::on_logIn_pushButton_clicked()
{
    QString login = ui->logIn_login->text();
    QString password = ui->logIn_password->text();

    QByteArray QBstr;
    socket->write(QBstr.append("auth " + login + " " +password));

}

void Form::on_reg_pushButton_clicked()
{

    if(ui->reg_login->text().isEmpty() || ui->reg_password1->text().isEmpty() || ui->reg_password2->text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "All fields must be filled in");
        return;
    }

    QString login = ui->reg_login->text();
    QString password1 = ui->reg_password1->text();
    QString password2 = ui->reg_password2->text();

    if(password1!=password2)
    {
        ui->reg_password1->setStyleSheet("border: 2px solid red");
        ui->reg_password2->setStyleSheet("border: 2px solid red");
        QMessageBox::critical(this, "Error", "Passwords do not match");

        return;
    }

    ui->reg_password1->setStyleSheet("border: 1px solid black");
    ui->reg_password2->setStyleSheet("border: 1px solid black");

    QByteArray QBlogin, QBpassword1, QBpassword2;
    socket->write(QBlogin.append("registr " + login + " " +password1 + " " + password2));

}
