#include "command.h"

ConnectionCommand::ConnectionCommand()
{

}

ConnectionCommand::~ConnectionCommand()
{

}

void ConnectionCommand::pingPong(QTcpSocket *socket)
{
    socket->write("ConnectionCommand pong");
}

void ConnectionCommand::echoMessage(QTcpSocket *socket, QByteArray message)
{
    QString qstr = message;
    QRegExp qreg("(ConnectionCommand echo)( )+");
    qstr.remove(qreg);
    int k = 0;
    for(int i = 0; i < qstr.size(); i++){
        if(qstr[i] == '"'){
            k++;
        }
    }
    if(k==0){
        int index = qstr.indexOf(' ', 0);
        if(index == -1){
            qstr = "ConnectionCommand echo " + qstr;
            socket->write(qstr.toUtf8());
        }
        else{
            QStringRef qstrref(&qstr, 0, qstr.size());
            socket->write("ConnectionCommand echo " + qstrref.toUtf8());
        }
    }
    else if(k>=2 && k%2==0){
        int firstIndex = qstr.indexOf('"', 0);
        int secondIndex = qstr.indexOf('"', firstIndex+1);
        QStringRef qstrref(&qstr, firstIndex, secondIndex+1);
        socket->write("ConnectionCommand echo " + qstrref.toUtf8());
    }
    else socket->write("ConnectionCommand echo ERROR");
}

void ConnectionCommand::closeConnection(QTcpSocket *socket)
{
    socket->write("ConnectionCommand disconnect");
}

StringsCommand::StringsCommand()
{
    mapStrings = new QMap<QString, QString>();
}

StringsCommand::~StringsCommand()
{

}

void StringsCommand::setKeyValue(QTcpSocket *socket, QString message)
{
    QRegExp qreg("^(StringsCommand set)( )+");
    message.remove(qreg);

    QStringList list = message.split(" ");

    if(list.size() !=2){
        socket->write("StringsCommand set ERROR");
    }
    else if(list.size() == 2){
        mapStrings->insert(list.at(0), list.at(1));
        if(mapStrings->value(list.at(0)) == list.at(1)){
            socket->write("StringsCommand set OK");
        }
        else{
            socket->write("StringsCommand set ERROR");
        }
    }
}

void StringsCommand::getKeyValue(QTcpSocket *socket, QString message)
{
    QRegExp qreg("^(StringsCommand get)( )+");
    message.remove(qreg);

    QStringList list = message.split(" ");

    if(list.size() != 1){
        socket->write("StringsCommand set ERROR");
    }
    else if(list.size() == 1){
        if(mapStrings->contains(list.at(0))){
            socket->write("StringsCommand get " + mapStrings->value(list.at(0)).toUtf8());
        }
        else{
            socket->write("StringsCommand get UNDEFINED");
        }
    }
}

void StringsCommand::existKeyValue(QTcpSocket *socket, QString message)
{
    QRegExp qreg("^(StringsCommand exist)( )+");
    message.remove(qreg);

    QStringList list = message.split(" ");
    if(list.size() != 1){
        socket->write("StringsCommand exist ERROR");
    }
    else if(list.size() == 1){
        if(mapStrings->contains(list.at(0))){
            socket->write("StringsCommand exist EXIST");
        }
        else{
            socket->write("StringsCommand get NULL");
        }
    }
}

void StringsCommand::getAndSet(QTcpSocket *socket, QString message)
{
    QRegExp qreg("^(StringsCommand getnset)( )+");
    message.remove(qreg);

    QStringList list = message.split(" ");

    if(list.size() !=2){
        socket->write("StringsCommand getnset ERROR");
    }
    else if(list.size() == 2){
        QString oldValue = mapStrings->value(list.at(0));
        mapStrings->insert(list.at(0), list.at(1));
        if(mapStrings->value(list.at(0)) == list.at(1)){
            socket->write("StringsCommand getnset " + oldValue.toUtf8());
        }
        else{
            socket->write("StringsCommand set ERROR");
        }
    }
}

void StringsCommand::appendTo(QTcpSocket *socket, QString message)
{
    QRegExp qreg("^(StringsCommand append)( )+");
    message.remove(qreg);

    QStringList list = message.split(" ");

    if(list.size() !=2){
        socket->write("StringsCommand append ERROR");
    }
    else if(list.size() == 2){
        if(mapStrings->contains(list.at(0))){
            QString value = mapStrings->value(list.at(0)) + " " + list.at(1);
            socket->write("StringsCommand append " + value.toUtf8());
        }
        else{
            mapStrings->insert(list.at(0), list.at(1));
            if(mapStrings->value(list.at(0)) == list.at(1)){
                socket->write("StringsCommand append " + list.at(1).toUtf8());
            }
            else{
                socket->write("StringsCommand append ERROR");
            }
        }
    }
    else{
        socket->write("StringsCommand append ERROR");
    }
}

void StringsCommand::increment(QTcpSocket *socket, QString message)
{
    QRegExp qreg("^(StringsCommand increment)( )+");
    message.remove(qreg);

    QStringList list = message.split(" ");

    if(list.size() !=1){
        socket->write("StringsCommand increment ERROR");
    }
    else{
        if(mapStrings->contains(list.at(0))){
            int valueInt = mapStrings->value(list.at(0)).toInt() + 1;
            QString valueStr = QString::number(valueInt);
            mapStrings->insert(list.at(0), valueStr);
            socket->write("StringsCommand increment " + valueStr.toUtf8());
        }
        else{
            socket->write("StringsCommand increment NULL");
        }
    }

}

void StringsCommand::decrement(QTcpSocket *socket, QString message)
{
    QRegExp qreg("^(StringsCommand decrement)( )+");
    message.remove(qreg);

    QStringList list = message.split(" ");

    if(list.size() !=1){
        socket->write("StringsCommand decrement ERROR");
    }
    else{
        if(mapStrings->contains(list.at(0))){
            int valueInt = mapStrings->value(list.at(0)).toInt() - 1;
            QString valueStr = QString::number(valueInt);
            mapStrings->insert(list.at(0), valueStr);
            socket->write("StringsCommand decrement " + valueStr.toUtf8());
        }
        else{
            socket->write("StringsCommand decrement NULL");
        }
    }
}
