//
//  Database.hpp
//  lab1
//
//  Created by Maddie Johnson on 10/22/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef Database_h
#define Database_h

#include <stdio.h>
#include <map>
#include <string>
#include <list>
#include "Relation.h"
//#include "Interpreter.h"
using namespace std;

//DOESN'T KNOW DATALOGPROGRAM CLASSES EXIST, ONLY INTERPRETER
class Database {
public:
    Database();
    void addRelation(string name, Relation relation) {
        relations.insert(make_pair(name, relation));
    }
    map<string, Relation> relations;
private:
    
};

#endif /* Database_h */