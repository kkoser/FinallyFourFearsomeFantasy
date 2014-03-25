//
//  Character.cpp
//  tester
//
//  Created by Zach Waterson on 3/22/14.
//  Copyright (c) 2014 Zach Waterson. All rights reserved.
//

#include "Character.h"

Character::Character(string fileName) {
    
}

void Character::actMoveOnTarget(string moveName, vector<Character> targets) {
    
    //open file
    ifstream file(moveName.c_str());
    //check for open
    if (!file) {
        cout<<"File "<<moveName<<" failed to open"<<endl;
        return;
    }
    
    //get each line from file
    string line;
    while (getline(file, line)) {
        
        Character &ch = *this;
        
        //get each word from line
        istringstream iss(line);
        string word;
        while (getline(iss, word, ' ')) {
            if (word=="Display") {
                this->displayForMove(line);
            }
            else if (word=="Target") {
                ch = targets[0];
                
            }
            else if (word=="Actor") {
                ch = *this;
            }
            else if (word=="Health") {
                getline(iss, word);
                
                
                int val;
                if (word=="MAX") {
                    val = ch.getCurrentHealth();
                }
                else if (word=="HALF") {
                    val = ch.getCurrentHealth()/2;
                }
                if (word=="-MAX") {
                    val = -1*ch.getCurrentHealth();
                }
                else if (word=="-HALF") {
                    val = -1*ch.getCurrentHealth()/2;
                }
                
                else {
                    val = atoi(word.c_str()); //replace with numeric value of word
                }
                ch.setCurrentHealth(ch.getCurrentHealth()+val);
            }
            
            else {
                cout << "Error reading word " << word << endl;
            }
            
        }
    }
    
}

int Character::numTargetsForMove(string moveName) {
    ifstream file(moveName.c_str());
    
    if (!file) {
        cout<<"File "<<moveName<<" failed to open"<<endl;
    }
    
    string line;
    
    while (file.good()) {
        getline(file, line); //split file into lines
        
        istringstream iss(line); //convert to stream for tokenization
        string word; //individual word of line
        while (getline(iss, word, ' ')) { //store next word from line
            
            //look for TARGETS keyword, otherwise move on
            if (word=="Targets") {
                getline(iss, word, ' ');
                if (word=="ALL") {
                    return 0;
                }
                else {
                    return atoi(word.c_str()); //convert to int
                }
            }
        }
    }
    
    return 1;   //defaults to 1 if can't find target

}

void Character::displayForMove(string str) {
    
}

//setters and getters
int Character::getCurrentHealth() {
    return currentHealth;
}

void Character::setCurrentHealth(int health) {
    if (health < 0) {
        health = 0;
    }
    else if (health > maxHealth) {
        health = maxHealth;
    }
    currentHealth = health;
}

int Character::getCurrentPower() {
    return currentPower;
}

void Character::setCurrentPower(int power) {
    if (power < 0) {
        power = 0;
    }
    else if (power > standardPower) {
        power = standardPower;
    }
    currentPower = power;
}

int Character::getCurrentPP() {
    return currentPP;
}

void Character::setCurrentPP(int PP) {
    if (PP < 0) {
        PP = 0;
    }
    else if (PP > maxPP) {
        PP = maxPP;
    }
    currentPP = PP;
}