#ifndef COMMAND_H
#define COMMAND_H

#include <QTcpSocket>
#include <QString>
#include <QStringList>
#include <QRegExp>
#include <QMap>

class ConnectionCommand
{
public:
    ConnectionCommand();
    ~ConnectionCommand();

    void pingPong(QTcpSocket *socket);
    void echoMessage(QTcpSocket *socket, QByteArray message);
    void closeConnection(QTcpSocket *socket);
};

class StringsCommand
{
public:
    StringsCommand();
    ~StringsCommand();

    QMap<QString, QString> *mapStrings;

    void setKeyValue(QTcpSocket *socket, QString message);
    void getKeyValue(QTcpSocket *socket, QString message);
    void existKeyValue(QTcpSocket *socket, QString message);
    void getAndSet(QTcpSocket *socket, QString message);
    void appendTo(QTcpSocket *socket, QString message);
    void increment(QTcpSocket *socket, QString message);
    void decrement(QTcpSocket *socket, QString message);


};



#endif // COMMAND_H
