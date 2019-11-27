#include "progressbardialog.h"
#include <QtConcurrent/QtConcurrentMap>


ProgressBarDialog::ProgressBarDialog()
{}

void spin(int &iteration)
{
    const int work = 1000 * 1000 * 40;
    for(int j = 0; j < work; ++j)
        iteration *= 2;
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
    vector.clear();
    for(int i = 0; i < 40; ++i)
        vector.append(i);
    const QFuture<void> future = QtConcurrent::map(vector, spin);
    m_futureWatcher.setFuture(future);
    connect(&m_futureWatcher, &QFutureWatcher<void>::progressValueChanged,
            this, &ProgressBarDialog::updateProgress);
}

void ProgressBarDialog::cancelComputation()
{
    m_running = false;
    emit runningChanged();
}

void ProgressBarDialog::updateProgress(int value)
{
    m_progressValue = value;
    emit progressChanged();
}
