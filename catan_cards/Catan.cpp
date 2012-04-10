#include "Player.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>


//constructor
//something is wrong with it.
Player::Player(){
    this->name_ = "Jeff";

    this->victoryPoints_= 0;
    this->roadLength_   = 0;
    this->armySize_     = 0;
    this->yellow        = 0;
    this->lightGreen    = 0;
    this->darkGreen     = 0;
    this->blue          = 0;
    this->red           = 0;

    this->knight        = 0;
    this->victoryPointCard = 0;
    this->roadBuilder   = 0;
    this->monopoly      = 0;
    this->yearOfPlenty  = 0;
}

Player::~Player(){

}


int Player::roll(){
    return rand() %5 +1;
}

void Player::checkStats(){
    cout<<"Player Name: "<<this->name_<<endl;
    cout<<"Victory Points: "<<this->victoryPoints_<<endl;
    cout<<"Army Size: "<<this->armySize_<<endl;
    cout<<"Road Length: "<<this->roadLength_<<endl;
    cout<<"Num of Resources: " <<this->numberOfResources()<<endl;
    cout<<"Num of Development: "<<this->numberOfDevelopments()<<endl<<endl;
}

int Player::numberOfResources(){
    int total = this->yellow;
    total = total + this->lightGreen;
    total = total + this->darkGreen;
    total = total + this->blue;
    total = total + this->red;
    return total;
}

int Player::numberOfDevelopments(){
    int total = this->knight;
    total +=this->victoryPointCard;
    total +=this->roadBuilder;
    total +=this->monopoly;
    total +=this->yearOfPlenty;
    return total;
}


void Player::seeResources(){
    cout<<"Yellow: "<<this->yellow<<endl;
    cout<<"Light Green: "<<this->lightGreen<<endl;
    cout<<"Dark Green: "<<this->darkGreen<<endl;
    cout<<"Blue: "<<this->blue<<endl;
    cout<<"Red: "<<this->red<<endl<<endl;
}

void Player::seeDevelopments(){
    cout<<"Knights: "<<this->knight<<endl;
    cout<<"Victory Point Card(s): "<<this->victoryPointCard<<endl;
    cout<<"Road Builder: "<<this->roadBuilder<<endl;
    cout<<"Monoply: "<<this->monopoly<<endl;
    cout<<"Year Of Plenth: "<<this->yearOfPlenty<<endl<<endl;
}

void Player::buyItem(){
    cout<<"What would you like to buy: "<<endl;
    cout<<"1) Road        (1 Red, 1 Dark Green)"<<endl;
    cout<<"2) Settlement  (1 Red, 1 Dark Green, 1 Light Green, 1 Yellow)"<<endl;
    cout<<"3) City        (3 Blue, 2 Yellow)"<<endl;
    cout<<"4) Development Card (1 Blue, 1 Yellow, 1 Light Green)"<<endl;
    cout<<"0 to cancel"<<endl;
    int number;
    cin>>number;
    cout<<endl;
    if(number==1)
        this->buyRoad();
    else if (number ==2)
        this->buySettlement();
    else if (number==3)
        this->buyCity();
    else if (number==4)
        this->buyDevelopmentCard(); 

}

void Player::buyRoad(){
    if(this->red>0 && this->darkGreen>0){
        //do action to place road
        this->red--;
        this->darkGreen--;
    } else
        cout<<"You do not have the resources to purchase a road!"<<endl<<endl;

}

void Player::buySettlement(){
    if(this->red >0 && this->darkGreen>0 && this->lightGreen>0 && this->yellow>0){
        //do action to place settlement
        this->red--;
        this->darkGreen--;
        this->yellow--;
        this->lightGreen--;
        this->victoryPoints_++;
    }else
        cout<<"You do not have the resources to purchase a settlement!"<<endl<<endl;
}

void Player::buyCity(){
    if(this->blue>=3 && this->yellow>=2){
        //do action to place settlement, but also we have to make sure a settlement is already in that space.
        this->blue -= 3;
        this->yellow -= 2;
        this->victoryPoints_++;
    } else
        cout<<"You do not have the resources to purchase a city!"<<endl<<endl;

}

void Player::gainResources(int roll){
    list<settlement>::iterator current = pieces.begin();

    int size = pieces.size();
    //need to know how the city will be attached to a the color;
    for(int i = 0; i<size; i++){
        if(current->top == roll){
            this->somecolor ++city;
        }
        if(current->left == roll){
            this->somecolor ++city;
        }
        if(current->right == roll){
            this->somecolor ++city;
        }

    }
}

void Player::buyDevelopmentCard(){
    if(this->blue>0 && this->yellow>0 && this->lightGreen>0){
        //do action to fetch developmentCard
        this->blue--;
        this->yellow--;
        this->lightGreen--;
    } else
        cout<<"You do not have the resources to purchase a developmentCard!"<<endl<<endl;
}

void Player::switchOutCards(){
    this->seeResources();
    
    cout<<"1) Trade for yellow"<<endl;
    cout<<"2) Trade for light green"<<endl;
    cout<<"3) Trade for dark green"<<endl;
    cout<<"4) Trade for blue"<<endl;
    cout<<"5) Trade for red"<<endl<endl;
    int input;
    cin>>input;

    if(input==1){
        
        this->yellow++;
    }else if (input==2){

        this->lightGreen++;
    }else if(input==3){

        this->darkGreen++;
    }else if(input==4){

        this->blue++;
    }else if(input==5){

        this->red++;
    }else
        cout<<"Cancelled"<<endl;
    

}

void Player::whichCardsToTrade(){
    
    cout<<"1) Give up yellow"<<endl;
    cout<<"2) Give up light green"<<endl;
    cout<<"3) Give up dark green"<<endl;
    cout<<"4) Give up blue"<<endl;
    cout<<"5) Give up red"<<endl;
    int input;
    cin>>input;

    int tradeDefault = 4;
    if(input==1){
        //check for better trade through ports
        Player.yellow-=tradeDefault;
        
    }else if (input==2){
        //check for better trade through ports
        Player.lightGreen-=tradeDefault;
    }else if(input==3){
        //check for better trade through ports
        Player.darkGreen-=tradeDefault;
    }else if(input==4){
        //check for better trade through ports
        Player.blue-=tradeDefault;
    }else if(input==5){
        //check for better trade through ports
        Player.red-=tradeDefault;
    }else
        cout<<"Cancelled"<<endl;

}
