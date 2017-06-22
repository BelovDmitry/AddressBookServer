#ifndef WORKER_H
#define WORKER_H

#include <QRunnable>
#include <QTcpSocket>
#include <QDebug>

#include "storage.h"

class CWorker: public QRunnable
{
public:
    CWorker(qintptr handle);
    ~CWorker() = default;

    void run();

private:
    qintptr descriptor;
};

#endif // WORKER_H
