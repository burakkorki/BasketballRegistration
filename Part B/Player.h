//
//  Player.hpp
//  Homework-3-Part-B
//
//  Created by Burak Korkmaz on 18.12.2017.
//  Copyright © 2017 Burak Korkmaz. All rights reserved.
//

#ifndef __PLAYER_H
#define __PLAYER_H
#include <string>
using namespace std;

class Player {
public:
    Player();
    ~Player();
    Player( const Player &systemToCopy );
    void operator=( const Player &right );
    
    void setPlayerName( string playerName );
    void setPlayerPosition( string playerPosition);
    string getPlayerName();
    string getPlayerPosition();
    
    
private:
    
    string playerName;
    string playerPosition;
};

#endif
