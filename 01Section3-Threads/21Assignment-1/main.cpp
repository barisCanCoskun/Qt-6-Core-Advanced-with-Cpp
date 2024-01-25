/*
 * Assignment-1
 *
 * Why
 * Practice what you learned
 *
 * How
 * Counting files in folders
 *
 */

#include <QCoreApplication>
#include <QDebug>
#include <QtConcurrent>
#include <QFuture>
#include <QDirIterator>
#include <QString>

void count(QString path){
    QDirIterator it(path, QDir::Files, QDirIterator::Subdirectories);
    int value{};

    while(it.hasNext()){
        qInfo() << it.next();
        ++value;
    }
    qInfo() << "Found" << value << "files";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QDir dir{QDir::current()};
    QDir dir{QCoreApplication::applicationDirPath()};
    qInfo() << dir.dirName();
    qInfo() << dir.absolutePath();

    dir.cdUp();
    qInfo() << "Abs path:" << dir.absolutePath();
    qInfo() << "Path:" << dir.path();
    qInfo() << "\n";

    QFuture<void> future = QtConcurrent::run(count, dir.absolutePath());
    qInfo() << "Counting files...";

    // do other things

    future.waitForFinished();

    qInfo() << "Done";


    return a.exec();
}


// main takeaway here is all those counting was done on a seperate thread.
// there are multiple reasons you might want to to this:
// count() func is very time consuming, very expensive, if you have a large directory,
// this colud take few seconds, few minutes maybe few hours depending how big dir is
// so you want to be able to do other things in the background...











