#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;


void startCatan()
				{
	//Print out of start Screen
	int totalPlayers;
	int playersDice[];
	
	cout<< "Welcome to Catan!!";
	cout<< "\nHow many people are playing?";	//Establish how many players in the game.
	cin >> numberPlayers;
	
	for(i=1; numberPlayers < i; i++)	//For each player to decide on a color.
	{
		cout<< "What color do you want to be player "<< i << ".\n";
		//either use buttons for colors or display the options for colors
		//cin>> color;
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
	
	playerTurn()	
}

int Roll()
{
	int die;
	die=(int)(rand()%6)+1;
	return die;
}

landAssignment(char building, int player, int setup)
{
	if(building == 's' && setup == 1)
	{
		//Place a settlement
		//Check for placement in this area
		roadPlacement(player);
	}
	
	else if(building == 's' && setup == 0)
	{
		//Place a settlement
		//Check for placement in this area
		//check for two roads connected to a settlement or city
	}
	
	if(building == 'c')
	{
		//Place a city 
		//check for placement in this area
		//Make sure that there is two roads attached.
		//Make sure that there is no settlements within two spots.
	}
	
	else
	cout<< "ERROR";
}

void roadPlacement(int player)
{
	//Place Road
	//Make sure nothing is in spot.
	//Make sure that the road is connected to the same road, settlement, or city.
}