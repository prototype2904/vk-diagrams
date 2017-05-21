#ifndef USER_H
#define USER_H
#include <QString>
#include "entity/vk/VkGroup.h"
#include "entity/User.h"

class User;

class VkUser : public User{
private:
    int _id;

    QString _firstName;
    QString _lastName;
    QString _deactivated;
    QString _hidden;
public:
    VkUser();
    VkUser(QString f, QString l, int i):_firstName(f), _lastName(l), _id(i){}
    void setId(int id);
    QString getFirstName() const;
    void setFirstName(const QString &firstName);
    QString getLastName() const;
    void setLastName(const QString &lastName);
    QString getDeactivated() const;
    void setDeactivated(const QString &deactivated);
    QString getHidden() const;
    void setHidden(const QString &hidden);

    int getId();
    QString getFio();
};

#endif // USER_H
