#include "counter.h"

Counter::Counter(QMutex *mutexPtr, int *valuePtr)
    : m_mutexPtr{mutexPtr}, m_valuePtr{valuePtr}
{

}

void Counter::run()
{
    // Wait until we can do stuff...

    m_mutexPtr->lock(); // We will wait until we can lock!
    // what this does is it basically says, I'm going to use that mutex doorway
    // and open it, walk through the door, shut it and lock it
    // so no one else can open that door while I'm busy

    // Our code here

    // we want to make sure that the time spent with that mutex lock is
    // as minimal as possible in production code,
    // bec any thread which is out there also trying to use this lock mechanism,
    // they're going to stop functioning until they can actually lock.
    // It becomes a blocking mechanism.

    QThread::currentThread()->msleep(50);
    ++(*m_valuePtr);
    qInfo() << *m_valuePtr << QThread::currentThread();

    m_mutexPtr->unlock(); // Other threads can lock
}


















