#include "counter.h"

Counter::Counter(QMutex *mutexPtr, int *valuePtr)
    : m_mutexPtr{mutexPtr}, m_valuePtr{valuePtr}
{

}

void Counter::run()
{
    // Wait until we can do stuff...

    QMutexLocker locker(m_mutexPtr);

    QThread::currentThread()->msleep(50);
    ++(*m_valuePtr);
    qInfo() << *m_valuePtr << QThread::currentThread();

}


















