//
//  BasketReg.cpp
//  Homework-3-Part-B
//
//  Created by Burak Korkmaz on 18.12.2017.
//  Copyright © 2017 Burak Korkmaz. All rights reserved.
//

#include "BasketReg.h"

#include <string>
#include <iostream>
using namespace std;
#include <algorithm>

BasketReg::BasketReg(){
    head = NULL;
    teamNo = 0;
}

BasketReg::~BasketReg(){
    while (teamNo != 0)
        removeTeam(head->t.getName());
}

BasketReg::BasketReg( const BasketReg &systemToCopy ){
    if(systemToCopy.head == NULL)
        head = NULL;
    else{
        head = new Node;
        head->t = systemToCopy.head->t;
        teamNo = systemToCopy.teamNo;
        Node *prev = head;
        for(Node *cur = systemToCopy.head->next; cur != NULL; cur = cur->next){
            prev->next = new Node;
            prev->t = cur->t;
            prev->t.setName(cur->t.getName());
            prev->t.setColor(cur->t.getColor());
            prev = prev->next;
        }
        prev->next = NULL;
    }
}

void BasketReg::operator=( const BasketReg &right ){
    if(right.head == NULL)
        head = NULL;
    else{
        head = new Node;
        head->t = right.head->t;
        teamNo = right.teamNo;
        Node *prev = head;
        for(Node *cur = right.head->next; cur != NULL; cur = cur->next){
            prev->next = new Node;
            prev->t = cur->t;
            prev->t.setName(cur->t.getName());
            prev->t.setColor(cur->t.getColor());
            prev = prev->next;
        }
        prev->next = NULL;
    }
}
void BasketReg::addTeam(string teamName, string teamColor){
    string beforeTransform = teamName;
    int count = 0;
    
    
    if(head != NULL){
        std::transform(teamName.begin(),teamName.end(),teamName.begin(),::tolower);
        for(Node *prev = head; prev != NULL ; prev=prev->next){
            string temp = prev->t.getName();
            std::transform(temp.begin(),temp.end(),temp.begin(),::tolower);
            if(temp == teamName)
                count++;
        }
    }
    if(count == 0){
        
        Node *temp = NULL;
        temp = new Node;
        temp->t.setName(teamName);
        temp->t.setColor(teamColor);
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
        teamNo++;
    }
    else
        cout<< "Team name  with  an  already  registered  name : " << beforeTransform  << " as --> " << teamName     << endl;
    
}


void BasketReg::removeTeam(string teamName){
    std::transform(teamName.begin(),teamName.end(),teamName.begin(),::tolower);
    
    Node *temp = head;
    Node *cur = findTeam(teamName);
    
    if(cur != NULL){
        if(teamNo == 1){
            if(cur->t.getName() == head->t.getName()){
                head = head->next;
            }
            else
                cout << "Wrong team name entered" << endl;
        }
        else{
            if(head->t.getName() == cur->t.getName())
                head = head->next;
            else{
                Node *prev = head;
                while(prev->next->t.getName() != cur->t.getName())
                    prev = prev->next;
                
                temp = prev->next;
                prev->next = temp->next;
            }
        }
        temp->next = NULL;
        delete temp;
        temp = NULL;
        teamNo--;
    }
    else
        cout<<  "Wrong team name entered" <<endl;
}

void BasketReg::displayAllTeams(){
    
    if(teamNo == 0)
        cout <<"--EMPTY--"<< endl;
    else{
        Node *temp = head;
        for(int i = 0; i< teamNo;i++){
            if(i == 0)
                cout << temp->t.getName() << "," << temp->t.getColor() << " (for the " << i+1 << "st team)" << endl;
            else if(i == 1)
                cout << temp->t.getName() << "," << temp->t.getColor() << " (for the " << i+1 << "nd team)" << endl;
            else if(i == 2)
                cout << temp->t.getName() << "," << temp->t.getColor() << " (for the " << i+1 << "rd team)" << endl;
            else
                cout << temp->t.getName() << "," << temp->t.getColor() << " (for the " << i+1 << "th team)" << endl;
            temp = temp->next;
        }
    }
}

void BasketReg::addPlayer(string teamName, string playerName, string playerPosition){
    Node *team = findTeam(teamName);
    if(team != NULL)
        team->t.addPlayer(playerName, playerPosition);
    if(team == NULL)
        cout << "Wrong team name entered" << endl;
}

void BasketReg::removePlayer(string teamName, string playerName){
    Node *team = findTeam(teamName);
    if(team != NULL){
        team->t.removePlayer(playerName);
    }
    if(team == NULL)
        cout << "Wrong team name entered" << endl;
}

void BasketReg::displayTeam(string teamName){
    Node *team = findTeam(teamName);
    if(team != NULL){
        cout<< team->t.getName() << ", " << team->t.getColor() << endl;
        team->t.displayAllPlayers();
    }
    if (team == NULL)
        cout << "--EMPTY--" << endl;
}

void BasketReg::displayPlayer(string playerName){
    int count= 0;
    int loop = 0;
//    Node *temp = head;
    if(head != NULL)
        cout << playerName << endl;
    std::transform(playerName.begin(),playerName.end(),playerName.begin(),::tolower);
    for(Node *temp = head; temp != NULL ; temp = temp->next ){
        Team::Node *comp = temp->t.findPlayer(playerName);
        if(comp != NULL){
            if(loop == 0)
                cout << comp->p.getPlayerPosition() << ", " << temp->t.getName() << ", " << temp->t.getColor() << " (for the " << loop + 1 << "st team)" << endl;
            else if(loop == 1)
                cout << comp->p.getPlayerPosition() << ", " << temp->t.getName() << ", " << temp->t.getColor() << " (for the " << loop + 1 << "nd team)" << endl;
            else if(loop == 2)
                cout << comp->p.getPlayerPosition() << ", " << temp->t.getName() << ", " << temp->t.getColor() << " (for the " << loop + 1 << "rd team)" << endl;
            else
                cout << comp->p.getPlayerPosition() << ", " << temp->t.getName() << ", " << temp->t.getColor() << " (for the " << loop + 1 << "th team)" << endl;
            count ++;
        }
        loop ++;
    }
    if(count == 0)
        cout << "--EMPTY--" << endl;
}

BasketReg::Node *BasketReg::findTeam(string teamName){
    std::transform(teamName.begin(),teamName.end(),teamName.begin(),::tolower);
    
    Node *temp = head;
    int count = 0;
    
    if(temp != NULL){
        for(Node *prev = head; prev != NULL ; prev=prev->next){
            string tmp = prev->t.getName();
            std::transform(tmp.begin(),tmp.end(),tmp.begin(),::tolower);
            if(tmp == teamName)
                count++;
        }
        
        
        if(count > 0){
            if(temp!=NULL)
                string s = temp->t.getName();
            while(temp->t.getName() != teamName )
                temp = temp->next;
        }
        
        if (count == 0)
            temp = NULL;
    }
    return temp;
}

