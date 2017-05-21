#include "userservicefacade.h"
#include "servise/VkServise.h"

UserServiceFacade::UserServiceFacade()
{
    QString access_token = "75314cff911e687ce2bfe8f8f79cafce6221be8b65464ab7261f3e77ca3f0e7b3cfb3ea6b823c6feb6e53";
    userService = new VkServise(access_token);
}

QList<User*>* UserServiceFacade::getFriends(User* user)
{
    return userService->getFriends(user->getId());
}

User* UserServiceFacade::getUser(QString id){
    return userService->getUser(id.toInt());
}

ER<User*>* UserServiceFacade::createER(QString id){
    ER<User*>* er = new ER<User*>();
    er->addEntity(new Entity<User*>(getUser(id)));
    return er;
}

int UserServiceFacade::getNumOwnGroups(User *center, User *select){

    int ownGroups = 0;
    for(int i = 0; i < center->getGroups()->size(); i++){
        for(int j = 0; j < select->getGroups()->size(); j++){
            if(select->getGroups()->at(j)->getId() == center->getGroups()->at(i)->getId()){
                ownGroups++;
                break;
            }
        }
    }
    return ownGroups;
}

int UserServiceFacade::getNumOwnFriends(User* center, User* select){

    QList<User*>* centerFriends= userService->getFriends(center->getId());
    QList<User*>* selectFriends= userService->getFriends(select->getId());
    int ownFriends = 0;
    for(int i = 0; i < centerFriends->size(); i++){
        for(int j = 0; j < selectFriends->size(); j++){
            if(selectFriends->at(j)->getId() == centerFriends->at(i)->getId()){
                ownFriends++;
                break;
            }
        }
    }
    return ownFriends;
}

