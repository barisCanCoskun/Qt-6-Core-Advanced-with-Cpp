#include "worker.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{}

void Worker::work()
{
    for(int i{}; i < 10; ++i){
        qInfo() << "Work" << i << QThread::currentThread();
        QThread::currentThread()->msleep(1000);
    }
}
























