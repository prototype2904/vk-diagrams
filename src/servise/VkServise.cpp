#include "VkServise.h"


QString VkServise::getAccess_token() const
{
    return access_token;
}

void VkServise::setAccess_token(const QString &value)
{
    access_token = value;
}

VkServise::VkServise(QString access_token)
{
    this->access_token = access_token;

}

VkUser VkServise::getVkUser(int user_id)
{
    QString jsonReply = restClient.sendRequest(VkRequestBuilder::strUserGet(user_id,access_token));

    JsonError jsonError;

    QList <VkUser> users = JsonParser::getVkUsersFromStrJson(jsonReply,jsonError);

    return users.at(0);

}

QList<VkUser> VkServise::getVkUsers(QList<int> user_ids)
{
    QString jsonReply = restClient.sendRequest(VkRequestBuilder::strUsersGet(user_ids,access_token));

    JsonError jsonError;

    QList <VkUser> users = JsonParser::getVkUsersFromStrJson(jsonReply,jsonError);

    return users;
}

QList<VkGroup> VkServise::getVkGroups(int user_id)
{
    QString jsonReply = restClient.sendRequest(VkRequestBuilder::strGroupGet(user_id,access_token));

    JsonError jsonError;

    QList <VkGroup> groups = JsonParser::getVkGroupsFromStrJson(jsonReply,jsonError);

    return groups;

}

User VkServise::getUser(int user_id)
{
    User user;
    VkUser vkuser = getVkUser(user_id);
    QList<VkGroup> groups = getVkGroups(user_id);
    user.setVkUser(vkuser);
    user.setVkGroup(groups);
    return user;

}

QList<User> VkServise::getUsers(QList<int> user_ids)
{
     QList<User> users;
     foreach (const int & userId, user_ids) {
         User user = getUser(userId);

         users.append(user);
     }
     return users;
}

QList<VkUser> VkServise::getFriends(int user_id)
{

    QString jsonReply = restClient.sendRequest(VkRequestBuilder::strFrinedsGet(user_id, access_token));

    JsonError jsonError;

    QList <int> vkIds = JsonParser::getFriendsFromStrJson(jsonReply,jsonError);

    QList<VkUser> friends = getVkUsers(vkIds);

    return friends;

}

