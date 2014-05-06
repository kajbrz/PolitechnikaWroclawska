#include "DominoAI.h"
#include <iostream>
#include <cstdlib>
DominoAI::DominoAI(InterfaceDomino *game, enum level level =  random, int whoIam = 1)
	: game(game)
{
	this->level = level;
	this->whoIam = whoIam;
}
DominoAI::DominoAI(void)
{
	game = nullptr;
	//game = NULL;
}


DominoAI::~DominoAI(void)
{

}

void DominoAI::set_level(enum level level)
{
	this->level = level;
}
bool DominoAI::play()
{
	srand((int)time(NULL));

	if(whoIam != game->get_who_play() || game->get_status_game() != status::start)
	{
		return false;
	}

	if(game->get_count_onboardI() == 0)
	{
		if(game->send_block(0,0,whoIam)!=0)
		{
			;
		}

		return true;
	}

	BlockDomino left_side  = game->get_leftblockdomino();
	BlockDomino right_side  = game->get_rightblockdomino();

	int left_side_value = game->get_left_value();
	int right_side_value = game->get_right_value();

	bool left_double;
	bool right_double;

	if(left_side.get_rotate() == rotate::vertical)
	{
		left_side_value *= 2;
		left_double = true;
	}
	if(right_side.get_rotate() == rotate::vertical)
	{
		right_side_value *= 2;
		right_double = true;
	}

	int modulo_left = left_side_value % 5;

	int modulo_right = right_side_value % 5;


	vector<indexing> index_available;
	int many;
	if(whoIam==0)
	{
		many = game->get_count_player1I();
		for(int i = 0 ; i < many; i++)
		{
			BlockDomino temp = game->get_blockdomino_player1I(i);
			int up = temp.get_value_up();
			int down = temp.get_value_down();
			bool doublevalue;
			if(up==down)
				doublevalue = true;
			else
				doublevalue = false;
			if(up==game->get_left_value()
				|| down == game->get_left_value())
			{
				index_available.push_back(indexing(i,false));
			}
			if(up==game->get_right_value()
				||down == game->get_right_value())
			{
				index_available.push_back(indexing(i,true));
			}
		}
	}

	if(whoIam==1)
	{
		many = game->get_count_player2I();
		for(int i = 0 ; i < many; i++)
		{
			BlockDomino temp = game->get_blockdomino_player2I(i);
			int up = temp.get_value_up();
			int down = temp.get_value_down();
			bool doublevalue;
			if(up==down)
				doublevalue = true;
			else
				doublevalue = true;

			if(up==game->get_left_value()
				|| down == game->get_left_value())
			{
				index_available.push_back(indexing(i,false));
			}
			if(up==game->get_right_value()
				||down == game->get_right_value())
			{
				index_available.push_back(indexing(i,true));
			}
		}
	}
	int many_indexes = index_available.size();

	if(many_indexes == 0)
	{
		game->draw_domino(whoIam);
		return false;
	}

	int choosen_index = 0;
	int choosen_value = 0;/*
	for(int i=0; i<many_indexes; i++)
	{
		int index = index_available[i].index;
		bool isEnd = index_available[i].isEnd;
		BlockDomino temp;
		if(whoIam==0)
		{
			temp = game->get_blockdomino_player1I(i);
		}
		else
		{
			temp = game->get_blockdomino_player2I(i);
		}



	}*/
	choosen_index = rand()%index_available.size();

	int side;
	if(index_available[choosen_index].isEnd==false)
		side = 0;
	else
		side = 1;

	std::cout << "Send block: [" << game->get_blockdomino_player2I(index_available[choosen_index].index).get_value_up()
		<< ";" << game->get_blockdomino_player2I(choosen_index).get_value_down() << "]";

	game->send_block(index_available[choosen_index].index, side, whoIam);

	index_available.clear();
	return true;
}
