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
    // This is the thing I really want to point out here is when you call that,
    // it means it's going to enter the event loop and wait until exit is called,
    // meaning this worker is essentially consuming that thread.
    // And the only thing that's going to run inside this worker on that thread is
    // going to be asynchronous calls such as our timer's timeout().

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

// remember signals and slots are also asynchronous,
// but it's also highly dependent on how they're called.
// Here he means Qt::QueuedConnection












