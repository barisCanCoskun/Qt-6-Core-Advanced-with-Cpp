#include "manager.h"

Manager::Manager(QObject *parent)
    : QObject{parent}
{
    for(int i{}; i < 5; ++i){
        QThread *thread = new QThread(this);
        // Qt's automatic mem management called the parent child relationship
        thread->setObjectName("Thread " + QString::number(i));
        qInfo() << "Created:" << thread->objectName();
        connect(thread, &QThread::started, this, &Manager::started);
        connect(thread, &QThread::finished, this, &Manager::finished);
        threads.append(thread);
    }
}

void Manager::start()
{
    qInfo() << "Starting Threads...";
    foreach (QThread *thread, threads) {
        qInfo() << "Starting:" << thread->objectName();
        Counter *c = new Counter(); // RAW Pointer!!!
        c->moveToThread(thread);
        connect(thread, &QThread::started, c, &Counter::start);
        thread->start();
    }
}

void Manager::finish()
{
    qInfo() << "Finishing Threads...";
    foreach (QThread *thread, threads) {
        qInfo() << "Finishing:" << thread->objectName();
        thread->quit();
    }
}

void Manager::started()
{
    qInfo() << "Startig" << sender();
    // QThread *thread = qobject_cast<QThread *>(sender());
    if(!sender()) return;
    qInfo() << "Started: " << sender()->objectName();
}

void Manager::finished()
{
    qInfo() << "Finishing" << sender();
    if(!sender()) return;
    qInfo() << "Children length:" << sender()->children().length();
    qInfo() << "Finished:" << sender()->objectName();

    threads.removeAll(sender());
    delete sender();
}
















