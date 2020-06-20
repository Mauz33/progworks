#include "connectedclients.h"

Client::Client(QTcpSocket* socket, bool isAuth)
{
    this->socket = socket;
    this->isAuth = isAuth;
}

Client::~Client()
{
    delete socket;
}
