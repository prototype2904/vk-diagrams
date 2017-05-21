#ifndef VKGROUP_H
#define VKGROUP_H
#include <QString>
#include "entity/group.h"

class Group;

class VkGroup : public Group
{
private:
    int _id;
    QString _name;
public:
    VkGroup();
    int getId();
    void setId(int id);
    QString getName();
    void setName(const QString &name);
};

#endif // VKGROUP_H
