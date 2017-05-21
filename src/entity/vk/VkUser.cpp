#include "VkUser.h"

int VkUser::getId()
{
    return _id;
}

void VkUser::setId(int id)
{
    _id = id;
}

QString VkUser::getFirstName() const
{
    return _firstName;
}

void VkUser::setFirstName(const QString &firstName)
{
    _firstName = firstName;
}

QString VkUser::getLastName() const
{
    return _lastName;
}

void VkUser::setLastName(const QString &lastName)
{
    _lastName = lastName;
}

QString VkUser::getDeactivated() const
{
    return _deactivated;
}

void VkUser::setDeactivated(const QString &deactivated)
{
    _deactivated = deactivated;
}

QString VkUser::getHidden() const
{
    return _hidden;
}

void VkUser::setHidden(const QString &hidden)
{
    _hidden = hidden;
}

QString VkUser::getFio(){
    return QString().append(getFirstName()).append(" ").append(getLastName());
}

VkUser::VkUser()
{

}

