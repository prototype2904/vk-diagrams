#ifndef USER_H
#define USER_H
#include <QString>


class VkUser
{
private:
    int _id;

    QString _firstName;
    QString _lastName;
    QString _deactivated;
    QString _hidden;

   //Можно доп параметры
public:
    VkUser();
    int getId() const;
    void setId(int id);
    QString getFirstName() const;
    void setFirstName(const QString &firstName);
    QString getLastName() const;
    void setLastName(const QString &lastName);
    QString getDeactivated() const;
    void setDeactivated(const QString &deactivated);
    QString getHidden() const;
    void setHidden(const QString &hidden);
};

#endif // USER_H
