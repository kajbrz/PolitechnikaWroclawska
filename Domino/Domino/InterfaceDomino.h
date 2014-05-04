#pragma once
#include "BoardDomino.h"
class InterfaceDomino
{
public:
	InterfaceDomino(void);
	virtual ~InterfaceDomino(void);

	//those functions must return 0 if they haven't errors	
	virtual int start_game(void) = 0; //start a game
	virtual int stop_game(void) = 0; //stop a game -its like game over
	virtual int pause_game(void) = 0; //pause a game
	virtual int send_block(int indeks, int side) = 0; //choose block which you'll use and side  without player -> player is choosen automaticly
	virtual int send_block(int indeks, int side, int player) = 0; //choose block which you'll use and side with player-> player is choosen
	
	virtual int draw_domino(int) = 0 ;

	//FOR AI//
	virtual BlockDomino get_leftblockdomino() = 0;
	virtual BlockDomino get_rightblockdomino() = 0;
	
	virtual int get_left_value() = 0;
	virtual int get_right_value() = 0;
	/////////////
	virtual int get_points_player1()=0;
	virtual int get_points_player2()=0;

	/////////////////////////////////
	/*
	those functions must be checked in every loop
	*/
	virtual int get_global_time_end(void) = 0; //get time to end the game. What happend after end will defining under-class 
	virtual int get_player_time_end(void) = 0; //get time left to move
	virtual ::status get_status_game(void) = 0;  //what happend on the board
    virtual int get_who_play(void) = 0;			//get who is play now
	virtual int test_game(void) = 0;
	
	virtual int get_who_won() = 0;
	//////////////////////////////////////////////

	/////////////////////////////////	
	virtual BlockDomino get_blockdomino_jackpotI(int at) = 0;	
	virtual BlockDomino get_blockdomino_player1I(int at) = 0;	
	virtual BlockDomino get_blockdomino_player2I(int at) = 0;	
	virtual BlockDomino get_blockdomino_onboardI(int at) = 0;	
	
	
	
	virtual int get_count_jackpotI()=0;
	virtual int get_count_player1I()=0;
	virtual int get_count_player2I()=0;
	virtual int get_count_onboardI()=0;
		
};


