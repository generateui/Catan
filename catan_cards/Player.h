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
    char playerColor_;

    //resources
    int yellow_;     //y
    int lightGreen_; //l
    int darkGreen_;  //d
    int blue_;       //b
    int red_;        //r

    //developmentCards
    int knight_;
    int victoryPointCard_;
    int roadBuilder_;
    int monopoly_;
    int yearOfPlenty_;
    struct component{
        int number;
        char color; //y, l, d, b, or r 
    }
 
    struct settlement{
        int city; //1 if settlement, 2 if city.
        component top;
        component left;
        component right;
        char port; //port will be the same as color y, l, d, b, r, or of course '3' for the 3:1 port
    };

    list<settlement> pieces;

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
    void whichCardsToTrade();       //trade withself
    void tradeResources(Player &);  //trade with another player
    int findBestTrade(char&);

    //gaining resources
    void addProperColor(char&, int&);

    public:
    int roll();

    void checkStats();
    void seeResources();
    void seeDevelopments();
    void buyItem();
    void changeName(String&);
    void changeColor(char&);
    void convertResources(); //try to switch out cards

    //constructor
    Player();
    ~Player();
};
