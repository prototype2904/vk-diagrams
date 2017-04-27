#ifndef ERUSER_H
#define ERUSER_H
#include "vk/VkUser.h"
#include "vk/VkGroup.h"
#include <QList>
class User
{
private:
    VkUser* vkUser;
    QList<VkGroup*> vkGroup;
public:
    User();
    VkUser* getVkUser() ;
    void setVkUser(VkUser *value);
    QList<VkGroup*> getVkGroup() const;
    void setVkGroup(QList<VkGroup*> value);
};

#endif // ERUSER_H
