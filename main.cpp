//
//  main.cpp
//  lab1
//
//  Created by Maddie Johnson on 9/14/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <streambuf>
#include "Lexer.h"
#include "Parser.h"
#include "TestParser.h"
#include "DatalogProgram.h"
using namespace std;

int main(int argc, const char * argv[]) {
    ifstream in("/Users/maddie/CODING/lab2/lab2/project2-exampleIO/in21.txt");
 
//    ifstream in(argv[1]);
    stringstream buffer;
    buffer << in.rdbuf();
    
    Lexer * lexer = new Lexer();
    lexer->run(buffer.str());
    //lexer->PrintTokens();
    
    Parser * parser = new Parser(lexer->GetTokens());
    parser->Parse();
    
    parser->GetDatalog()->toString();
    parser->PrintDomain();
    
    delete lexer;
    delete parser;
    //delete datalog;
    
    
//    TestParser* tp = new TestParser();
//    tp->TestSchemeList();
    
}
