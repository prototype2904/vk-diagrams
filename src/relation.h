#ifndef RELATION_H
#define RELATION_H

#include "QString"
#include "entity/User.h"
#include "entity.h"

class Relation{
 private:
    QString key;
    Entity<User*>* entityR;
    Entity<User*>* entityL;
    bool MultiplicityR;
    bool MultiplicityL;
    bool AbstractR;
    bool AbstractL;

public:
    QString getKey();
    Entity<User*>* getEntR();
    Entity<User*>* getEntL();
    bool isMulR();
    bool isMulL();
    bool isAbsR();
    bool isAbsL();
     Relation(
             QString key,
             Entity<User*>* entitieR,
             Entity<User*>* entitieL,
             bool MultiplicityR,
             bool MultiplicityL,
             bool AbstractR,
             bool AbstractL);
    ~Relation();

};

#endif // RELATION_H
