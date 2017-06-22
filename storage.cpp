#include "storage.h"
#include <thread>
#include <cstdio>

CStorage* CStorage::instance = 0;

void CStorage::setAll(QByteArray book)
{
    document = QJsonDocument::fromJson(book);

    std::thread th(&CStorage::save, this);
    th.join();
}

void CStorage::save()
{
    if (document.isEmpty())
        return;

    FILE * pFile;
    pFile = fopen ("address_book.json", "wb");
    if (!pFile) {
        qDebug() << trUtf8("Error: cannot open storage");
        return;
    }
    fwrite (document.toJson().toStdString().c_str() , sizeof(char), document.toJson().size(), pFile);
    fflush(pFile);
    fclose (pFile);

    /*
    QFile file("address_book.json");
    if (file.open(QIODevice::WriteOnly))
        file.write(document.toJson());
    else
        qDebug() << "Error: cannot open storage";
    */
}


QByteArray CStorage::getAll()
{
    if (!document.isEmpty())
        return document.toJson();

    QByteArray data;
    QFile file("address_book.json");
    if (file.open(QIODevice::ReadOnly))
    {
        data = file.readAll();
        document = QJsonDocument::fromJson(data);
        file.close();
    }else{
        qDebug() << trUtf8("Error: cannot open data storage");
    }

    if (!data.isEmpty()) {
        return data;
    }else{
        qDebug() << "data is empty";
        return QByteArray();
    }

}
