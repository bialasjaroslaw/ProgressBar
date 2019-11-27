#include "progressbardialog.h"
#include <QtConcurrent/QtConcurrentMap>


ProgressBarDialog::ProgressBarDialog()
{}

void spin(int &iteration)
{
    const int work = 1000 * 1000 * 40;
    volatile int v = 0;
    for(int j = 0; j < work; ++j)
        ++v;
}

float ProgressBarDialog::progress()
{
    return m_progressValue;
}

bool ProgressBarDialog::running()
{
    return m_running;
}

void ProgressBarDialog::startComputation()
{
    m_running = true;
    emit runningChanged();
    // Prepare the vector
    QVector<int> vector;
    for(int i = 0; i < 40; ++i)
        vector.append(i);
//    const QFuture<void> future = QtConcurrent::map(vector, spin);
    //    m_futureWatcher.setFuture(future);
}

void ProgressBarDialog::cancelComputation()
{
    m_running = false;
    emit runningChanged();
}
