//
//  Tuple.cpp
//  lab1
//
//  Created by Maddie Johnson on 10/22/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Tuple.h"

//Tuple::Tuple(string n) {
//    name = n;
//}

Tuple::Tuple() {}

void Tuple::AddToTuple(Parameter* p) {
    values.push_back(p);
}

void Tuple::toString() {
    vector<Parameter*>::iterator it;
    for (it = values.begin(); it != values.end(); it++) {
        cout << (*it) << " ";
    }
}
