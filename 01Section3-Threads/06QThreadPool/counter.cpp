#include "counter.h"

Counter::Counter() {}

void Counter::run()
{
    qInfo() << "Starting:" << QThread::currentThread();

    for(int i{}; i < 20; ++i){
        qInfo() << QThread::currentThread() << "=" << i;
        auto value = static_cast<unsigned long> (QRandomGenerator::global()->bounded(100));
        QThread::currentThread()->msleep(value);
    }

    qInfo() << "Finished:" << QThread::currentThread();
}
























