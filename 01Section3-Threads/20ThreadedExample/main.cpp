/*
 * Threaded Example
 *
 * Why
 * We want to see a simple example bringing it alltogether
 *
 * How
 * Manager controller workers
 *
 * Bringing everything together, using threading and asynchronous
 *
 */

#include <QCoreApplication>
#include <QtConcurrent>
#include <QTextStream>
#include <QString>
#include "manager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Manager manager;

    qInfo() << "Type START to start";
    qInfo() << "Type QUIT to quit";
    QTextStream cin(stdin);

    do{
        QString command;
        cin >> command;

            if(command.toUpper() == "START") manager.process();
            if(command.toUpper() == "QUIT") manager.quit();

    }while(true);

    return a.exec();
}












