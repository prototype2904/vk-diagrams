#ifndef USERSERVICEFACADE_H
#define USERSERVICEFACADE_H
#include <er_diagram.h>
#include <node.h>
#include <servise/userservice.h>
#include <QtWidgets>
#include <QtWidgets/QDialog>


class UserService;
template<typename T> class Entity;
template<typename T> class ER;

class UserServiceFacade
{
public:
    QList<User*>* getFriends(User* user);
    User* getUser(QString id);
    ER<User*>* createER(QString id);
    int getNumOwnFriends(User* center, User *select);
    int getNumOwnGroups(User* center, User *select);
    UserServiceFacade();
private:
    UserService *userService;
};

#endif // USERSERVICEFACADE_H
