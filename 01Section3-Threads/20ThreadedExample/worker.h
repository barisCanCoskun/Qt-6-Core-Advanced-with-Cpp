#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QDebug>
#include <QEventLoop>
#include <QTimer>
#include <QThread>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    ~Worker();

signals:
public slots:
    void start();
    void stop();
    void timeout();

private:
    QTimer m_timer;
    QEventLoop m_loop;

};

#endif // WORKER_H







