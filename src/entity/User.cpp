#include "User.h"

VkUser User::getVkUser() const
{
    return vkUser;
}

void User::setVkUser(const VkUser &value)
{
    vkUser = value;
}

QList<VkGroup> User::getVkGroup() const
{
    return vkGroup;
}

void User::setVkGroup(const QList<VkGroup> &value)
{
    vkGroup = value;
}

User::User()
{

}

