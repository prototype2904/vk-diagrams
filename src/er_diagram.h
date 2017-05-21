#ifndef ER_H
#define ER_H

#include <QString>
#include <QList>
#include <entity.h>
#include <relation.h>

using namespace std;

template <typename T>
class Entity;

template <typename T>
class ER
{
private:
    QList<Entity<T>*>* entities;
    QList<Relation*>* relations;

public:
    ER(){
        this->entities = new QList<Entity<T>*>();
        this->relations = new QList<Relation*>();
    }
    ~ER(){
        for(int i=0; i<this->relations->size(); i++){
            delete(relations->at(i));
        }
        for(int i=0; i<this->entities->size(); i++){
            delete(entities->at(i));
        }
        delete(entities);
        delete(relations);
    }

public:
    Relation*     relationAt(int i){
        return this->relations->at(i);
    }
    void    addRelation(
                        QString key,
                        Entity<T>* EntityR,
                        Entity<T>* EntityL,
                        bool MultiplicityR,
                        bool MultiplicityL,
                        bool AbstractR,
                        bool AbstractL){
        this->relations->push_back(new Relation(key, EntityR, EntityL, MultiplicityR,
                                                MultiplicityL, AbstractR, AbstractL));
    }

    void addEntity(Entity<User*> * entity){
        this->entities->push_back(entity);
    }

    int          getEntityCount(){
        return this->entities->size();
    }
    int getRelationCount(){
        return this->relations->size();
    }

    Entity<T>*  entityAt(int i) {
        return this->entities->at(i);
    }
};

#endif
