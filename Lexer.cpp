//
//  Lexer.cpp
//  lab1
//
//  Created by Maddie Johnson on 9/14/20.
//  Copyright © 2020 Maddie Johnson. All rights reserved.
//

#include "Lexer.h"
#include <vector>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

Lexer::Lexer() {
    machines.push_back(new MatcherAutomaton(",", COMMA));
    machines.push_back(new MatcherAutomaton(".", PERIOD));
    machines.push_back(new MatcherAutomaton("?", Q_MARK));
    machines.push_back(new MatcherAutomaton("(", LEFT_PAREN));
    machines.push_back(new MatcherAutomaton(")", RIGHT_PAREN));
    machines.push_back(new MatcherAutomaton(":", COLON));
    machines.push_back(new MatcherAutomaton(":-", COLON_DASH));
    machines.push_back(new MatcherAutomaton("*", MULTIPLY));
    machines.push_back(new MatcherAutomaton("+", ADD));
    machines.push_back(new MatcherAutomaton("Schemes", SCHEMES));
    machines.push_back(new MatcherAutomaton("Facts", FACTS));
    machines.push_back(new MatcherAutomaton("Queries", QUERIES));
    machines.push_back(new MatcherAutomaton("Rules", RULES));
    machines.push_back(new IdAutomaton(ID));
    machines.push_back(new StringAutomaton(STRING));
    machines.push_back(new CommentAutomaton(COMMENT));
    //undefined
    machines.push_back(new MatcherAutomaton("\n", EOFILE));
    machines.push_back(new UnterminatedStringAutomaton(UNDEFINED));
    machines.push_back(new UnterminatedCommentAutomaton(UNDEFINED));
}


void Lexer::run(string fileContents) {
    int curLineNum = 1;
    int maxRead = 0;
    int inputRead = 0;
    int maxNewLines = 0;
    Automaton* maxMachine = NULL;
    
    while (fileContents.size() > 0) {
//        cout << fileContents << endl;
        maxMachine = NULL;
        maxRead = 0;
        
        while (fileContents.size() > 0 && isspace(fileContents.at(0))) {
            if (fileContents.at(0) == '\n') {
                curLineNum++;
            }
//            cout << "erasing " << fileContents.at(0) << endl;
            fileContents.erase(0,1);
        }
        
        vector <Automaton*>::iterator it;
        for (it = machines.begin(); it != machines.end(); it++) {
            inputRead = (*it)->Read(fileContents);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxMachine = (*it);
                maxNewLines = (*it)->NewLinesRead();
            }
        }
        
        if (maxRead > 0) {
            Token* newToken = maxMachine->CreateToken(maxMachine->GetValue(), curLineNum);
            curLineNum += maxNewLines;
            if (newToken != NULL) {
                tokens.push_back(newToken);
            }
        }
        else {
            if (fileContents.length() > 0) {
                maxRead = 1;
                Token* newToken = new Token(UNDEFINED, fileContents.substr(0,1), curLineNum);
                if (newToken != NULL) {
                    tokens.push_back(newToken);
                }
            }
        }
        fileContents.erase(0, maxRead);
    }
    
    Token* newToken = new Token(EOFILE, "", curLineNum);
    if (newToken != NULL) {
        tokens.push_back(newToken);
    }
}

void Lexer::PrintTokens() {
    vector <Token*>::iterator it;
    for (it = tokens.begin(); it != tokens.end(); it++) {
        cout << (*it)->toString() << endl;
    }
    cout << "Total Tokens = " << tokens.size();
}

vector <Token*> Lexer::GetTokens() {
    return tokens;
}
