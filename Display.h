#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <vector>

#include "Player.h"
#include "Resource.h"
#include "Config.h"
#include "UI.h"
#include "MapUtil.h"

using namespace std;
extern vector <Player> playerList; //vector of Player objects
extern int aliveCount; //number of players alive

class Display
{
private:
	char gameMap[MAPHEIGHT][MAPWIDTH]; //2D array of all entity objects used in the game
	
	void initMap(); //initializes the gameMap with objects from building, player, and Entity vectors in Resource.h
	
public:

	Display() //constructor 
	{
		aliveCount = playerList.size();
		initMap();
	}
	
	//comparison function for Player pointers; priority: being alive > no of kills > remaining HP > player ID
	static bool cmpKillCount(const Player* const p1, const Player* const p2);
	
	void printMap() const; //iterates through the gameMap array to print every element in a grid
	void printPlayerStats(Player* const player) const; //print player stats, called in main menu
	vector<const Player*> printLeaderboard() const; //print leaderboard. Returns the sorted list of player pointers.
	void printItem(const Item* item, const vector<int>& colSize, const int type, const int count = 0) const; //print item stats in inventory (type=0) or shop (type=1)
	void removeDeadPlayers(const vector<int>& deadPlayers); //removes dead players (in the deadPlayers vector) from map
	void playerMenu(); //switch menu to prompt specific player for action during their turn
	
	inline void incrementCurrentTurn(){ //increments to next turn or loops back to first player's turn
		playerList[currentTurn].endTurn();
		do {
			currentTurn++;
			if(currentTurn == playerList.size()) {
				currentTurn %= playerList.size();
				roundCounter++;
			}
		} while(playerList[currentTurn].getHealthStat() <= 0);
		playerList[currentTurn].beginTurn();
	}
};

#endif
