#include "counter.h"

Counter::Counter() {}

void Counter::setnum(int num)
{
    m_num = num;
}

void Counter::run()
{
    // QString name = QString("thread # %1").arg(m_num);
    // QThread::currentThread()->setObjectName(name);

    qInfo() << "Starting:" << QThread::currentThread();

    for(int i{}; i < 20; ++i){
        //comment this out to see the threads being reused
        // qInfo() << QThread::currentThread() << "=" << i;
        auto value = static_cast<unsigned long> (QRandomGenerator::global()->bounded(100));
        QThread::currentThread()->msleep(value);
    }

    qInfo() << "Finished:" << QThread::currentThread();
}
























