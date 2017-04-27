#include "userservicefacade.h"


UserServiceFacade::UserServiceFacade()
{
    QString access_token = "fb6fe7a6462893ca5bd7c191415c93218300e429986433041f2dbfac803bc6e109e6a686b1354b9f7d994";
    vkServise = new VkServise(access_token);
}

QList<User*> UserServiceFacade::getFriends(User* user)
{
    QList<VkUser*> friends = vkServise->getFriends(user->getVkUser()->getId());
    QList<User*> users;
    foreach(VkUser* vk, friends){
        user = vkServise->getUser(vk->getId());
        users.append(user);
    }
    return users;
}

User* UserServiceFacade::getUser(QString id){
    User * user = vkServise->getUser(id.toInt());
    return user;
}

int UserServiceFacade::getNumOwnGroups(User *center, User *select){

    int ownGroups = 0;
    for(int i = 0; i < center->getVkGroup().size(); i++){
        for(int j = 0; j < select->getVkGroup().size(); j++){
            if(select->getVkGroup().at(j)->getId() == center->getVkGroup().at(i)->getId()){
                ownGroups++;
                break;
            }
        }
    }
    return ownGroups;
}

int UserServiceFacade::getNumOwnFriends(User* center, User* select){

    QList<VkUser*> centerFriends= vkServise->getFriends(center->getVkUser()->getId());
    QList<VkUser*> selectFriends= vkServise->getFriends(select->getVkUser()->getId());
    int ownFriends = 0;
    for(int i = 0; i < centerFriends.size(); i++){
        for(int j = 0; j < selectFriends.size(); j++){
            if(selectFriends.at(j)->getId() == centerFriends.at(i)->getId()){
                ownFriends++;
                break;
            }
        }
    }
    return ownFriends;
}

