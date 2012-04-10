#include<iostream>
#include<string>
#include<list>

using namespace std;

class Player{

    private:
    string name_;
    int victoryPoints_;
    int roadLength_;
    int armySize_;

    //resources
    int yellow;
    int lightGreen;
    int darkGreen;
    int blue;
    int red;

    //developmentCards
    int knight;
    int victoryPointCard;
    int roadBuilder;
    int monopoly;
    int yearOfPlenty;

    struct Settlement{
        int city; //1 if settlement, 2 if city.
        int top;
        int left;
        int right;
        char port;
    };

    list<Settlement> pieces;

    void checkLongestRoad();
    void checkLargestArmy();

    //called from checkStats()
    int  numberOfResources();
    int  numberOfDevelopments();

    //called from buyItem()
    void buyRoad();
    void buySettlement();
    void buyCity();
    void buyDevelopmentCard();
    //Trading cards
    void whichCardsToTrade(); //trade withself 

    public:
    void tradeResources(Player &, Player &);
    void buyResources(Player &);
    int roll();
    void checkStats();
    void seeResources();
    void seeDevelopments();
    void buyItem();

    void switchOutCards();

    //constructor
    Player();
    ~Player();
};
