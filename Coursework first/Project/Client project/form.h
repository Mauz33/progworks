#ifndef FORM_H
#define FORM_H

#include <QDialog>
#include <QString>
#include <QTcpSocket>
#include <QRegExp>
#include <QRegExpValidator>
#include <QMessageBox>
#include <QCryptographicHash>

namespace Ui {
class Form;
}

class Form : public QDialog
{
    Q_OBJECT

public:
    explicit Form(QTcpSocket* socket, QWidget *parent = nullptr);
    ~Form();

    void reg_setColorLoginError();
    void reg_setColorLoginSuccess();
    void log_setColorFieldError();
    void log_setColorFieldSuccess();
    void cleanField();
    void switchTabAfterReg();

private slots:
    void on_logIn_pushButton_clicked();
    void on_reg_pushButton_clicked();

private:
    QTcpSocket *socket;
    Ui::Form *ui;
};

#endif // FORM_H
