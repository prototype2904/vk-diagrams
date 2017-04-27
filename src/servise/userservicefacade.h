#ifndef USERSERVICEFACADE_H
#define USERSERVICEFACADE_H
#include <er_diagram.h>
#include <node.h>
#include <servise/VkServise.h>
#include <QtWidgets>
#include <QtWidgets/QDialog>


template <typename T> class Er;
class VkServise;

class UserServiceFacade
{
public:
    QList<User*> getFriends(User* user);
    User* getUser(QString id);
    int getNumOwnFriends(User* center, User *select);
    int getNumOwnGroups(User* center, User *select);
    UserServiceFacade();
private:
    VkServise *vkServise;
};

#endif // USERSERVICEFACADE_H
