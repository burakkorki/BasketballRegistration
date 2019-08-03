//
//  SimpleTeam.cpp
//  Homework 3
//
//  Created by Burak Korkmaz on 17.12.2017.
//  Copyright © 2017 Burak Korkmaz. All rights reserved.
//

#include "SimpleTeam.h"
#include <string>
#include <iostream>
using namespace std;


Team::Team(){
    teamName = "";
    teamColor = "";
}
    
void Team::setName(string teamName ){
    this->teamName = teamName;
}
void Team::setColor(string teamColor ){
    this->teamColor = teamColor;
}
string Team::getName(){
    return teamName;
}

string Team::getColor(){
    return teamColor;
}

