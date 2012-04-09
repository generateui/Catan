#include "Player.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

int Player::roll(){
    return rand() %5 +1;
}

void Player::checkStats(){
    cout<<"Player Name: "<<this->name_<<endl;
    cout<<"Victory Points: "<<this->victoryPoints_<<endl;
    cout<<"Army Size: "<<this->armySize_<<endl;
    cout<<"Number of Resources: " <<this->numberOfResources();
}

int Player::numberOfResources(){
    int total = this->yellow;
    total = total + this->lightGreen;
    total = total + this->darkGreen;
    total = total + this->blue;
    total = total + this->red;
    return total;
}

//constructor
//something is wrong with it.
Player::Player(){
    cout<<"in constructor"<<endl;
    this->name_ = "Jeff"
    this->victoryPoints_ = 0;
    this->roadLength_ = 0;
    this->armySize_ = 0;
    this->yellow = 0;
    this->darkGreen = 0;
    this->blue = 0;
    this->red = 0;
}
