#ifndef VKSERVISE_H
#define VKSERVISE_H
#include "../util/RestClient.h"
#include "../util/VkRequestBuilder.h"
#include "../util/JsonParser.h"
#include "servise/userservice.h"

class VkServise : public UserService
{
private:
    RestClient restClient;
    QString access_token;
public:

    VkServise();
    VkServise(QString access_token);
    QList<Group*>* getGroups(int user_id);
    User* getUser(int user_id);
    QList<User*>* getUsers(QList<int> user_ids);
    QList<User*>* getFriends(int user_id);
};

#endif // VKSERVISE_H
