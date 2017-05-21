#ifndef ERUSER_H
#define ERUSER_H
#include "entity/group.h"
#include <QString>
#include <QList>
class User
{
private:
    QList<Group*>* groups;
public:
    virtual QString getFio(){return "";}
    virtual int getId(){return 0;}
    QList<Group*>* getGroups();
    void setGroups(QList<Group*>* groups);
};

#endif // ERUSER_H
