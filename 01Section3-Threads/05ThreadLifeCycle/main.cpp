/*
 * Thread lifecycle
 * Why
 * Threads might not live forever
 * How
 * Threaded code
 *
 */
#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include "manager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QThread::currentThread()->setObjectName("Main Thread");

    Manager m;
    m.start();

    m.finish();

    return a.exec();
}

















