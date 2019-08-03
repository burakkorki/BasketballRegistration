//
//  Player.cpp
//  Homework-3-Part-B
//
//  Created by Burak Korkmaz on 18.12.2017.
//  Copyright © 2017 Burak Korkmaz. All rights reserved.
//

#include "Player.h"
#include <string>
#include <iostream>
using namespace std;


Player::Player(){
    playerName = "";
    playerPosition = "";
}

Player::~Player(){
    
}

Player::Player( const Player &systemToCopy ){
    
}

void Player::operator=(const Player &right){
    
}

void Player::setPlayerName(string playerName){
    this->playerName = playerName;
}
void Player::setPlayerPosition(string playerPosition){
    this->playerPosition = playerPosition;
}
string Player::getPlayerName(){
    return playerName;
}

string Player::getPlayerPosition(){
    return playerPosition;
}
