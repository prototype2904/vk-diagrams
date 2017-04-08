#include "VkRequestBuilder.h"

VkRequestBuilder::VkRequestBuilder()
{
}

QString VkRequestBuilder::strUsersGet(QList<int> user_id, QString access_token)
{
    QString strUrl = "https://api.vk.com/method/users.get?user_ids=";
    foreach (const int & value, user_id) {
         strUrl+= QString::number(value) + ',';
    }

    strUrl.remove(strUrl.size()-1,1); //удаляем лишнюю запятую

    if( !(access_token.isEmpty()) ) {
        strUrl+="&access_token"
                +access_token;
    }

    strUrl+="&v=5.52";
    return strUrl;
}

QString VkRequestBuilder::strUserGet(int user_id, QString access_token)
{
    QString strUrl = "https://api.vk.com/method/users.get?user_id="
                    +QString::number(user_id);


    if( !(access_token.isEmpty()) ) {
        strUrl+="&access_token"
                +access_token;
    }

    strUrl+="&v=5.52";
    return strUrl;
}

QString VkRequestBuilder::strGroupGet(int user_id,
                                      QString access_token,
                                      VkRequestBuilder::Extended extended)
{
    int iExtended = (extended == YES_EXTENDED) ? 1  : 0;
    QString strUrl = "https://api.vk.com/method/groups.get?user_id="
                    +QString::number(user_id)
                    +"&extended="
                    +QString::number(iExtended)
                    +"&access_token="
                    +access_token
                    +"&v=5.52";
    return strUrl;

}

QString VkRequestBuilder::strFrinedsGet(int user_id, QString access_token) {
    QString strUrl = "https://api.vk.com/method/friends.get?user_id="
                    +QString::number(user_id)
                    +"&fields="
                    +"first_name,last_name"
                    +"&access_token="
                    +access_token
                    +"&v=5.52";
    return strUrl;
}

