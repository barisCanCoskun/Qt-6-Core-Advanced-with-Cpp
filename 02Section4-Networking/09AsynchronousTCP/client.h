#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QMetaEnum>
#include <QNetworkProxy>
#include <QThread>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

signals:

public slots:
    void connectToHost(QString host, quint16 port);
    void disconnect();
    // he has a habit of making things slots
    // so that he can connect to them via signals slots later
    // if he decides to change sth...

private slots:
    void connected();
    void disconnected();
    void error(QAbstractSocket::SocketError socketError);
    void stateChanged(QAbstractSocket::SocketState socketState);
    void readyRead();

private:
    QTcpSocket socket;

};

#endif // CLIENT_H















