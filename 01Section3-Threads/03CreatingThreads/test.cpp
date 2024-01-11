#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{}

void Test::run()
{
    qInfo() << "Running" << QThread::currentThread();
    m_timer.singleShot(3000, this, &Test::timeout);
    qInfo() << "Finished" << QThread::currentThread();
}
// we're going to be using asynchronous code, but we're going to
// run this entire class right on a seperate thread.

void Test::timeout()
{
    qInfo() << "Timeout" << QThread::currentThread();
}


















