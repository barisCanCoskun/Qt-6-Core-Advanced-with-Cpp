#ifndef COUNTER_H
#define COUNTER_H

#include<QObject>
#include<QDebug>
#include<QRunnable>
#include<QThread>
#include<QRandomGenerator>

class Counter : public QRunnable
{
    int m_num;
public:
    Counter();
    void setnum(int num);

    // QRunnable interface
public:
    void run();
};

#endif // COUNTER_H





























