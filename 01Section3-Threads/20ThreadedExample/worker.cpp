#include "worker.h"

Worker::Worker(QObject *parent)
    : QObject{parent}
{
    qInfo() << this << "Constructed on" << QThread::currentThread();
    connect(&m_timer, &QTimer::timeout, this, &Worker::timeout);
    m_timer.setInterval(1000);
}

Worker::~Worker()
{
    qInfo() << this << "Destructed on" << QThread::currentThread();
}

void Worker::start()
{
    qInfo() << this << "Started on" << QThread::currentThread();
    m_timer.start();
    m_loop.exec();  // Processing stays here
    // This is going to seem as if it's blocking our execution, but it's really not.
    // We're still available for signals and slots

    qInfo() << this << "Loop finished on" << QThread::currentThread();

    // this->deleteLater();  // may hold on to this for a while
    delete this;
}

void Worker::stop()
{
    qInfo() << this << "Stopping on" << QThread::currentThread();
    m_timer.stop();
    m_loop.quit();
    qInfo() << this << "Stopped on" << QThread::currentThread();
}

void Worker::timeout()
{
    qInfo() << this << "Timeout on" << QThread::currentThread();
}









