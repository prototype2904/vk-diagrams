#include "userservicefacade.h"
#include "servise/VkServise.h"

UserServiceFacade::UserServiceFacade()
{
    QString access_token = "57ac5d95c287c7935fbd1adbc06ac920994c0712ba7d73079043f21edea79c9397ee549f2e234d16bbc0f";
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
    User* user = getUser(id);
    if(user != NULL){
        ER<User*>* er = new ER<User*>();
        er->addEntity(new Entity<User*>(user));
        return er;
    }
    else{
        return NULL;
    }
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

