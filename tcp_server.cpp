#include "tcp_server.h"

CTcpServer::CTcpServer(QObject *parent): QTcpServer(parent)
{
    threadPool = new QThreadPool(this);
    threadPool->setMaxThreadCount(10);
}

void CTcpServer::start()
{
    if (listen(QHostAddress::Any, 12345))
        qDebug() << "Listening";
    else
        qDebug() << "Error: " << errorString();
}

void CTcpServer::incomingConnection(qintptr handle)
{
    qDebug() << "new connection";

    CWorker *worker = new CWorker(handle);
    threadPool->start(worker);
}
