/*
 * Iterate over Future VALUES
 *
 * Why
 * We want to sync values
 *
 * How
 * QFutureIterator
 *
 */

#include <QCoreApplication>
#include <QDebug>
#include <QtConcurrent>
#include <QFuture>
#include <QFutureWatcher>
#include <QFutureIterator>
#include <QList>

int multiply(const int &value){
    qInfo() << "Called:" << value;
    return (value * 10);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int> list;
    for(int i{}; i < 100; ++i)
        list << i;

    // Do stuff async -----------------------
    QFutureWatcher<int> watcher;
    QFuture<int> future = QtConcurrent::mapped(list, &multiply);
    watcher.setFuture(future);

    // Blocking style -----------------------
    watcher.waitForFinished();

    // Java style -----------------------
    QFutureIterator<int> iter(future);
    while(iter.hasNext())
        qInfo() << "Java:" << iter.next();

    // Index style (normal c++) -----------------------
    for(int i; i < future.results().size(); ++i)
        qInfo() << "Index" << i << ":" << future.resultAt(i);

    // Qt style -----------------------
    foreach (int result, future.results()) {
        qInfo() << "Qt:" << result;
    }

    // STD  -----------------------
    QList<int> values = future.results();
    for(auto it{values.begin()}; it != values.end(); ++it)
        qInfo() << "STD:" << *it;

    // another way for me
    for(const auto &v: future.results())
        qInfo() << "STD-rangeBased:" << v;


    qInfo() << "Done";

    return a.exec();
}
















