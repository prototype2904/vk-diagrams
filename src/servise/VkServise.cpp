#include "VkServise.h"

VkServise::VkServise(QString access_token)
{
    this->access_token = access_token;

}

QList<Group*>* VkServise::getGroups(int user_id)
{
    QString jsonReply = restClient.sendRequest(VkRequestBuilder::strGroupGet(user_id,access_token));
    JsonError jsonError;
    return JsonParser::getVkGroupsFromStrJson(jsonReply,jsonError);
}

User* VkServise::getUser(int user_id)
{
    QString jsonReply = restClient.sendRequest(VkRequestBuilder::strUserGet(user_id,access_token));
    JsonError jsonError;
    QList <User*>* users = JsonParser::getVkUsersFromStrJson(jsonReply,jsonError);
    if(users->isEmpty()){
        return NULL;
    }
    else{
        users->first()->setGroups(getGroups(users->first()->getId()));
        return users->first();
    }
}

QList<User*>* VkServise::getUsers(QList<int> user_ids)
{
     QList<User*>* users = new QList<User*>();
     foreach (const int & userId, user_ids) {
         User* user = getUser(userId);
         if(user != NULL){
             users->append(user);
         }
     }
     return users;
}

QList<User*>* VkServise::getFriends(int user_id)
{
    QString jsonReply = restClient.sendRequest(VkRequestBuilder::strFrinedsGet(user_id, access_token));
    JsonError jsonError;
    QList <int> vkIds = JsonParser::getFriendsFromStrJson(jsonReply,jsonError);
    return getUsers(vkIds);
}
