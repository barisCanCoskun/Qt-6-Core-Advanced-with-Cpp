#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
#include <QDebug>
#include <QWaitCondition>
#include <QMutex>
#include <QThread>
#include <QRandomGenerator>

class Producer : public QObject
{
    Q_OBJECT
public:
    explicit Producer(QMutex *mutexPtr, QWaitCondition *valueReadyPtr, int *valuePtr, QObject *parent = nullptr);

signals:

public slots:
    void run();

private:
    QMutex *m_mutexPtr;
    QWaitCondition *m_valueReadyPtr;
    int *m_valuePtr;

};

#endif // PRODUCER_H








