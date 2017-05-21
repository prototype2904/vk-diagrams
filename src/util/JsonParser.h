#ifndef JSONSERVICE_H
#define JSONSERVICE_H

#include "../entity/vk/VkUser.h"
#include "../entity/vk/VkGroup.h"
#include "enums.h"
#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QList>
#include <QDebug>
#include "entity/User.h"
#include "entity/group.h"

class User;
class Group;

 class JsonParser
{
public:

    JsonParser();
    static QList<User*>* getVkUsersFromStrJson(QString strJsonUsers, JsonError &jsonError);
    static User* getUserFromJson(QJsonObject jsonObjectUser);

    static QList<Group*>* getVkGroupsFromStrJson(QString strJsonGroup, JsonError &jsonError);
    static VkGroup* getGroupFromJson(QJsonObject jsonOnjectGroup);

    static QList<int> getFriendsFromStrJson(QString strJsonFriends, JsonError &jsonError);


};

#endif // JSONSERVICE_H
