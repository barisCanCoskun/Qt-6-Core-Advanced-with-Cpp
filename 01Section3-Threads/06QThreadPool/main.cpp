/*
 * Thread Pools
 * Why
 * We want multiple REUSABLE threads
 * How
 * QThreadPool and QRunnable
 *
 * QThreadPool is a manager class that manages a list of threads.
 * QRunnable represents work that we're going to put into that thread pool.
 * When our process is created under the hood Qt creates a thread pool.
 * We would take work in the form of a QRunnable and send it to the
 * thread pool, who would put it randomly on a thread, do the work and then it's done.
 * If we used multiple inheritance, we could get a signal and slot back.
 * QRunnable is not a QObject.
 */

#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QThreadPool>
#include "counter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    QThreadPool *pool = QThreadPool::globalInstance();
    // it's going to give me a pointer to the already existing thread pool.
    qInfo() << pool->maxThreadCount() << "Threads available";

    for(int i{}; i < 100; ++i){
        Counter *c = new Counter();
        // c->setnum(i);
        c->setAutoDelete(true);
        // it should be set by default, but make sure it is set to true
        // just in case Qt decides to change their code base.
        // So when the thread pool is done with this,
        // it will automatically delete that pointer for us.
        // We dont have to worry about mem management.

        pool->start(c);
    }

    return a.exec();
}






















