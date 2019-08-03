//
//  SimpleReg.cpp
//  Homework 3
//
//  Created by Burak Korkmaz on 17.12.2017.
//  Copyright © 2017 Burak Korkmaz. All rights reserved.
//

#include "SimpleReg.h"

#include <string>
#include <iostream>
using namespace std;
#include <algorithm>

SimpleReg::SimpleReg(){
    head = NULL;
    teamNo = 0;
}

void SimpleReg::addTeam(string teamName, string teamColor){
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


void SimpleReg::removeTeam(string teamName){
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

void SimpleReg::displayAllTeams(){

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

SimpleReg::Node *SimpleReg::findTeam(string teamName){
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
