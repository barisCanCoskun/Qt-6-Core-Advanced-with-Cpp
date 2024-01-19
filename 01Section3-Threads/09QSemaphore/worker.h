#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QSemaphore>
#include <QList>
#include <QDebug>
#include <QThread>
#include <QRandomGenerator>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QSemaphore *semaPtr, QList<int> *valuesPtr, QObject *parent = nullptr);

signals:

public slots:
    void run();

private:
    QSemaphore *m_semaPtr;
    QList<int> *m_valuesPtr;

};

#endif // WORKER_H






















