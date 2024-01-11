/*
 * Threaded example
 * Why
 * Understand what is happening when we run code
 * How
 * Threaded code
 *
 */

#include <QCoreApplication>
#include <QThread>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    // QThread is actually a Qt object under the hood.
    qInfo() << "Starting" << QThread::currentThread();

    QThread worker;
    worker.setObjectName("Worker Thread");

    Test test;
    test.moveToThread(&worker);
    test.connect(&worker, &QThread::started, &test, &Test::run);
    // worker.connect(&worker, &QThread::started, &test, &Test::run);
    // QObject::connect(&worker, &QThread::started, &test, &Test::run);

    worker.start();

    qInfo() << "Finished" << QThread::currentThread();

    return a.exec();
}

















