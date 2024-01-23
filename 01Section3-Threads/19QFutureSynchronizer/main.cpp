/*
 * Sync future values
 *
 * Why
 * We want values in the future in a specific order
 *
 * How
 * QFutureSynchronizer
 *
 */

#include <QCoreApplication>
#include <QDebug>
#include <QtConcurrent>
#include <QThread>
#include <QFuture>
#include <QFutureSynchronizer>

void doStuff(int value){
    for(int i{}; i < 10; ++i){
        QThread::currentThread()->msleep(100);
        qInfo()<< QThread::currentThread() << value << "=" << i;
    }
}

void runThread(){
    QFutureSynchronizer<void> sync;

    for(int i{}; i < 3; ++i)
        sync.addFuture(QtConcurrent::run(doStuff, i));

    // sync.waitForFinished();
    // The destructor of QFutureSynchronizer calls waitForFinished(),
    // providing an easy way to ensure that all futures have finished before returning from a function.
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    runThread();
    qInfo() << "Done";

    return a.exec();
}













