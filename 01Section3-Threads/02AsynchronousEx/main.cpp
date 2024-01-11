/*
 * Asynchronous example
 * Why
 * Understand what is happening when we run code
 * How
 * Async code
 *
 */

#include <QCoreApplication>
#include <QThread>
#include <QTimer>
// QTimer is a class that allows you to do repetitive
// and single shot timers.
// It's a way of saying, I want to do sth in the future and
// then uses a signal and slot mechanism to notify  you
// when that time is up.

void test(){
    qInfo() << "Testing" << QThread::currentThread();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    // QThread is actually a Qt object under the hood.
    qInfo() << "Starting" << QThread::currentThread();

    QTimer timer;
    timer.singleShot(3000, &test);
    // singleshot means we're going to wait and then
    // execute one and only once.
    // We want to do this a certain time in the future.
    qInfo() << "Finished" << QThread::currentThread();

    // When we run the program it says starting, finished
    // and then testing , so this looks like a multithreaded app,
    // but the thread we're running on is the main thread.
    // This is what he means by asynchronous code.
    // All runs on the same thread, but it can appear as
    // if it is running in some other thread or some part of the app.

    // What is the real advantage of asynchronous code ?
    // Basically that you can save some resources by not spinning up
    // a seperate thread. You can just use the space
    // in the current thread that's not being consumed by the CPU.

    return a.exec();
}

















