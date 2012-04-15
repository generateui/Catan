#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;


void player::startCatan()
				{
	//Print out of start Screen
	int totalPlayers;
	int playersDice[];
	
	cout<< "Welcome to Catan!!";
	cout<< "\nHow many people are playing?";	//Establish how many players in the game.
	cin >> numberPlayers;
	
	for(i=1; numberPlayers < i; i++)	//For each player to decide on a color.
	{
		cout<< "What is your name\n?"
		cint>> this->name_;
		cout<< "\nWhat color do you want to be player "<< i << ".\n\n";
		cin>> this->color;
	}
	
	playersDice[totalPlayers];	//Create a array for dice values for each player.
	
	for(i=1; numberPlayers < i; i++)	//Roll for each player
	{
		int highestRoller, highestRoll;
		diceValue = Roll();
		playersDice[i] = diceValue;
		cout<< " Player " << i << " has rolled a " << diceValue << ".\n";
		
		if(playersDice[1])
		{
			highestRoller = i;
			highestRoll = playersDice[i];
		}
		
		else if(players[i] > players[i-1])
		{
			highestRoller = players[i]
			highestRoll = playersDice[i];
		}
		//Maybe Display Dice values.
	}
	
	
	cout<< "Player " << highestRoller << " has rolled a " << highestRoll <<". This player will go first.\n";
	
	for(i=1; numberPlayers < i; i++)	
	{
		landAssignment(s,i, 1);
	}
	
	for(i=numberPlayers; numberplayers < 0; i--)
	{
		landAssignment(s,i, 1);
	}
	
	playerTurn(numberPlayers)	
}

void player::playerTurn(int numberPlayers)
{
	int diceValue, winners,decision;
	
	while(winners == 0)
	{
		for(int i=0; numberPlayers>i; i++)
		{
			diceValue = this->roll();
			this->checkMap(diceValue);
			this->playerOptions(i);
			winners = this->playerStatCheck();
		}
	
	}
	
	cout<< "Winner Message"<< "\n\n\nWant to play again?(Y/N)\n";
	cin<< decision;
	
	if(decision == 'y' || decision == 'Y')
	{
		this->StartCatan();
	}
	
	else
	continue;
}
	
void player::playerOptions()
{	
	int choice;
	
	cout<< "What do you want to do?\n"<< "1)Buy\n2)Convert Resources\n3)Use Development Card\n4)End Turn\n";
	cin>> choice;
	
	switch(choice)
	{
	     case 1:
		this->buyItem();
	     case 2:
		this->convertResources();
	     case 3:
		this->showDevelopmentCard();
	     case 4:
		break;
	     default:
	          cout<< "Value Unknown. Try Again"
		  this->playerOptions();
	}
} 
	
void Player::showDevelopmentCards()
{
	//Show Development Cards
	//Choose one
	//Get sent to DC specific Function
}

void Player::convertResources()
{
	cout<< "What do you want to convert?"
	//Display choices depending on port availabilty
}

