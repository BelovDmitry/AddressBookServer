#ifndef STORAGE_H
#define STORAGE_H

#include <QObject>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QByteArray>
#include <QFile>
#include <QString>

class CStorage: public QObject
{
    Q_OBJECT

public:
    static CStorage* getInstance() {
        if(!instance)
            instance = new CStorage();
        return instance;
    }

    QByteArray getAll();
    void setAll(QByteArray);

private:
    void save();

    static CStorage *instance;
    CStorage() {}
    CStorage( const CStorage& );
    CStorage& operator=( CStorage& );

    QJsonDocument document;
};

#endif // STORAGE_H
