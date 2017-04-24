#ifndef REQUESTER_H
#define REQUESTER_H
#include <QObject>
#include <QtNetwork>
#include <QNetworkReply>
#include <QDebug>
#include <QEventLoop>

#include "JsonParser.h" //TODO DELETE
#include "../entity/User.h"

class RestClient: public QObject
{
    Q_OBJECT
private:
    QNetworkAccessManager *manager;
public:
    RestClient();
    RestClient(QString host);

    QString sendRequest(const QString &requestUrl);

    bool onFinishRequest(QNetworkReply *reply);
};

#endif // REQUESTER_H
