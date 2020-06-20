#ifndef CONNECTEDCLIENTS_H
#define CONNECTEDCLIENTS_H

#include <QList>
#include <QTcpSocket>

class Client
{
public:
    Client(QTcpSocket* socket, bool isAuth = 0);
    ~Client();

     QTcpSocket *socket;
     bool isAuth;
};

#endif // CONNECTEDCLIENTS_H
