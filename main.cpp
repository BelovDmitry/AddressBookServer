#include <QCoreApplication>
#include <QTextCodec>
#include "tcp_server.h"
#include "storage.h"
#include <QObject>

int main(int argc, char *argv[])
{
    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    codec->setCodecForLocale(codec);

    QCoreApplication a(argc, argv);

    CTcpServer server;
    server.start();

    return a.exec();
}
