#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QtConcurrent>
#include <QFuture>
#include <QFutureWatcher>
#include <QThread>
#include <QMutex>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

    void process();
    static void multiply(int &value);

signals:

public slots:
    void canceled();
    void finished();
    void progressRangeChanged(int minimum, int maximum);
    void progressTextChanged(const QString &progressText);
    void progressValueChanged(int progressValue);
    void resultReadyAt(int index);
    void resultsReadyAt(int beginIndex, int endIndex);
    void resumed();
    void started();
    void suspended();
    void suspending();

private:
    QFutureWatcher<void> watcher;
    QFuture<void> future;
    QList<int> list;

};

#endif // TEST_H









