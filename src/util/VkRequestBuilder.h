#ifndef VKREQUESTBUILDER_H
#define VKREQUESTBUILDER_H
#include <QString>
#include <QList>
class VkRequestBuilder
{
private:

public:
    enum Extended {
        NO_EXTENDED = 0,
        YES_EXTENDED = 1
    };
    VkRequestBuilder();
    static QString strUsersGet(QList<int> user_id, QString access_token = "");
    static QString strUserGet(int user_id, QString access_token = "");

    //TODO pasha можно добавить фильтры
    static QString strGroupGet(int user_id , QString access_token, Extended extended = YES_EXTENDED);
    static QString strFrinedsGet(int user_id, QString access_token);
};

#endif // VKREQUESTBUILDER_H
