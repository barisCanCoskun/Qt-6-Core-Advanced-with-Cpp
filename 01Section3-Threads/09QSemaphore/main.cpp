/*
 * Semaphores
 * Why
 * Generalize a mutex
 * Lock and unlock multiple resources
 * How
 * QSemaphore
 *
 */

#include <QCoreApplication>
#include <QDebug>
#include <QSemaphore>
#include <QThread>
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> values{};
    values.resize(10);
    // values.resize(10, 0);

    QSemaphore sema(values.size());
    qInfo() << values;

    QThread thread1;
    thread1.setObjectName("Thread 1");
    QThread thread2;
    thread2.setObjectName("Thread 2");

    Worker worker1(&sema, &values);
    worker1.moveToThread(&thread1);
    Worker worker2(&sema, &values);
    worker2.moveToThread(&thread2);

    QObject::connect(&thread1, &QThread::started, &worker1, &Worker::run);
    QObject::connect(&thread2, &QThread::started, &worker2, &Worker::run);

    thread1.start();
    thread2.start();

    return a.exec();
}






















