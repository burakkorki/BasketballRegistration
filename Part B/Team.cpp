//
//  Team.cpp
//  Homework-3-Part-B
//
//  Created by Burak Korkmaz on 18.12.2017.
//  Copyright © 2017 Burak Korkmaz. All rights reserved.
//

#include "Team.h"

#include <string>
#include <iostream>
using namespace std;
#include <algorithm>

Team::Team(){
    head = NULL;
    playerNo = 0;
    teamName = "";
    teamColor = "";
}

Team::~Team(){
    while (playerNo != 0)
        removePlayer(head->p.getPlayerName());
}

Team::Team( const Team &systemToCopy ){
    if(systemToCopy.head == NULL)
        head = NULL;
    else{
        head = new Node;
        head->p = systemToCopy.head->p;
        playerNo = systemToCopy.playerNo;
        teamName = systemToCopy.teamName;
        teamColor = systemToCopy.teamColor;
        Node *prev = head;
        for(Node *cur = systemToCopy.head->next; cur != NULL; cur = cur->next){
            prev->next = new Node;
            prev->p = cur->p;
            prev->p.setPlayerName(cur->p.getPlayerName());
            prev->p.setPlayerPosition(cur->p.getPlayerPosition());
            prev = prev->next;
        }
        prev->next = NULL;
    }
}

void Team::operator=(const Team &right){
    if(right.head == NULL)
        head = NULL;
    else{
        head = new Node;
        head->p = right.head->p;
        playerNo = right.playerNo;
        teamName = right.teamName;
        teamColor = right.teamColor;
        Node *prev = head;
        for(Node *cur = right.head->next; cur != NULL; cur = cur->next){
            prev->next = new Node;
            prev->p = cur->p;
            prev->p.setPlayerName(cur->p.getPlayerName());
            prev->p.setPlayerPosition(cur->p.getPlayerPosition());
            prev = prev->next;
        }
        prev->next = NULL;
    }
}

void Team::addPlayer( string playerName, string playerPosition ){
    string beforeTransform = playerName;
    int count = 0;
    std::transform(playerName.begin(),playerName.end(),playerName.begin(),::tolower);
    
    if(head != NULL){
        
        for(Node *prev = head; prev != NULL ; prev=prev->next){
            string temp = prev->p.getPlayerName();
            std::transform(temp.begin(),temp.end(),temp.begin(),::tolower);
            if(temp == playerName)
                count++;
        }
    }
    if(count == 0){
        
        Node *temp = NULL;
        temp = new Node;
        temp->p.setPlayerName(playerName);
        temp->p.setPlayerPosition(playerPosition);
        temp->next= NULL;
        if(head == NULL){
            head = temp;
        }
        else{
            Node *cur = head;
            while(cur->next != NULL)
                cur = cur->next;
            cur->next = temp;
        }
        playerNo++;
    }
    else
        cout<< "Player name  with  an  already  registered  name : " << beforeTransform  << " as --> " << playerName     << endl;
    
}

void Team::removePlayer( string playerName ){
    std::transform(playerName.begin(),playerName.end(),playerName.begin(),::tolower);
    
    Node *temp = head;
    Node *cur = findPlayer(playerName);
    
    if(cur != NULL){
        if(playerNo == 1){
            if(cur->p.getPlayerName() == head->p.getPlayerName()){
                head = head->next;
            }
            else
                cout << "Wrong player name entered" << endl;
        }
        else{
            if(head->p.getPlayerName() == cur->p.getPlayerName())
                head = head->next;
            else{
                Node *prev = head;
                while(prev->next->p.getPlayerName() != cur->p.getPlayerName())
                    prev = prev->next;
                
                temp = prev->next;
                prev->next = temp->next;
            }
        }
        temp->next = NULL;
        delete temp;
        temp = NULL;
        playerNo--;
    }
    else
        cout<<  "Wrong player name entered" <<endl;
}

void Team::displayAllPlayers(){

    if(playerNo == 0)
        cout <<"--EMPTY--"<< endl;
    else{
        Node *temp = head;
        for(int i = 0; i< playerNo;i++){
            if(i == 0)
                cout << temp->p.getPlayerName() << "," << temp->p.getPlayerPosition() << " (for the " << i+1 << "st player)" << endl;
            else if(i == 1)
                cout << temp->p.getPlayerName() << "," << temp->p.getPlayerPosition() << " (for the " << i+1 << "nd player)" << endl;
            else if(i == 2)
                cout << temp->p.getPlayerName() << "," << temp->p.getPlayerPosition() << " (for the " << i+1 << "rd player)" << endl;
            else
                cout << temp->p.getPlayerName() << "," << temp->p.getPlayerPosition() << " (for the " << i+1 << "th player)" << endl;
            temp = temp->next;
        }
    }
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


Team::Node *Team::findPlayer(string playerName){
    std::transform(playerName.begin(),playerName.end(),playerName.begin(),::tolower);
    
    Node *temp = head;
    int count = 0;
    
    if(temp != NULL){
        for(Node *prev = head; prev != NULL ; prev=prev->next){
            string tmp = prev->p.getPlayerName();
            std::transform(tmp.begin(),tmp.end(),tmp.begin(),::tolower);
            if(tmp == playerName)
                count++;
        }
        
        
        if(count > 0){
            if(temp!=NULL)
                string s = temp->p.getPlayerName();
            while(temp->p.getPlayerName() != playerName )
                temp = temp->next;
        }
        
        if (count == 0)
            temp = NULL;
    }
    return temp;
}
