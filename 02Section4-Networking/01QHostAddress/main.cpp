/*
 * Network interfaces and addresses
 *
 * Why
 * We can have more than one!
 *
 * How
 * QHostAddress
 *
 */

#include <QCoreApplication>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QAbstractSocket>
#include <QMetaEnum>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    for(int i{}; i < list.size(); ++i){  // list.count()... same thing
        QHostAddress address{list.at(i)};
        qInfo() << address.toString();

        // Never goes on the network
        qInfo() << "\tLoopback:" << address.isLoopback();

        // Send to many
        qInfo() << "\tMulticast:" << address.isMulticast();

        // can be written this way:
        // QMetaEnum metaEnum{QMetaEnum::fromType<QAbstractSocket::NetworkLayerProtocol>()};
        // qInfo() << "\tProtocol:" << metaEnum.valueToKey(address.protocol());

        switch (address.protocol()) {
            case QAbstractSocket::IPv4Protocol:
                qInfo() << "\tProtocol: IPv4";
                break;
            case QAbstractSocket::IPv6Protocol:
                qInfo() << "\tProtocol: IPv6";
                break;
            case QAbstractSocket::AnyIPProtocol:
                qInfo() << "\tProtocol: Any";
                break;
            case QAbstractSocket::UnknownNetworkLayerProtocol:
                qInfo() << "\tProtocol: Unknown";
                break;
        }

    }
    return a.exec();
}














