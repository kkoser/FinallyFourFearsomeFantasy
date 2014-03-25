//
//  Character.h
//  tester
//
//  Created by Zach Waterson on 3/22/14.
//  Copyright (c) 2014 Zach Waterson. All rights reserved.
//

/*
This is the base character class of which other characters will inherit.
 It is an abstract class, as there will be no base character filetype to parse.
 */
#ifndef __tester__Character__
#define __tester__Character__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


typedef enum {NOSTATUS, DPT, SHIELD, INCAP} Statuses; //these can be applied by the move
typedef enum {NOATTRIBUTE, POWER, CURRENTPP, PPREGEN, ARMOR} Attributes; //certain moves multiply these

using namespace std;

class Character {
protected:
    
	int maxHealth;
	int standardPower;
	int maxPP; //mana for moves
	int standardPPRegen;
	int standardArmor;
    
	int currentHealth; //current health in/out battle
    
	//these are augmented in battle and reset afterwords
	int currentPower;
	int currentPP;
	int currentPPRegen;
	int currentArmor;
    
	//these are not increased by level points
	int accuracy;
    
	string name;
    string file;
	
    vector<string> moves;
    
	string spriteName;
        
public:
	Character(string fileName);
    
    //attribute setters for battle
    void setPower(int p);
    
    void actMoveOnTarget(string moveName, vector<Character> targets);
    
    int numTargetsForMove(string moveName);
    
    //setters and getters, these adjust for <0 or >max inputs
    int getCurrentHealth();
    void setCurrentHealth(int health);
    
    
private:
    
    string displayForMove(string str); //creates text to be displayed
    void setStatForTarget();
    int getValueForCommand(string com, int baseVal);
    

};

#endif /* defined(__tester__Character__) */