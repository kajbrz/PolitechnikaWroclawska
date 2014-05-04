#pragma once
#include "domino_baserules.h"
#include "InterfaceDomino.h"

#include <iostream>
#include <windows.h>
class Domino_NormalRules :
	public Domino_BaseRules,
	public InterfaceDomino
{
private:
	bool change; // 

	float start_time_game; //When game was start
	float start_player_time_game;  //When start play one of player

	//in normal game you have only 2 sides of blocks of value, that left and right
	//on start we haven't any of value, but after first move we had 2;
	int left_value; //left value of value on board
	bool left_vertical;
	
	int right_value; //right value of value on bard
	bool right_vertical;

	int points_player1;
	int points_player2;
	int points_minimum;

	int who_won; // 0 - nobody, 1- Player1, 2 - Player2, 3-Draw
	
	void get_points_each_block(int& player1, int& player2);
	void set_rotate(::pool pool, int index, ::rotate rotate); // set  rotate in correct place	
	void count_points();
	void draw_pulls();
public:
	Domino_NormalRules(void);
	~Domino_NormalRules(void);

	///	
	int get_left_value(){return left_value;}
	int get_right_value(){return right_value;}
	///
	//those functions must return 0 if they haven't errors	
	int start_game(void); //start a game
	int stop_game(void); //stop a game -its like game over
	int pause_game(void); //pause a game
	int send_block(int indeks, int side); //choose block which you'll use and side  without player -> player is choosen automaticly
	int send_block(int indeks, int side, int player); //choose block which you'll use and side with player-> player is choosen
	
	int get_who_won();
	/////////////////////////////////
	/*
	those functions must be checked in every loop
	*/
	int get_global_time_end(void);	//get time to end the game. What happend after end will defining under-class 
	int get_player_time_end(void);	//get time left to move
	::status get_status_game(void);	//what happend on the board
    int get_who_play(void);			//get who is play now

	
	BlockDomino get_blockdomino_jackpotI(int at);	
	BlockDomino get_blockdomino_player1I(int at);	
	BlockDomino get_blockdomino_player2I(int at);	
	BlockDomino get_blockdomino_onboardI(int at);
	
	BlockDomino get_leftblockdomino();
	BlockDomino get_rightblockdomino();
	
	int get_count_jackpotI(){return blockdomino_jackpot.size();}
	int get_count_player1I(){return blockdomino_player1.size();}
	int get_count_player2I(){return blockdomino_player2.size();}
	int get_count_onboardI(){return blockdomino_onboard.size();}

	int test_game(void);	
	int draw_domino(int);

	int get_points_player1();
	int get_points_player2();

};

