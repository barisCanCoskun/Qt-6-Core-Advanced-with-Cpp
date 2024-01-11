/*
 * Synchronous example
 * Why
 * Understand what is happening when we run code
 * How
 * Sync code
 *
 */

#include <QCoreApplication>
#include <QThread>
// Why do u want QThread if u r running Synchronous code ?
// Want to show u the current thread we're on and
// we need to access it through.
// QThread is the Qt class which represents a platform
// independent way to manage threads.

void test(){
    qInfo() << "Testing" << QThread::currentThread();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    // QThread is actually a Qt object under the hood.
    qInfo() << "Starting" << QThread::currentThread();

    test();
    qInfo() << "Finished" << QThread::currentThread();

    return a.exec();
}

















