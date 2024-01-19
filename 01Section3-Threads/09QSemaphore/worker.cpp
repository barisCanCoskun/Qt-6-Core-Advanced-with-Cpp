#include "worker.h"

Worker::Worker(QSemaphore *semaPtr, QList<int> *valuesPtr, QObject *parent)
    : QObject{parent}, m_semaPtr{semaPtr}, m_valuesPtr{valuesPtr}
{}

void Worker::run()
{
    qInfo() << "Running" << QThread::currentThread();
    int max = QRandomGenerator::global()->bounded(1, m_valuesPtr->size());

    qInfo() << "Acquiring" << max << "elements of list in" << QThread::currentThread();
    m_semaPtr->acquire(max);

    qInfo() << "Available" << m_semaPtr->available() << "elements of list in" << QThread::currentThread();
    for(int i{}; i < max; ++i){
        qInfo() << "Modify" << i << "th element of list in" << QThread::currentThread();
        int value{QRandomGenerator::global()->bounded(100)};
        m_valuesPtr->replace(i, value);
        qInfo() << *m_valuesPtr;
        QThread::currentThread()->msleep(250);
    }

    qInfo() << "Releasing" << max << "elements of list in" << QThread::currentThread();
    m_semaPtr->release(max);

}






























