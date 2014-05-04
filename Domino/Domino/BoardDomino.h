#pragma once
/*
Specification of lookout of board game

one Jackpot -> Pot all of draw randomly blocks;
two Players -> Pots of player's blocks;
one onBoard -> Pot who see everyone players

*/
#include <vector>
#include "BlockDomino.h"
#include <ctime>
using namespace std;




class BoardDomino
{
protected:
    vector<BlockDomino> blockdomino_jackpot; // list of jackpot
    vector<BlockDomino> blockdomino_player1; // list of player1
    vector<BlockDomino> blockdomino_player2; // list of player2
    vector<BlockDomino> blockdomino_onboard; // list of onBoard

public:
	BoardDomino();
	virtual ~BoardDomino(void);


	//Setters and getters
	
	BlockDomino get_blockdomino_jackpot(int at);	
	BlockDomino get_blockdomino_player1(int at);	
	BlockDomino get_blockdomino_player2(int at);	
	BlockDomino get_blockdomino_onboard(int at);	
	
	int get_count_jackpot(){return blockdomino_jackpot.size();}
	int get_count_player1(){return blockdomino_player1.size();}
	int get_count_player2(){return blockdomino_player2.size();}
	int get_count_onboard(){return blockdomino_onboard.size();}
	///////////////////////
};

