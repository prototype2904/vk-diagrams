#include "RestClient.h"


RestClient::RestClient()
{
    manager = new QNetworkAccessManager(this);
}
QString RestClient::sendRequest(const QString &requestUrl){

    QEventLoop loop;



    QNetworkReply *reply = manager->get(QNetworkRequest(QUrl(requestUrl)));
    QObject::connect(reply, SIGNAL(finished()),
              &loop, SLOT( quit() ));
    loop.exec();

    if (onFinishRequest(reply)) {
         QString strJsonReply = (QString)reply->readAll();
         return strJsonReply;
    }
    else {
        //TODO pasha обработчик ошибок
        //Что?
        //a)повторить запрос
        //b)выкинуть пользователю
    }

}

bool RestClient::onFinishRequest(QNetworkReply *reply)
{
    QNetworkReply::NetworkError replyError = reply->error();
    if (replyError == QNetworkReply::NoError ) {
        int code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        if ((code >=200) && (code < 300)) {
            return true;
        }
    }
    return false;
}




