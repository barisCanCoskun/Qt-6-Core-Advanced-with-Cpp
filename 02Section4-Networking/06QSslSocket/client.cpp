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

    //SSL
    connect(&socket, &QSslSocket::encrypted, this, &Client::encrypted);
    connect(&socket, &QSslSocket::encryptedBytesWritten, this, &Client::encryptedBytesWritten);
    connect(&socket, &QSslSocket::modeChanged, this, &Client::modeChanged);
    connect(&socket, &QSslSocket::peerVerifyError, this, &Client::peerVerifyError);
    connect(&socket, &QSslSocket::preSharedKeyAuthenticationRequired, this, &Client::preSharedKeyAuthenticationRequired);
    connect(&socket, QOverload<const QList<QSslError> &>::of(&QSslSocket::sslErrors), this, &Client::sslErrors);

    /*
    // Proxy stuff
    QNetworkProxy proxy(QNetworkProxy::HttpProxy, "35.154.21.111", 3128);
    // QNetworkProxy proxy(QNetworkProxy::HttpProxy, "50.174.7.157", 80); // not connected

    // Can set authentication
    // proxy.setUser("user");
    // proxy.setPassword("pass");

    // App proxy
    QNetworkProxy::setApplicationProxy(proxy);

    // Per socket
    socket.setProxy(proxy);
    */
}

void Client::connectToHost(QString host, quint16 port)
{
    if(socket.isOpen()) disconnect();
    qInfo() << "Connecting to:" << host << "on port" << port;

    // socket.connectToHost(host, port);    // Normal TCP

    socket.ignoreSslErrors();   // Not Secure!!
    // Typically he won't do this in the real world bec. it's not secure.

    socket.setProtocol(QSsl::SecureProtocols);  // ask to sysadmin
    socket.connectToHostEncrypted(host, port);
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
    // socket.write("Hello\r\n");
    // This will immediately make most web servers very angry.

    QByteArray data;
    data.append("GET /get HTTP/1.1\r\n");   // very old protocol, dont use in production.
    // we simulate like we are a specific browser: using Mozilla on Windows NT compatible
    data.append("User-Agent: Mozilla/4.0 (compatible; MSIE 8.0 Windows NT 6.0; Trident /4.0)\r\n");
    data.append("Host: local\r\n");
    data.append("Connection: Close\r\n"); // tell server to go and stop talking to us when we're done.
    data.append("\r\n");
    socket.write(data);

    socket.waitForBytesWritten();
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

void Client::encrypted()
{
    qInfo() << "Encrypted";
}

void Client::encryptedBytesWritten(qint64 written)
{
    qInfo() << "encryptedBytesWritten:" << written;
}

void Client::modeChanged(QSslSocket::SslMode mode)
{
    // Qt doesn't support this yet...
    // QMetaEnum metaEnum{QMetaEnum::fromType<QSslSocket::SslMode>()};
    // qInfo() << "Mode:" << metaEnum.valueToKey(mode);
    qInfo() << "SSl Mode:" << mode;
}

void Client::peerVerifyError(const QSslError &error)
{
    qInfo() << "peerVerifyError:" << error.errorString();
}

void Client::preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator *authenticator)
{
    qInfo() << "Preshared key required...";
    //QSslPreSharedKeyAuthenticator lookup if needed
}

void Client::sslErrors(const QList<QSslError> &errors)
{
    qInfo() << "Ssl Errors";
    foreach (QSslError e, errors) {
        qInfo() << e.errorString();
    }
}












