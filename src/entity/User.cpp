#include "User.h"

VkUser* User::getVkUser()
{
    return vkUser;
}

void User::setVkUser(VkUser *value)
{
    vkUser = value;
}

QList<VkGroup*> User::getVkGroup() const
{
    return vkGroup;
}

void User::setVkGroup(QList<VkGroup*> value)
{
    vkGroup = value;
}

User::User()
{
    vkUser= NULL;
}

