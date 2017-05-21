#include "relation.h"


Entity<User*>* Relation::getEntR(){
    return this->entityR;
}


Entity<User*>* Relation::getEntL(){
    return this->entityL;
}

bool Relation::isMulR(){
    return this->MultiplicityR;
}

bool Relation::isMulL(){
    return this->MultiplicityL;
}

bool Relation::isAbsR(){
    return this->AbstractR;
}

bool Relation::isAbsL(){
    return this->AbstractL;
}

QString Relation::getKey(){
    return this->key;
}

Relation::Relation(
         QString key,
         Entity<User*>* EntityR,
         Entity<User*>* EntityL,
         bool MultiplicityR,
         bool MultiplicityL,
         bool AbstractR,
         bool AbstractL){

    this->key = key;
    this->AbstractL = AbstractL;
    this->AbstractR = AbstractR;
    this->MultiplicityR = MultiplicityR;
    this->MultiplicityL = MultiplicityL;
    this->entityL = EntityL;
    this->entityR = EntityR;

    EntityL-> addRelation(this);
    EntityR->addRelation(this);
}

Relation::~Relation(){
//    if(this->EntityL!=NULL){
//        this->EntityL->popRelatio this->relationID, false);
//    }
//    if(this->EntityR!=NULL){
//        this->EntityR->popRelationByID(this->relationID, false);
//    }
//    #ifdef DEBUGLOG_RELATION
//        QFile file(LOG_PATH);
//        file.open(QIODevice::Append | QIODevice::Text);
//        QTextStream out(&file);
//        out << "- Relation deleted" << endl;
//        file.close();
//        //CountDeltedObject++;
//    #endif
}
