//
//  BasketReg.hpp
//  Homework-3-Part-B
//
//  Created by Burak Korkmaz on 18.12.2017.
//  Copyright © 2017 Burak Korkmaz. All rights reserved.
//

#ifndef __BASKET_REG_H
#define __BASKET_REG_H
#include <string>
using namespace std;
#include "Team.h"
class BasketReg {
public:
    BasketReg();
    ~BasketReg();
    BasketReg( const BasketReg &systemToCopy );
    void operator=( const BasketReg &right );
    
    void addTeam( string teamName, string teamColor );
    void removeTeam( string teamName );
    void displayAllTeams();
    void addPlayer( string teamName, string playerName, string playerPosition );
    void removePlayer( string teamName, string playerName );
    void displayTeam( string teamName );
    void displayPlayer( string playerName );
private:
    struct Node {
        Team t;
        Node* next;
    };
    
    Node *head;
    int teamNo;
    Node* findTeam(string teamName);
};
#endif
