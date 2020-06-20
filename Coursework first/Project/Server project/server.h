#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QList>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDebug>
#include <QStringList>
#include <QCryptographicHash>
#include <QObject>
#include <connectedclients.h>
#include <authreg.h>
#include <command.h>


class Server : public QTcpServer{
    Q_OBJECT

public slots:
    void startServer();
    void newConnect();
    void changedSocketState(QAbstractSocket::SocketState socketState);
    void socketReady();
private:
    QTcpServer*  qserver;
    QList<Client*> listClients; // Список класса клиентов с сокетами и информации об авторизации
    ConnectionCommand* commandConn;
    StringsCommand* commandStr;
};

#endif // SERVER_H
