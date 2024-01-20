/*
 * Wait Conditions
 *
 * Why
 * Sync threads
 *
 * How
 * QWaitCondition
 *
 */

#include <QCoreApplication>
#include <QDebug>
#include <QWaitCondition>
#include <QMutex>
#include <QThread>
#include "producer.h"
#include "consumer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QWaitCondition valueReady;
    QMutex mutex;
    QThread producerThread;
    QThread consumerThread;
    int value{};

    Producer producer(&mutex, &valueReady, &value);
    Consumer consumer(&mutex, &valueReady, &value);

    producer.moveToThread(&producerThread);
    consumer.moveToThread(&consumerThread);

    QObject::connect(&producerThread, &QThread::started, &producer, &Producer::run);
    QObject::connect(&consumerThread, &QThread::started, &consumer, &Consumer::run);

    producerThread.start();
    consumerThread.start();



    return a.exec();
}











