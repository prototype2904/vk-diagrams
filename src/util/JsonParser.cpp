#include "JsonParser.h"

JsonParser::JsonParser()
{
}

QList<VkUser> JsonParser::getVkUsersFromStrJson(QString strJsonUsers, JsonError &jsonError)
{

     QList<VkUser> vkUsers;
     QJsonDocument jsonDocumentUsers = QJsonDocument::fromJson(strJsonUsers.toUtf8());

     QJsonObject jsonObjectUsers = jsonDocumentUsers.object();
     if( (!(jsonObjectUsers["response"].isNull()))  && (jsonObjectUsers["response"].isArray()) ) {

          QJsonArray jsonArrayUsers = jsonObjectUsers["response"].toArray();

          foreach (const QJsonValue & value, jsonArrayUsers) {
             QJsonObject jsonObjectUser = value.toObject();
             VkUser vkUser = getUserFromJson(jsonObjectUser);
             vkUsers.append(vkUser);

          }
          jsonError = JSON_NOERROR;
     }
     else {

         jsonError = JSON_ERROR;
     }
     return vkUsers;
}

VkUser JsonParser::getUserFromJson(QJsonObject jsonObjectUser)
{
    VkUser vkUser;

    if( !(jsonObjectUser["first_name"].isNull()) )
        vkUser.setFirstName(jsonObjectUser["first_name"].toString());

    if( !(jsonObjectUser["last_name"].isNull()) )
        vkUser.setLastName(jsonObjectUser["last_name"].toString());

    if( !(jsonObjectUser["id"].isNull()) )
        vkUser.setId(jsonObjectUser["id"].toInt());

    if( !(jsonObjectUser["deactivated"].isNull()) )
        vkUser.setDeactivated(jsonObjectUser["deactivated"].toString());

    if( !(jsonObjectUser["hidden"].isNull()) )
        vkUser.setHidden(jsonObjectUser["hidden"].toString());

    return vkUser;
}



QList<VkGroup> JsonParser::getVkGroupsFromStrJson(QString strJsonGroup, JsonError &jsonError)
{
    QList<VkGroup> vkGroups;

    QJsonDocument jsonDocumentGroups = QJsonDocument::fromJson(strJsonGroup.toUtf8());

    QJsonObject jsonObjectGroups = jsonDocumentGroups.object();
    if (!(jsonObjectGroups["response"].isNull() )) {
        QJsonObject jsonDocumentResponse = jsonObjectGroups["response"].toObject();
        if( (!(jsonDocumentResponse["items"].isNull()))  && (jsonDocumentResponse["items"].isArray()) ) {

            QJsonArray jsonArrayGroups = jsonDocumentResponse["items"].toArray();

            foreach (const QJsonValue & value, jsonArrayGroups) {

                QJsonObject jsonObjectGroup = value.toObject();
                VkGroup vkGroup = getGroupFromJson(jsonObjectGroup);
                vkGroups.append(vkGroup);
            }
             jsonError = JSON_NOERROR;
        }
        else {
             jsonError = JSON_ERROR;
        }
    }
    else {
         jsonError = JSON_ERROR;
    }


    return vkGroups;
}

VkGroup JsonParser::getGroupFromJson(QJsonObject jsonOnjectGroup)
{
    VkGroup vkGroup;

    if( !(jsonOnjectGroup["id"].isNull()) )
        vkGroup.setId(jsonOnjectGroup["id"].toInt());

    if( !(jsonOnjectGroup["name"].isNull()) )
        vkGroup.setName(jsonOnjectGroup["name"].toString());


    return vkGroup;
}

QList<int> JsonParser::getFriendsFromStrJson(QString strJsonFriends, JsonError &jsonError)
{
    QList<int> vkIds;

    QJsonDocument jsonDocumentIds = QJsonDocument::fromJson(strJsonFriends.toUtf8());

    QJsonObject jsonObjectIds = jsonDocumentIds.object();
    if (!(jsonObjectIds["response"].isNull() )) {
        QJsonObject jsonDocumentResponse = jsonObjectIds["response"].toObject();
        if( (!(jsonDocumentResponse["items"].isNull()))  && (jsonDocumentResponse["items"].isArray()) ) {

            QJsonArray jsonArrayIds = jsonDocumentResponse["items"].toArray();

            foreach (const QJsonValue & value, jsonArrayIds) {

                vkIds.append(value.toObject()["id"].toInt());
            }
             jsonError = JSON_NOERROR;
        }
        else {
             jsonError = JSON_ERROR;
        }
    }
    else {
         jsonError = JSON_ERROR;
    }


    return vkIds;
}


