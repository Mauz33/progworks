#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->getAccessButton->setEnabled(false);
    ui->pushButtonSend->setEnabled(false);

    socket = new QTcpSocket(this);

    QRegExp sendLine("^[a-z0-9\\s]*");
    QRegExpValidator *validatorSend = new QRegExpValidator(sendLine, this);
    ui->lineCommand->setValidator(validatorSend);

    connect(socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
    connect(socket, &QTcpSocket::connected, this, &MainWindow::switchAcessStatus);
    connect(socket, &QTcpSocket::connected, this, &MainWindow::on_getAccessButton_clicked);
    connect(socket, &QTcpSocket::connected, this, &MainWindow::switchLineStatus);
    connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));
}

MainWindow::~MainWindow()
{
    delete socket;
    delete form;
    delete ui;
}

// Вызывается при отключении от сервера
void MainWindow::sockDisc()
{
    // Открываются объекты для ввода
    ui->lineIP->setEnabled(true);
    ui->linePort->setEnabled(true);
    ui->pushButtonConnect->setEnabled(true);
    ui->getAccessButton->setEnabled(true);
    // Удаляется сокет
    socket->abort();
}

void MainWindow::sockReady()
{
    // Считывание данных из сокета
    QByteArray Data = socket->readAll();
    QStringList list = QString(Data).split(" ");

    if(list.at(0) == "Authorized") // Если пользователь авторизовался
    {
        form->log_setColorFieldSuccess();
        QMessageBox::information(nullptr, "Information", "You are logged in");
        ui->getAccessButton->setEnabled(false);
        ui->pushButtonSend->setEnabled(true);
        form->close();

        QHostAddress address = socket->peerAddress();
        QHostAddress ipv4(address.toIPv4Address());
        ui->textBrowser_4->append("Connected to: " +ipv4.toString());
        return;
    }
    else if(list.at(0) == "AlredyExist") // Если пользователь с данным логином уже существует
    {
        QMessageBox::critical(nullptr, "Error", "The login already exists");
        form->reg_setColorLoginError();
        return;
    }
    else if(list.at(0) == "RegSuccessful") // Если регистрация прошла успешно
    {
        QMessageBox::about(nullptr, "Succes", "You have successfully registered");
        form->reg_setColorLoginSuccess();
        form->cleanField();
        form->switchTabAfterReg();
        return;
    }
    else if(list.at(0) == "IncorrectPassword") // Если введен неверный логин или пароль
    {
        QMessageBox::critical(nullptr, "Error", "Invalid login or password");
        form->log_setColorFieldError();
        return;
    }

    if(list.at(0) == "UnknownCommand")
    {
        ui->textBrowser_4->append("Unknown command");
    }
    else if(list.at(0) == "ConnectionCommand")
    {
        if(list.at(1) == "pong")
        {
            ui->textBrowser_4->append(list.at(1));
        }
        else if(list.at(1) == "echo")
        {
            QString qstr = Data;
            QRegExp qreg("(ConnectionCommand echo)( )+");
            qstr.remove(qreg);
            ui->textBrowser_4->append(qstr);
        }
        else if(list.at(1) == "disconnect")
        {
            QHostAddress address = socket->peerAddress();
            QHostAddress ipv4(address.toIPv4Address());
            socket->abort();
            ui->textBrowser_4->append("Disconnected from: " + ipv4.toString());
            QMessageBox::information(this, "Information", "You are disconnected");
        }
    }
    else if(list.at(0) == "StringsCommand")
    {
        if(list.at(1) == "set")
        {
            ui->textBrowser_4->append(list.at(2));
        }
        else if(list.at(1) == "get")
        {
            ui->textBrowser_4->append(list.at(2));
        }
        else if(list.at(1) == "exist")
        {
            ui->textBrowser_4->append(list.at(2));
        }
        else if(list.at(1) == "getnset")
        {
            ui->textBrowser_4->append(list.at(2));
        }
        else if(list.at(1) == "append")
        {
            QRegExp qreg("^(StringsCommand append)( )+");
            QString str = Data;
            str.remove(qreg);
            ui->textBrowser_4->append(str);
        }
        else if(list.at(1) == "increment")
        {
            ui->textBrowser_4->append(list.at(2));
        }
        else if(list.at(1) == "decrement"){
            ui->textBrowser_4->append(list.at(2));
        }

    }

}

void MainWindow::on_pushButtonConnect_clicked()
{
    QString strIP = ui->lineIP->text();
    int port = ui->linePort->text().toInt();
    socket->connectToHost(strIP, port);
}

void MainWindow::on_pushButtonSend_clicked()
{
    QByteArray Data;
    QString lineData = ui->lineCommand->text();
    QStringList list = lineData.split(" ");
    if(list.at(0) == ""){
        ui->textBrowser_4->append(">");
        return;
    }
    if(list.at(0) == "ping"){
        socket->write(Data.append("ConnectionCommand "+lineData));
    }
    else if(list.at(0) == "echo"){
        socket->write(Data.append("ConnectionCommand "+lineData));
    }
    else if(list.at(0) == "disconnect"){
        socket->write(Data.append("ConnectionCommand "+lineData));
    }
    else if(list.at(0) == "set"){
        socket->write(Data.append("StringsCommand "+lineData));
    }
    else if(list.at(0) == "get"){
        socket->write(Data.append("StringsCommand "+lineData));
    }
    else if(list.at(0) == "exist"){
        socket->write(Data.append("StringsCommand "+lineData));
    }
    else if(list.at(0) == "getnset"){
        socket->write(Data.append("StringsCommand "+lineData));
    }
    else if(list.at(0) == "append"){
        socket->write(Data.append("StringsCommand "+lineData));
    }
    else if(list.at(0) == "increment"){
        socket->write(Data.append("StringsCommand "+lineData));
    }
    else if(list.at(0) == "decrement"){
        socket->write(Data.append("StringsCommand "+lineData));
    }
    else{
        socket->write(Data.append(lineData));
    }
    ui->lineCommand->setText("");
    ui->textBrowser_4->append("> " + lineData);
}

void MainWindow::on_getAccessButton_clicked()
{
    form = new Form(socket);
    form->setWindowTitle("Authorization");
    form->setModal(true);
    form->exec();

}

void MainWindow::switchLineStatus()
{
    ui->lineIP->setEnabled(false);
    ui->linePort->setEnabled(false);
    ui->pushButtonConnect->setEnabled(false);
}

void MainWindow::switchAcessStatus()
{
    ui->getAccessButton->setEnabled(true);
}
