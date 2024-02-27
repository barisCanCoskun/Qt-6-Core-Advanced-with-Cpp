#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QUdpSocket>
#include <QNetworkDatagram>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

signals:

public slots:
    void start();       // start a timer
    void stop();        // stop a timer
    void timeout();     // when the timer fires
    void readyRead();   // when there is actually info on the socket to read
    void broadcast();   // broadcast that datagram out onto the network

private:
    QUdpSocket socket;
    QTimer timer;
    quint16 port{2020}; // Note < 1024 those admin ports / special services. HTTP, FTP, POP3, SMTP

};

#endif // WORKER_H


















