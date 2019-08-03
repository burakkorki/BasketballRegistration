//
//  SimpleTeam.husing namespace std;
//  Homework 3
//
//  Created by Burak Korkmaz on 17.12.2017.
//  Copyright © 2017 Burak Korkmaz. All rights reserved.
//

#ifndef __SIMPLE_TEAM_H
#define __SIMPLE_TEAM_H
#include <string>
using namespace std;

class Team {
public:
    Team();
    
    void setName( string teamName );
    void setColor( string teamColor );
    string getName();
    string getColor();

    
private:
    
    string teamName;
    string teamColor;
};

#endif
