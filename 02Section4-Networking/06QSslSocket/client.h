#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QMetaEnum>
#include <QNetworkProxy>
#include <QSslSocket>
#include <QSslPreSharedKeyAuthenticator>

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

    // SSL
    void encrypted();
    void encryptedBytesWritten(qint64 written);
    void modeChanged(QSslSocket::SslMode mode);
    void peerVerifyError(const QSslError &error);
    // this one is dangerous.
    // The whole point of using SSL is you can trust who you're talking to
    // and that you're talking to them in an encrypted manner, if you get this error,
    // that means you can't really verify they are who they say they are.

    void preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *authenticator);
    void sslErrors(const QList<QSslError> &errors);

private:
    QSslSocket socket;

};

#endif // CLIENT_H















