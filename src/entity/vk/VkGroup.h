#ifndef VKGROUP_H
#define VKGROUP_H
#include <QString>
class VkGroup
{
private:
    int _id;
    QString _name;
public:
    VkGroup();
    int getId() const;
    void setId(int id);
    QString getName() const;
    void setName(const QString &name);
};

#endif // VKGROUP_H
