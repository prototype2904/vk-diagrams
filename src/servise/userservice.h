#ifndef USERSERVICE_H
#define USERSERVICE_H

#include"entity/User.h"

class User;

class UserService
{
public:
    UserService();
    virtual User* getUser(int user_id) = 0;
    virtual QList<User*>* getUsers(QList<int> user_ids) = 0;
    virtual QList<User*>* getFriends(int user_id) = 0;
    virtual QList<Group*>* getGroups(int user_id) = 0;
};

#endif // USERSERVICE_H
