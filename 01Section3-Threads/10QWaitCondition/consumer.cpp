#include "consumer.h"

Consumer::Consumer(QMutex *mutexPtr, QWaitCondition *valueReadyPtr, int *valuePtr, QObject *parent)
    : m_mutexPtr{mutexPtr}, m_valueReadyPtr{valueReadyPtr}, m_valuePtr{valuePtr}
{
    Q_UNUSED(parent);
}

void Consumer::run()
{
    qInfo() << "Cosumer running";
    m_mutexPtr->lock();
    qInfo() << "Consumer locked the mutex";

    if(!(*m_valuePtr)){
        qInfo() << "Consumer is waiting on a value";  // the producer hasn't actually produced yet
        m_valueReadyPtr->wait(m_mutexPtr);  // Releases the lockedMutex and waits on the wait condition.
    }

    qInfo() << "Consuming:" << *m_valuePtr;

    // We're NOT unlocking...
    // m_mutexPtr->unlock();
    // Because of the wait function above.
}















