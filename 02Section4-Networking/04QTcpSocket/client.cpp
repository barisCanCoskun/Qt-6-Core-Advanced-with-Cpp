#include "client.h"

Client::Client(QObject *parent)
    : QObject{parent}
{
    connect(&socket, &QTcpSocket::connected, this, &Client::connected);
    connect(&socket, &QTcpSocket::disconnected, this, &Client::disconnected);
    //Qt 5
    //connect(&socket,QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),this,&Client::error); //Explain
    connect(&socket, &QTcpSocket::errorOccurred, this, &Client::error);
    connect(&socket, &QTcpSocket::stateChanged, this, &Client::stateChanged);
    connect(&socket, &QTcpSocket::readyRead, this, &Client::readyRead);
}

void Client::connectToHost(QString host, quint16 port)
{
    if(socket.isOpen()) disconnect();
    qInfo() << "Connecting to:" << host << "on port" << port;

    socket.connectToHost(host, port);
    // start the connection. This is not an instantenous thing.
    // There's that 3 way handshake.
    // Now the problem with that 3 way handshake is it can take a little of time,
    // which is why we're using signals and slots we want this to fire off and then let us know
    // asynchronously when it's actually connected.
}

void Client::disconnect()
{
    socket.close();
    socket.waitForDisconnected();
}

void Client::connected()
{
    qInfo() << "Connected!";

    qInfo() << "Sending";
    socket.write("Hello\r\n");
    // This will immediately make most web servers very angry.
}

void Client::disconnected()
{
    qInfo() << "Disconnected";
}

void Client::error(QAbstractSocket::SocketError socketError)
{
    qInfo() << "Error:" << socketError << "" << socket.errorString();
}

void Client::stateChanged(QAbstractSocket::SocketState socketState)
{
    QMetaEnum metaEnum{QMetaEnum::fromType<QAbstractSocket::SocketState>()};
    qInfo() << "State:" << metaEnum.valueToKey(socketState);
}

void Client::readyRead()
{
    qInfo() << "Data from:" << sender() << "btyes:" << socket.bytesAvailable();
    qInfo() << "Data:" << socket.readAll();
    // A lot of people can think isn't readAll dangerous? What if there's a lot of data?
    // Sockets that read buffer they are very small. It's okay to readAll bec
    // you are not going to get like terabytes of data.
}












