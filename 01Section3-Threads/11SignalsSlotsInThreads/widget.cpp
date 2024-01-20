#include "widget.h"

Widget::Widget(QObject *parent)
    : m_isSender{false}, QObject{parent}
{}

void Widget::workStarted()
{
    qInfo() << this << "Started" << sender();
}

void Widget::workFinished()
{
    qInfo() << this << "Finished" << sender();
    m_isSenderActive = false;
}

void Widget::workReady(int i)
{
    qInfo() << this << "Work" << i << sender();
}

void Widget::run()
{
    if(m_isSender){
        qInfo() << this << "Starting work...";
        emit started();

        for(int i{}; i < 10; ++i){
            qInfo() << this << "Update...";
            emit update(i);
            QThread::currentThread()->msleep(500);
        }
        qInfo() << this << "Finishing work...";
        emit finished();
    }
    else{
        qInfo() << this << "Waiting for signals...";
        m_isSenderActive = true;
        while(m_isSenderActive)
            QThread::currentThread()->msleep(100);
    }

    qInfo() << this << "Done";
}

bool Widget::getIsSender() const
{
    return m_isSender;
}

void Widget::setIsSender(bool newIsSender)
{
    m_isSender = newIsSender;
}










