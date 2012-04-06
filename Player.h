#include<iostream>

class Player{

    private:
    int victoryPoints;
    int roadLength;
    int armySize;

    struct resources{
        int yellow;
        int lightGreen;
        int darkGreen;
        int blue;
        int red;
    }

    struct developmentCards{
        int knight;
        int victoryPoint;
        int roadBuilder;
        int monopoly;
        int yearOfPlenty;
    }

    struct Settlement{
        bool isCity; //if true we'll multiply by 2
        int top;
        int left;
        int right;
        char port;
    }
    list<Settlement> pieces;

    void checkStats();
    void checkLongestRoad();
    void checkLargestArmy();

    public:
    void tradeResources(Player &, Player &);
    void buyResources(Player &);
    int roll();
}
