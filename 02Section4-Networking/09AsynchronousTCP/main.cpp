/*
 * Asynchronous TCP
 *
 * Why
 * This is how you would typically work with it
 *
 * How
 * Signals and Slots
 * Note this blocks in the slots
 *
 */

#include <QCoreApplication>
#include <QThread>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread::currentThread()->setObjectName("Main Thread");

    Client client;
    client.connectToHost("voidrealms.com", 80);

    qInfo() << "*** Free to do other things ***";

    return a.exec();
}









