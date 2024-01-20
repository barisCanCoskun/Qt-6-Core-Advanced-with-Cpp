#ifndef WIDGET_H
#define WIDGET_H

#include <QObject>
#include <QDebug>
#include <QRunnable>
#include <QThread>

class Widget : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Widget(QObject *parent = nullptr);

signals:
    void started();
    void finished();
    void update(int i);

public slots:
    void workStarted();
    void workFinished();
    void workReady(int i);

    // QRunnable interface
public:
    void run();

    bool getIsSender() const;
    void setIsSender(bool newIsSender);

private:
    bool m_isSender;
    bool m_isSenderActive;
};

#endif // WIDGET_H













