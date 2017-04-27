#ifndef VKSERVISE_H
#define VKSERVISE_H
#include "../util/RestClient.h"
#include "../util/VkRequestBuilder.h"
#include "../util/JsonParser.h"
#include "../entity/User.h"

class VkServise
{
private:
    RestClient restClient;
    QString access_token;

public:

    VkServise();
    VkServise(QString access_token);
    User* getUser(int user_id);
    QList<User*> getUsers(QList<int> user_ids);
    QList<VkUser*> getFriends(int user_id);
    VkUser* getVkUser(int user_id);
    QList<VkUser*> getVkUsers(QList <int> user_ids);
    QList<VkGroup*> getVkGroups(int user_id);
    QString getAccess_token() const;
    void setAccess_token(const QString &value);

};

#endif // VKSERVISE_H
