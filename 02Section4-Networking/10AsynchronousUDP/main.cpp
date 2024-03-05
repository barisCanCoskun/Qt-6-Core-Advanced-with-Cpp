/*
 * Asynchronous UDP
 *
 * Why
 * We want to send and receive and not care about a connection
 * This is how we normally work with it
 *
 * How
 * Remember slots block!
 *
 * Major Takeaway from this section:
 * UDP will bind to a port where TCP will connect to a server.
 *
 * As this program is running, really stop and think. Sb. out there is going to say,
 * I need a multithreaded TCP, do you really?, though, bec. asynchronous runs very smoothly and
 * most of the time when you're doing socket programming, you're not actually pegging that CPU,
 * you're not filling up all of that RAM, meaning you can basically just sit back and wait for
 * some network event. In terms of CS, that time you spend waiting for some network event,
 * it is an eternity and you have all those resources available to you asynchronously
 * using signals and slots.
 *
 */

#include <QCoreApplication>
#include <QThread>
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread::currentThread()->setObjectName("Main Thread");

    Worker worker;
    worker.start();

    return a.exec();
}










