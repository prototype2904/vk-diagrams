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

 class JsonParser
{
public:

    JsonParser();
    static QList<VkUser*> getVkUsersFromStrJson(QString strJsonUsers, JsonError &jsonError);
    static VkUser* getUserFromJson(QJsonObject jsonObjectUser);

    static QList<VkGroup*> getVkGroupsFromStrJson(QString strJsonGroup, JsonError &jsonError);
    static VkGroup* getGroupFromJson(QJsonObject jsonOnjectGroup);

    static QList<int> getFriendsFromStrJson(QString strJsonFriends, JsonError &jsonError);


};

#endif // JSONSERVICE_H
