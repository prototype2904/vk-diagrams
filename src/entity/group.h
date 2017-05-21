#ifndef GROUP_H
#define GROUP_H

#include "QString"

class Group
{
public:
    Group();
    virtual int getId()=0;
    virtual QString getName() = 0;
};

#endif // GROUP_H
