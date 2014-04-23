#include "stdafx.h"
#include "Domino_BaseRules.h"


Domino_BaseRules::Domino_BaseRules(int game_time,
				int game_part_time,
				int who_plays,
				int block_of_every_player)
{
	this->status = status::stop;
	this->game_time = game_time;
	this->game_part_time = game_part_time;
	this->who_plays = who_plays;
	this->block_of_every_player = block_of_every_player;
}

Domino_BaseRules::~Domino_BaseRules(void)
{
}

void Domino_BaseRules::change_player()
{
	if(who_plays==0)
		who_plays=1;
	else
		who_plays=0;
}