#include "counter.h"

Counter::Counter(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "Constructed";
}

Counter::~Counter()
{
    qInfo() << this << "Destructed";
}

void Counter::start()
{
    for(int i{}; i < 20; ++i){
        qInfo() << QThread::currentThread()->objectName() << " = " << i;
        auto value = static_cast<unsigned long>(QRandomGenerator::global()->bounded(500));
        QThread::currentThread()->msleep(value);
        qInfo() << QThread::currentThread()->objectName() << " = " << i << "Completed";
    }

    qInfo() << this << "Completed!!";
    deleteLater();
    // what this does is it schedules this obj for deletion,
    // Qt has an internal garbage collector
    // and that's going to schedule that obj and get rid of it
}












