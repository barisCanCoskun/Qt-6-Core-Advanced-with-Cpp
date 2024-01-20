#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>
#include <QDebug>
#include <QWaitCondition>
#include <QMutex>
#include <QThread>

class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QMutex *mutexPtr, QWaitCondition *valueReadyPtr, int *valuePtr, QObject *parent = nullptr);

signals:

public slots:
    void run();

private:
    QMutex *m_mutexPtr;
    QWaitCondition *m_valueReadyPtr;
    int *m_valuePtr;

};

#endif // CONSUMER_H









