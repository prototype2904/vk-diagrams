#include "VkGroup.h"

int VkGroup::getId() const
{
    return _id;
}

void VkGroup::setId(int id)
{
    _id = id;
}

QString VkGroup::getName() const
{
    return _name;
}

void VkGroup::setName(const QString &name)
{
    _name = name;
}

VkGroup::VkGroup()
{

}

