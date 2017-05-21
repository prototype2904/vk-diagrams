#ifndef ENTITIE_H
#define ENTITIE_H

//=====================================================
#include <string>
#include <QList>
//=====================================================
using namespace std;

class Relation;
class Field;

template <typename T>
class Entity {
private:
    T value;
    QList<Relation*>* relations;

public:
    Entity(){
        this->relations = new QList<Relation*>();
    }
    Entity(T value){
        this->relations = new QList<Relation*>();
        this->value = value;
    }
    virtual ~Entity(){
        delete(relations);
    }

public:
    void    setValue(T value){
        this->value = value;
    }
    T getValue(){return this->value;}
    Relation* 	relationAt(int i){
        return this->relations->at(i);
    }
    void    addRelation(Relation* r){
        this->relations->push_back(r);
    }
    void    popRelationAt(int i, bool deleteRelationAfterPoping){
        this->relations->popAt(i);
        if(deleteRelationAfterPoping){
            delete(this->relations->at(i));
        }
    }
    int     relationCount(){
        return this->relations->size();
    }

    bool    isRelationListEmpty(){
        if(this->relationCount()>0){
            return false;
        }else{
            return true;
        }
    }
};

#endif // ENTITIE_H
