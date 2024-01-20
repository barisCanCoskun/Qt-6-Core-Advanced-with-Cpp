#include "producer.h"

Producer::Producer(QMutex *mutexPtr, QWaitCondition *valueReadyPtr, int *valuePtr, QObject *parent)
    : m_mutexPtr{mutexPtr}, m_valueReadyPtr{valueReadyPtr}, m_valuePtr{valuePtr}
{
    Q_UNUSED(parent);
}

void Producer::run()
{
    qInfo() << "Producer running";
    QThread::currentThread()->msleep(3000);

    m_mutexPtr->lock();

    qInfo() << "Producer creating a value";
    *m_valuePtr = QRandomGenerator::global()->bounded(1000);

    m_mutexPtr->unlock();

    qInfo() << "Producer waking up consumer";
    m_valueReadyPtr->wakeAll();
}
















