/*
 * Waiting for values in the future
 *
 * Why
 * Threading is not synchronous
 *
 * How
 * QFutureWatcher - signals and slots based approach
 *
 * I want to be able to communicate with objs that already exists in memory,
 * meaning I want to make a QObject and have a talk to things on the threads.
 */

#include <QCoreApplication>
#include <QDebug>
#include <QtConcurrent>
#include <QFuture>
#include <QFutureWatcher>
#include <QList>
#include "test.h"

void multiply(int &value){
    qInfo() << "Called:" << value;
    value *= 10;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    for(int i{}; i < 100; ++i)
        list << i;

    QFutureWatcher<void> watcher;
    Test test;
    QObject::connect(&watcher, &QFutureWatcher<void>::finished, &test, &Test::finished); // Auto connection "should" work

    QFuture<void> future = QtConcurrent::map(list, &multiply);
    watcher.setFuture(future);

    qInfo() << "Back in main";

    watcher.waitForFinished();  // Blocking

    qInfo() << "Done";
    qInfo() << list;

    return a.exec();
}

// "Test(0x7fff12ea6280) Processing..." print out after "Done"
// Unfortunately, we realy don't have any control over when that signal is actually fired off.
// Meaning you may actually see this "Test(0x7fff12ea6280) Processing..." above "Done".
// You may see it before QList...

// Basically just understand that because this is multithreaded,
// we have zero control over when that signal is going to get fired off.
// But it did indeed fire off.



















