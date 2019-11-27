#ifndef PROGRESSBARDIALOG_H
#define PROGRESSBARDIALOG_H

#include <QObject>
#include <QFutureWatcher>

class ProgressBarDialog : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float progress READ progress NOTIFY progressChanged)
    Q_PROPERTY(bool running READ running NOTIFY runningChanged)

public:
    ProgressBarDialog();
    float progress();
    bool running();

public Q_SLOTS:
    void startComputation();
    void cancelComputation();
private Q_SLOTS:
    void updateProgress(int value);
signals:
    void progressChanged();
    void runningChanged();
private:
    bool m_running = false;
    int m_progressValue = 0;
    QVector<int> vector;
    QObject m_Model;
    QFutureWatcher<void> m_futureWatcher;
};

#endif // PROGRESSBARDIALOG_H
