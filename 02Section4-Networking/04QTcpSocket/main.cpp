/*
 * TCP Sockets
 *
 * Why
 * We need to understand the connection life cycle
 *
 * How
 * QTcpSocket
 *
 */

#include <QCoreApplication>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client;
    client.connectToHost("www.voidrealms.com", 80);
    // that port "80" is standard for unencrypted Web traffic.

    return a.exec();
}









