#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QStringList>
#include <QCryptographicHash>
#include <form.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTcpSocket* socket;
    QByteArray Data;
    Form *form;

private slots:
    void sockReady();
    void sockDisc();
    void on_pushButtonConnect_clicked();
    void on_pushButtonSend_clicked();
    void on_getAccessButton_clicked();
    void switchLineStatus();
    void switchAcessStatus();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
