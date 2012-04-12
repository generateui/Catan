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
    this->playerColor_  = "G";
    this->yellow_       = 0;
    this->lightGreen_   = 0;
    this->darkGreen_    = 0;
    this->blue_         = 0;
    this->red_          = 0;

    this->knight_       = 0;
    this->victoryPointCard_ = 0;
    this->roadBuilder_  = 0;
    this->monopoly_     = 0;
    this->yearOfPlenty_ = 0;
}

Player::~Player(){

}

//public function for rolling dice
int Player::roll(){
    return rand() %6 +1;
}

//This function shows the basic numbers for a given player.
void Player::checkStats(){
    cout<<"Player Name: "<<this->name_<<endl;
    cout<<"Victory Points: "<<this->victoryPoints_<<endl;
    cout<<"Army Size: "<<this->armySize_<<endl;
    cout<<"Road Length: "<<this->roadLength_<<endl;
    cout<<"Num of Resources: " <<this->numberOfResources()<<endl;
    cout<<"Num of Development: "<<this->numberOfDevelopments()<<endl<<endl;
}

//this private function calculates the total number of resources a player has
int Player::numberOfResources(){
    int total = this->yellow_;
    total = total + this->lightGreen_;
    total = total + this->darkGreen_;
    total = total + this->blue_;
    total = total + this->red_;
    return total;
}

//this private function calculates the
//totalnumber of development cards a player has
int Player::numberOfDevelopments(){
    int total = this->knight_;
    total +=this->victoryPointCard_;
    total +=this->roadBuilder_;
    total +=this->monopoly_;
    total +=this->yearOfPlenty_;
    return total;
}

//This public functionallows a player to see
//which resources he or she has
void Player::seeResources(){
    cout<<"Yellow: "<<this->yellow_<<endl;
    cout<<"Light Green: "<<this->lightGreen_<<endl;
    cout<<"Dark Green: "<<this->darkGreen_<<endl;
    cout<<"Blue: "<<this->blue_<<endl;
    cout<<"Red: "<<this->red_<<endl<<endl;
}

//This public functionallows a player to see
//which development cards he or she has
void Player::seeDevelopments(){
    cout<<"Knights: "<<this->knight_<<endl;
    cout<<"Victory Point Card(s): "<<this->victoryPointCard_<<endl;
    cout<<"Road Builder: "<<this->roadBuilder_<<endl;
    cout<<"Monoply: "<<this->monopoly_<<endl;
    cout<<"Year Of Plenth: "<<this->yearOfPlenty_<<endl<<endl;
}

/*This public function brings up the buy menu. It calls the
proper private functions from here for whichever thing the player
wants to purchase. */
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
    if(input==1 || input==2 || input==3 || input==4){
    if(number==1)
        this->buyRoad();
    else if (number ==2)
        this->buySettlement();
    else if (number==3)
        this->buyCity();
    else if (number==4)
        this->buyDevelopmentCard(); 
        this->seeResources();
    }

}

//this private function allows a player to purchase a road
void Player::buyRoad(){
    if(this->red>0 && this->darkGreen>0){
        //do action to place road
        this->red_--;
        this->darkGreen_--;
    } else
        cout<<"You do not have the resources to purchase a road!"<<endl<<endl;

}

//This private fuction allows a player to purchase a settlement.
void Player::buySettlement(){
    if(this->red >0 && this->darkGreen>0 && this->lightGreen>0 && this->yellow>0){
        //do action to place settlement
        this->red_--;
        this->darkGreen_--;
        this->yellow_--;
        this->lightGreen_--;
        this->victoryPoints_++;

        struct settlement set;
        set.City = 1;

        //filling in the rest until we figure out how it connects to the board
        set.left = 1;
        set.right = 1;
        set.top =1;
        set.port = 'a';
        //end random fill
        
        pieces.push_back(set);//add city to list.

    }else
        cout<<"You do not have the resources to purchase a settlement!"<<endl<<endl;
}

/*This private function does the action of changing a settlement into a city and
charging the respective resources.*/
void Player::buyCity(){
    if(this->blue>=3 && this->yellow>=2){
        //do action to place settlement, but also we have to make sure a settlement is already in that space.
        
        //cycle through list of settlements to make sure there is a settlement to begin with
        list<settlement>::iterator current = pieces.begin();
        int size = pieces.size();
        int numOfCities = 0;
        for(int i = 0; i<size; i++){
            if(current->city == 2)
                numOfCities++;
            current++;
        }
        if(numOfCities!=size){ //it's possible to build a city (aka not every building is a city)
            this->blue_ -= 3;
            this->yellow_ -= 2;
            this->victoryPoints_++;
            //then we have to do some sort of cycle to change the proper settlement into a city.
        }
        else{   //we can't build a city because there are no settlements (Everything already is a city)
            cout<<"You have no settlements!"<<endl;
        }
        
    } else
        cout<<"You do not have the resources to purchase a city!"<<endl<<endl;

}

/*This private function lets you buy a development card.
It will have to call the private function UNKOWNRIGHTNOW
to figure out which card you get
*/
void Player::buyDevelopmentCard(){
    if(this->blue>0 && this->yellow>0 && this->lightGreen>0){
        //do action to fetch developmentCard
        this->blue_--;
        this->yellow_--;
        this->lightGreen_--;
    } else
        cout<<"You do not have the resources to purchase a developmentCard!"<<endl<<endl;
}

void Player::changeName(string & name){
    this->name_ = name;
}

void Player::changeColor(char &color){
    this->playerColor_ = color;
}

/*This public function searches through all the settlements/cities
a player has to give them the respective resources gained on
a roll. */
void Player::gainResources(int roll){
    list<settlement>::iterator current = pieces.begin();

    int size = pieces.size();
    //need to know how the city will be attached to a the color;
    
    for(int i = 0; i<size; i++){
        if(current->top.number == roll){
            this->addProperColor(current->top.color, current->city);
        }
        if(current->left.number == roll){
            this->addProperColor(current->left.color, current->city);
        }
        if(current->right.number == roll){
            this->addProperColor(current->right.color, current->city);
        }
        
        current++;
    }
   
}

/*This is a private function called by gainResources. It finds which 
of the players resources to add to given that he his settlement/city
has a part matching a number*/
void Player::addProperColor(char& color, int& city){
    if(color=='y'){
        this->yellow_ += city;
    }else if(color=='l'){
        this->lightGreen +=city;
    }else if(color=='d'){
        this->darkGreen +=city;
    }else if(color=='b'){
        this->blue += city;
    }else { //color = red
        this->red += city;
    }

}


/*this is a public function where you decide what you want to trade for.
The private function whichCardsToTrade decides which cards you will give up to attain the
card you decide on here */

void Player::convertResources(){
    this->seeResources();
    
    cout<<"1) Trade for yellow"<<endl;
    cout<<"2) Trade for light green"<<endl;
    cout<<"3) Trade for dark green"<<endl;
    cout<<"4) Trade for blue"<<endl;
    cout<<"5) Trade for red"<<endl;
    cout<<"0) Cancel"<<endl<<endl;
    int input;
    cin>>input;
    if(input==1 || input==2 || input==3 || input==4 || input==5){
        this->whichCardsToTrade();

        if(input==1)
            this->yellow++;
        else if (input==2)
            this->lightGreen++;
        else if(input==3)
            this->darkGreen++;
        else if(input==4)
            this->blue++;
        else if(input==5)
            this->red++;

    }else
        cout<<"Cancelled"<<endl;
    
}


/*this private function lets you trade cards with the bank.
it finds the conversion factor to get a trade. The defualt
is 4, it has to check ports to see if you can get a better deal though. */

void Player::whichCardsToTrade(){
    //maybe show the conversion too rather than just assuming the person knows
    int yellow = findBestTrade('y');
    int lightGreen = findBestTrade('l');
    int darkGreen = findBestTrade('d');
    int blue = findBestTrade('b');
    int red = findBestTrade('r');

    cout<<"1) Give up yellow        "<<yellow<<":1"<<endl;
    cout<<"2) Give up light green   "<<lightGreen<<":1"<<endl;
    cout<<"3) Give up dark green    "<<darkGreen<<":1"<<endl;
    cout<<"4) Give up blue          "<<blue<<":1"<<endl;
    cout<<"5) Give up red           "<<red<<":1"<<endl;
    cout<<"0) Cancel"<<endl;
    int input;
    cin>>input;

    if(input==1 || input==2 || input==3 || input==4 || input==5){

        if(input==1){
            Player.yellow-=yellow;
        }else if (input==2){
            Player.lightGreen-=lightGreen;
        }else if(input==3){
            Player.darkGreen-=darkGreen;
        }else if(input==4){
            Player.blue-=blue;
        }else{
            Player.red-=red;
        }
        this->showResources();

    }else
        cout<<"Cancelled"<<endl;
}

int findBestTrade(char & color){
    list<settlement>::iterator current = pieces.begin();

    int tradeDefault = 4;

    int size = pieces.size();
    for(int i = 0; i<size; ++i){
        if(current->port == color)
            return 2;
        else if(current->port == '3')
            tradeDefault=3;

        current++;
    }

    return tradeDefault;

}
