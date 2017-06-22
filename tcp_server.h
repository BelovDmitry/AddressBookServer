#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <QDebug>
#include <QObject>
#include <QThreadPool>
#include <QTcpServer>
#include <QHostAddress>

#include "worker.h"

class CTcpServer: public QTcpServer
{
Q_OBJECT
public:
    CTcpServer(QObject *parent = Q_NULLPTR);
    ~CTcpServer() = default;

    void start();
    void incomingConnection(qintptr handle);
    void setStorage(CStorage&);

private:
    QThreadPool *threadPool;
};


#endif // TCP_SERVER_H
