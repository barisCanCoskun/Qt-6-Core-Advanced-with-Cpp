#include "worker.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{
    connect(&timer, &QTimer::timeout, this, &Worker::timeout);
    connect(&socket, &QUdpSocket::readyRead, this, &Worker::readyRead);
    timer.setInterval(1000);
}

void Worker::start()
{
    if(!socket.bind(port)){  // if failed
        qInfo() << socket.errorString();
        return ;
    }

    qInfo() << "Started UDP on" << socket.localAddress() << ":" << socket.localPort();

    broadcast();

}

void Worker::stop()
{
    timer.stop();

    // whenever open a socket, have to close it
    socket.close();
    // the reason for that is under the hood sockets in Qt are IODevices, just like a file.
    // when you open a file, you have to close it...

    qInfo() << "Stopped";
}

void Worker::timeout()
{
    QString date{QDateTime::currentDateTime().toString()};

    qInfo() << "\ntest purpose:" << date << "\n"; // test purpose

    QByteArray data{date.toLatin1()};  // date.toUtf8();

    // what we're really doing is we're building info that we're going to send,
    // so we're going to get a string representation of the current date time and then
    // we're going to convert that into a QByteArray!!!
    // Whenever you're working with info on a socket,
    // it's 99% of the time under the hood QByteArray!!!
    // So get familiar with how to convert things to and from QByteArray...

    QNetworkDatagram datagram(data, QHostAddress::Broadcast, port);
    qInfo() << "Send:" << data;
    socket.writeDatagram(datagram);

}

void Worker::readyRead()
{
    while (socket.hasPendingDatagrams()) {
        QNetworkDatagram datagram{socket.receiveDatagram()};
        qInfo() << "Read:" << datagram.data() << "from" << datagram.senderAddress() << ":" << datagram.senderPort();
    }
}

void Worker::broadcast()
{
    qInfo() << "Broadcasting...";
    timer.start();
}











