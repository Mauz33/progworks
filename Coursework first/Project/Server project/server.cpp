#include <server.h>
#include <QStringRef>

void Server::startServer()
{
    qserver = new QTcpServer();
    commandConn = new ConnectionCommand();
    commandStr = new StringsCommand();

    if(qserver->listen(QHostAddress::Any, 4242)){
        qDebug() << "Listening";
    }
    // При новом сигнале вызывать соотвутсвующую функцию
    connect(qserver, SIGNAL(newConnection()), this, SLOT(newConnect()));
}

// Вызывается при новом подключении
void Server::newConnect()
{
    // Передача в констуктор входящего соединения
    Client *currentClient = new Client(qserver->nextPendingConnection());

    connect(currentClient->socket, SIGNAL(readyRead()), this, SLOT(socketReady()));
    connect(currentClient->socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(changedSocketState(QAbstractSocket::SocketState)));

    //Получение Ip адреса в нужном формате
    QHostAddress address = currentClient->socket->peerAddress();
    QHostAddress ipv4(address.toIPv4Address());
    qDebug().noquote() << ipv4.toString() << "Connected";
    listClients.push_back(currentClient);
}

// Вызывается при изменении сосстояния сокета
void Server::changedSocketState(QAbstractSocket::SocketState sockState)
{
    if(sockState == QAbstractSocket::UnconnectedState){
        QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());

        // Удаляется отключивший клиент из списка клиентов
        for(int i = 0; i < listClients.size(); i++)
        {
            if(listClients.at(i)->socket == sender)
            {
                listClients.removeAt(i);
                break;
            }
        }
        QHostAddress address = sender->peerAddress();
        QHostAddress ipv4(address.toIPv4Address());
        qDebug().noquote() << ipv4.toString() << "Disconnected";
    }
}

void Server::socketReady()
{
    //Получение сокета, который отправил данные
    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());
    QByteArray Data = sender->readAll();
    QStringList list = QString(Data).split(" ");

    // Авторизация, регистрация
    if(list.at(0) == "auth"){
        bool auth = authorization(list.at(1), list.at(2), sender); // Прошла авторизация или нет
        if(!auth){
            sender->write("IncorrectPassword");
            return;
        }
        else if (auth){
            for(int i = 0; i < listClients.size(); i++){
                if(listClients.at(i)->socket == sender){
                    listClients.at(i)->isAuth = true;
                    return;
                }
            }
        }
    }
    else if(list.at(0) == "registr"){
        registration(list.at(1), list.at(2), sender);
    }

    //Проверка авторизован ли пользователь
    for(int i = 0; i < listClients.size(); i++){
        if(listClients.at(i)->socket == sender && listClients.at(i)->isAuth == true){
            break;
        }
        else if(!(listClients.at(i)->socket == sender && listClients.at(i)->isAuth == true)){
            return;
        }
    }

    //Определение типа комманды, затем поиск ее в блоке
    if(list.at(0) == "ConnectionCommand"){
        if(list.at(1) == "ping"){
            commandConn->pingPong(sender);
            return;
        }
        if(list.at(1) == "echo"){
            commandConn->echoMessage(sender, Data);
            return;
        }
        if(list.at(1) == "disconnect"){
            commandConn->closeConnection(sender);
            return;
        }
    }
    else if(list.at(0) == "StringsCommand"){
        if(list.at(1) == "set"){
            commandStr->setKeyValue(sender, Data);
            return;
        }
        else if(list.at(1) == "get"){
            commandStr->getKeyValue(sender, Data);
            return;
        }
        else if(list.at(1) == "exist"){
            commandStr->existKeyValue(sender, Data);
            return;
        }
        else if(list.at(1) == "getnset"){
            commandStr->getAndSet(sender, Data);
            return;
        }
        else if(list.at(1) == "append"){
            commandStr->appendTo(sender, Data);
            return;
        }
        else if(list.at(1) == "increment"){
            commandStr->increment(sender, Data);
            return;
        }
        else if(list.at(1) == "decrement"){
            commandStr->decrement(sender, Data);
            return;
        }
    }
    else{
        sender->write("UnknownCommand ");
        return;
    }
}
