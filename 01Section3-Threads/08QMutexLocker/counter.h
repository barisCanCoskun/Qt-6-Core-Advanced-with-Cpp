#ifndef COUNTER_H
#define COUNTER_H

#include<QRunnable>
#include<QThread>
#include<QDebug>
#include<QMutex>
#include<QMutexLocker>

class Counter : public QRunnable
{
public:
    Counter(QMutex *mutexPtr, int *valuePtr);

    // QRunnable interface
public:
    void run();

private:
    QMutex *m_mutexPtr;
    int *m_valuePtr;
};

#endif // COUNTER_H












