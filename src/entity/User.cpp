#include "User.h"

QList<Group*>* User::getGroups(){
    return this->groups;
}

void User::setGroups(QList<Group*>* groups){
    this->groups = groups;
}
