
#include "Domino_NormalRules.h"


//Rules is set on start in constructor of class and it is constantly
//
/*
howmanyblocks - How many blocks is draw on start - 28
game_time - How long be play a one game - 60sec * 10 = 10min
game_part_time - How much time has one player to make move - 60sec = 1min
who_plays - it is random of who start a game - 0 or 1
block_of_every_player - How many blocks players get on the start
*/

Domino_NormalRules::Domino_NormalRules(void)
	:Domino_BaseRules(60*10,60*1,rand()%2,6)

{
	status =stop;
	//points_minimum = 100;
	points_minimum = 10;
	
}

Domino_NormalRules::~Domino_NormalRules(void)
{

}

int Domino_NormalRules::start_game(void)
{
	change = false;
	if(status== start)
		return -1;
	else if(status== pause)
	{
		status =  start;
	}
	else
	{
		status =  start;
		who_won = points_player1 = points_player2 =  0;
		draw_pulls();
	}

	return 0;
}

int Domino_NormalRules::stop_game(void)
{
	if(status== stop)
		return -1;
	else
		status =  stop;
	clear_board();
	status =  stop;

	return 0;
}

int Domino_NormalRules::pause_game(void)
{
	if(status== pause || status== stop)
		return -1;
	else
		status =  stop;

	status =  stop;

	return 0;
}

int Domino_NormalRules::send_block(int indeks, int side)
{
	if(change == true)
	{
		return -1;
	}
	/////////////////////////////
	////Testing correct var at///
	::pool pool;
	if(who_plays==0)
		pool = player1;
	else
		pool = player2;
	BlockDomino temp;
	if(pool == player1)
	{
		if(indeks<0 || indeks>=get_count_player1())
			return -1;
		temp = get_blockdomino_player1I(indeks);
	}
	else
	{
		if(indeks<0 || indeks>=get_count_player1())
			return -1;
		temp = get_blockdomino_player2I(indeks);
	}
	///////////////////////
	//temp array needed to transfer_domino function
	int* temp_array_of_index = new int[1];
	temp_array_of_index[0] = indeks;
	//////////////////////////

	//if on board aren't any blocks//
	bool no_move_error = true;
	if(left_value == -1)
	{
		if(temp.get_value_down() == temp.get_value_up())
		{
			set_rotate(pool,indeks, vertical);
			left_vertical = false;
			left_value = right_value = temp.get_value_down();
		}
		else
		{
			set_rotate(pool,indeks, horizontal_left);
			left_vertical = false;
			left_value = temp.get_value_up();
			right_value = temp.get_value_down();
		}
		transferdomino(pool,onboard, temp_array_of_index,1,false);
		no_move_error = false;
	}
	if(no_move_error == true)
	{
		if(side==0)
		{
			if(left_value == temp.get_value_down() || left_value == temp.get_value_up())
			{
				if(temp.get_value_down() == temp.get_value_up())
				{
					set_rotate(pool,indeks, vertical);
					left_value = temp.get_value_down();
					left_vertical = true;
				}
				else if(left_value == temp.get_value_down())
				{
					set_rotate(pool,indeks, horizontal_left);
					left_value = temp.get_value_up();
					left_vertical = false;
				}
				else
				{
					set_rotate(pool,indeks, horizontal_right);
					left_value = temp.get_value_down();
					left_vertical = false;
				}
				transferdomino(pool,  onboard, temp_array_of_index,1,false);
				no_move_error = false;
			}
		}
		else
		{
			if(right_value == temp.get_value_down()|| right_value == temp.get_value_up())
			{
				if(temp.get_value_down() == temp.get_value_up())
				{
					set_rotate(pool,indeks, vertical);
					right_value = temp.get_value_down();
					right_vertical = true;
				}
				else if(right_value == temp.get_value_down())
				{
					set_rotate(pool,indeks, horizontal_right);
					right_value = temp.get_value_up();
					right_vertical = false;
				}
				else
				{
					set_rotate(pool,indeks, horizontal_left);
					right_value = temp.get_value_down();
					right_vertical = false;
				}
				transferdomino(pool,  onboard, temp_array_of_index,1,true);
				no_move_error = false;
			}
		}
	}
	delete [] temp_array_of_index;

	if(no_move_error == false)
	{
		change = true;
		start_player_time_game = (float)GetTickCount();
		return 0;
	}
	else
	{
		return -2;
	}
}

int Domino_NormalRules::send_block(int indeks, int side, int player)
{
	if(player==who_plays)
		return send_block(indeks,side);
	else
		return -2;
}

int Domino_NormalRules::get_global_time_end(void)
{
	return game_time-(int)((float)GetTickCount() - start_time_game)/1000;
}

int Domino_NormalRules::get_player_time_end(void)
{
	return game_part_time-(int)((float)GetTickCount() - start_player_time_game)/1000;
}

::status Domino_NormalRules::get_status_game(void)
{
	return status;
}

int Domino_NormalRules::get_who_play(void)
{
	return who_plays;
}

BlockDomino Domino_NormalRules::get_blockdomino_jackpotI(int at)
{
	try
	{
		return get_blockdomino_jackpot(at);
	}
	catch(int e)
	{
		std::cout << "\nError:" << e << ", you used index out border, I'll return a BlockDomino(0,0)";
		return BlockDomino(0,0);
	}
}

BlockDomino Domino_NormalRules::get_blockdomino_player1I(int at)
{
	try
	{
		return get_blockdomino_player1(at);
	}
	catch(int e)
	{
		std::cout << "\nError:" << e << ", you used index out border, I'll return a BlockDomino(0,0)";
		return BlockDomino(0,0);
	}
}

BlockDomino Domino_NormalRules::get_blockdomino_player2I(int at)
{
	try
	{
		return get_blockdomino_player2(at);
	}
	catch(int e)
	{
		std::cout << "\nError:" << e << ", you used index out border, I'll return a BlockDomino(0,0)";
		return BlockDomino(0,0);
	}
}

BlockDomino Domino_NormalRules::get_blockdomino_onboardI(int at)
{
	try
	{
		return get_blockdomino_onboard(at);
	}
	catch(int e)
	{
		std::cout << "\nError:" << e << ", you used index out border, I'll return a BlockDomino(0,0)";
		return BlockDomino(0,0);
	}
}

int Domino_NormalRules::test_game(void)
{
	if(change==true)
	{
		int l_val = left_value;
		int r_val = right_value;
		if(left_vertical==true)
			l_val *=2;
		if(right_vertical==true)
			r_val *=2;

		int sum = l_val + r_val;
		if(sum%5==0)
		{
			if(who_plays==0)
				points_player1 +=sum;
			else
				points_player2 +=sum;
		}

		change = false;
		change_player();
	}

	if(points_player1>=points_minimum)
	{
		who_won = 1;
		status = stop;
		return -2;
	}
	if(points_player2>=points_minimum)
	{
		who_won = 2;
		status = stop;
		return -2;
	}

	//if(get_player_time_end()<=0)
	//{
	//	change_player();
	//	start_player_time_game = (float)GetTickCount();
	//	return -2; //something was happens
	//}

	if(get_global_time_end()<=0)
	{
		count_points();
		clear_board();
		stop_game();
		return -2; //the game is end
	}

	if(blockdomino_player1.size() == 0)
	{
		count_points();
		clear_board();
		draw_pulls();
		change_player();
		return -1; //The round is end
	}
	else if(blockdomino_player2.size() == 0)
	{
		count_points();
		clear_board();
		draw_pulls();
		change_player();
		return -1;	//The round is end
	}
	else if(blockdomino_jackpot.size() == 0)
	{
		count_points();
		clear_board();
		draw_pulls();
		change_player();
		return -1;	//The round is end
	}
	return 0; //return 0 if nothing happen
}


void Domino_NormalRules::set_rotate(::pool pool, int index, ::rotate rotate) // set  rotate in correct place
{
	if(pool ==  player1)
	{
		blockdomino_player1.at(index).set_rotate(rotate);
	}
	else
	{
		blockdomino_player2.at(index).set_rotate(rotate);
	}
}

//int Domino_NormalRules::draw_domino(void)
int Domino_NormalRules::draw_domino(int whoplay = -1)
{
	if(whoplay!= -1)
		if(whoplay != who_plays)
			return -1;
	if(blockdomino_jackpot.size()==0)
		return -1;
	else
	{
		::pool player;
		if(who_plays==0)
			player =  player1;
		else
			player =  player2;

		int *temp_array_of_blocks = new int[1];
		temp_array_of_blocks[0] = 0;
		transferdomino(jackpot, player, temp_array_of_blocks,1,true);
		delete [] temp_array_of_blocks;

		return 0;
	}
}

int Domino_NormalRules::get_who_won()
{
	return who_won;
}


void Domino_NormalRules::get_points_each_block(int& player1, int& player2)
{
	player1 = 0;
	player2 = 0;

	for(int i=0; i<get_count_player1I(); i++)
	{
		player1 +=
			blockdomino_player1.at(i).get_value_up() +
			blockdomino_player1.at(i).get_value_down();
	}


	for(int i=0; i<get_count_player2I(); i++)
	{
		player2 +=
			blockdomino_player2.at(i).get_value_up() +
			blockdomino_player2.at(i).get_value_down();
	}
}

int Domino_NormalRules::get_points_player1()
{
	return points_player1;
}
int Domino_NormalRules::get_points_player2()
{
	return points_player2;
}



BlockDomino Domino_NormalRules::get_leftblockdomino()
{
	return blockdomino_onboard[0];
}
BlockDomino Domino_NormalRules::get_rightblockdomino()
{
	return blockdomino_onboard[blockdomino_onboard.size()-1];
}


void Domino_NormalRules::count_points()
{
	int sum_block_point_player1=0;
	int sum_block_point_player2=0;

	get_points_each_block(sum_block_point_player1, sum_block_point_player2);


	if(sum_block_point_player1 != sum_block_point_player2)
	{
		if(sum_block_point_player1 < sum_block_point_player2)
		{

			sum_block_point_player2 += -sum_block_point_player1;

			sum_block_point_player2 += sum_block_point_player2%5;

			points_player1 += sum_block_point_player2;
		}
		else
		{
			sum_block_point_player1 += -sum_block_point_player2;

			sum_block_point_player1 += (sum_block_point_player1%5);

			points_player2 += -sum_block_point_player1;
		}
	}
	points_player1 += points_player1%5;
	points_player2 += points_player2%5;
}

void Domino_NormalRules::draw_pulls(void)
{

		who_plays = rand()%2; //random who move first

		//set when players start a game
		start_time_game = (float)GetTickCount();
		start_player_time_game = (float)GetTickCount();

		draw_pull(28,:: jackpot);  //add to jackpot 28 blocks of domino

		int *temp_array_of_blocks = new int[block_of_every_player];
		for(int i=0; i<block_of_every_player; i++)
		{
			temp_array_of_blocks[i] = i;
		}
		transferdomino( jackpot,  player1, temp_array_of_blocks, block_of_every_player, false);
		transferdomino( jackpot,  player2, temp_array_of_blocks, block_of_every_player, false);
		delete [] temp_array_of_blocks;

		left_value = -1; // -1 it's means without start value
		right_value = -1; // as above
}
