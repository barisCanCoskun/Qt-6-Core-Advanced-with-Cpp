/*
 * Mutex
 * Why
 * We want to protect an obj from thead issues
 * How
 * QMutex
 *
 * Two threads updating the same thing at the same time
 *
 */

#include <QCoreApplication>
#include <QDebug>   // for legacy purposes
#include <QThread>
#include <QThreadPool>
#include <QMutex>
#include "counter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    QThreadPool *pool{QThreadPool::globalInstance()};

    QMutex mutex;
    int value{};
    qInfo() << pool->maxThreadCount() << "Threads available";

    for(int i{}; i < 100; ++i){
        Counter *c{new Counter(&mutex, &value)};
        c->setAutoDelete(true);
        pool->start(c);
    }

    return a.exec();
}

// In help mode:
// The QMutex class provides access serialization between threads.

// The purpose of a QMutex is to protect an obj, data structure or
// section of code so that only one thread can access it at a time











