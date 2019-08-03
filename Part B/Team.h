//
//  Team.h
//  Homework-3-Part-B
//
//  Created by Burak Korkmaz on 18.12.2017.
//  Copyright © 2017 Burak Korkmaz. All rights reserved.
//

#ifndef __TEAM_H
#define __TEAM_H
#include <string>
using namespace std;
#include "Player.h"
class Team {
public:
    Team();
    ~Team();
    Team( const Team &systemToCopy );
    void operator=( const Team &right );
    
    void addPlayer( string playerName, string playerPosition );
    void removePlayer( string playerName );
    void displayAllPlayers();
    void setName( string teamName );
    void setColor( string teamColor );
    string getName();
    string getColor();

    
    
//private:
    struct Node {
        Player p;
        Node* next;
    };
    
    Node *head;
    int playerNo;
    string teamName;
    string teamColor;
    
    
    Node* findPlayer(string playerName);
};

#endif
