//
//  Header.h
//  lab1
//
//  Created by Maddie Johnson on 10/22/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "Parameter.h"
using namespace std;

class Header {
public:
//    Header();
    string toString();
    void AddAttribute(Parameter* a);
    vector <Parameter*> attributes;
private:
    
};

#endif /* Header_h */
