#include "chat.h"

Chat::Chat(QObject *parent)
    : QObject{parent}
{
    if(!socket.bind(port, QUdpSocket::ShareAddress)){  // if failed
        qInfo() << socket.errorString();
    }
    else{
        qInfo() << "Started UDP on" << socket.localAddress() << ":" << socket.localPort();
        connect(&socket, &QUdpSocket::readyRead, this, &Chat::readyRead);
    }
}

void Chat::command(QString value)
{
    QString message{name + ": "};
    if(name.isEmpty()){
        name = value;
        message = name + ": joined";
        // this is when sb joins the chatroom
        send(message);
        return;
    }

    message.append(value);
    send(message);
}

void Chat::send(QString value)
{
    QByteArray data{value.toLatin1()};
    QNetworkDatagram datagram(data, QHostAddress::Broadcast, port);

    if(!socket.writeDatagram(datagram))
        qInfo() << socket.errorString();
}

void Chat::readyRead()
{
    while (socket.hasPendingDatagrams()) {
        QNetworkDatagram datagram{socket.receiveDatagram()};
        // qInfo() << "Read:" << datagram.data() << "from" << datagram.senderAddress() << ":" << datagram.senderPort();
        qInfo() << datagram.data();
    }
}










