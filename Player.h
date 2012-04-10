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

    //after further thought resources and developmentCards don't need to be
    //structs. if you think its neccessary make the neccessary changes.
    //struct resources{
        int yellow;
        int lightGreen;
        int darkGreen;
        int blue;
        int red;
    //};

    //struct developmentCards{
        int knight;
        int victoryPointCard;
        int roadBuilder;
        int monopoly;
        int yearOfPlenty;
    //};

    struct Settlement{
        bool isCity; //if true we'll multiply by 2
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

    public:
    void tradeResources(Player &, Player &);
    void buyResources(Player &);
    int roll();
    void checkStats();
    void seeResources();
    void seeDevelopments();
    void buyItem();


    //constructor
    Player();
    ~Player();
};
