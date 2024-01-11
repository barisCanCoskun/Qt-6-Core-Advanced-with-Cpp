#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT

    QTimer m_timer;
public:
    explicit Test(QObject *parent = nullptr);

signals:

public slots:
    void run();

private slots:
    void timeout();

};

#endif // TEST_H











