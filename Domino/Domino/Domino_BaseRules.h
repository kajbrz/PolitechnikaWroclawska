#pragma once
#include "managementdomino.h"


class Domino_BaseRules :
	public ManagementDomino
{
protected:
	::status status;
	int block_of_every_player; //this is count of how much block has one player on start;

	//Time is in seconds
	int game_time;
	int game_part_time;

	int who_plays;			//number of actual player
public:
	Domino_BaseRules(int,int,int,int);
	~Domino_BaseRules(void);


	void change_player();
};

