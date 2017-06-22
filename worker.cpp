#include "worker.h"

CWorker::CWorker(qintptr handle): descriptor(handle)
{}

void CWorker::run()
{
    QTcpSocket *pSocket = new QTcpSocket();
    pSocket->setSocketDescriptor(descriptor);

    pSocket->waitForReadyRead();
    QByteArray message = pSocket->readAll();
    QByteArray response;

    switch (message.at(0))
    {
    case 0x01: // read all
        response.append(QChar(0x01));
        response.append(CStorage::getInstance()->getAll());
        qDebug() << "recive command is read all address book";
        break;
    case 0x02: // write all
        response.append(QChar(0x00));
        message.remove(0,1);
        CStorage::getInstance()->setAll(message);
        qDebug() << "recive command is write all address book";
        break;
    default:
        qDebug() << "Unknown command";
        response.append(QChar(0x00));
        break;
    }

    pSocket->write(response);
    pSocket->waitForBytesWritten();

    pSocket->disconnect();
    pSocket->close();
    pSocket->deleteLater();
}
