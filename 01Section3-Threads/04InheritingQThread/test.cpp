#include "test.h"

Test::Test(QObject *parent)
    : QThread{parent}
{}

void Test::run()
{
    // Notice after 3 seconds nothing happens!
    m_timer.singleShot(3000, this, &Test::test);
    test();
}

void Test::test()
{
    // Notice this gets runs last!
    qInfo() << "TESTING" << currentThread();

    terminate();

    // Bad things happen from here...
    // What do you mean by that?
    // Think of what we've done, we now a thread and we're saying
    // when we run() after 3 secs, we're going to terminate.
    // So anything running on us bec we are a thread is also
    // going to terminate after 3 secs.
    // We have fundamentally just very simply broken
    // the whole point of QThread.
}








