/*
 * QtConcurrent::run
 *
 * Why
 * Easily run on a thread
 *
 * How
 * QtConcurrent::run
 *
 */

#include <QCoreApplication>
#include <QDebug>
#include <QtConcurrent>
#include <QThread>
#include <QThreadPool>

void loop(){
    for(int i{}; i < 10; ++i){
        qInfo() << "Loop" << i << "on:" << QThread::currentThread();
    }
}

void test(){
    qInfo() << "Test on:" << QThread::currentThread();
    loop();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    // whenever you're graphical programming, this is called main thread,
    // or the main execution thread or the root thread also called the GUI thread.

    QThreadPool pool;
    // we could do the global instance, but I just want to push it onto
    // a seperate thread pool just to show you that we can.

    QFuture<void> future = QtConcurrent::run(&pool, test);
    // Runs function in a separate thread.

    qInfo() << "Main on:" << QThread::currentThread();

    return a.exec();
}

// we can actually see this running in a threaded fashion.
// What are we not doing, we're not worrying about individual threads,
// we're not worrying about anything like a mutex no complexity at all,
// we're just saying, I want this func "test" and any funcs that it calls "loop" to run out on a thread pool.















