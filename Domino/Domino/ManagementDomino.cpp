#include "ManagementDomino.h"

ManagementDomino::ManagementDomino(void)
{
}


ManagementDomino::~ManagementDomino(void)
{
}


int ManagementDomino::transferdomino(pool from, pool to, int arrayindex[], int howmuch, bool isend)
{
	vector<BlockDomino> temp; //inicializate a temporary list of blocks of domino


	///////////////////
	//Download every indicated block
	for(int i=0; i< howmuch; i++)
	{
		int currentindex = arrayindex[howmuch - i - 1];
		switch(from)
		{
		case  jackpot:
			{
				temp.push_back(blockdomino_jackpot.at(currentindex)); // save one of block to the temp
				blockdomino_jackpot.erase(blockdomino_jackpot.begin()+currentindex);

				break;
			}
		case  player1:
			{
				temp.push_back(blockdomino_player1.at(currentindex));
				blockdomino_player1.erase(blockdomino_player1.begin()+currentindex);

				break;
			}
		case  player2:
			{
				temp.push_back(blockdomino_player2.at(currentindex));
				blockdomino_player2.erase(blockdomino_player2.begin()+currentindex);
				break;
			}
		case  onboard:
			{
				temp.push_back(blockdomino_onboard.at(currentindex));
				blockdomino_onboard.erase(blockdomino_onboard.begin()+currentindex);
				break;
			}
		}
	}
	//////////////////////////////////////////

	//Put all of them to right place

	if(isend==true)
	{
		switch(to)
		{
			case  jackpot:
			{
				blockdomino_jackpot.insert(blockdomino_jackpot.end(),temp.begin(), temp.end());
				break;
			}
			case  player1:
			{
				blockdomino_player1.insert(blockdomino_player1.end(),temp.begin(), temp.end());
				break;
			}
			case  player2:
			{
				blockdomino_player2.insert(blockdomino_player2.end(),temp.begin(), temp.end());
				break;
			}
			case  onboard:
			{
				blockdomino_onboard.insert(blockdomino_onboard.end(),temp.begin(), temp.end());
				break;
			}
		}
	}
	else
	{
		switch(to)
		{
			case  jackpot:
			{
				blockdomino_jackpot.insert(blockdomino_jackpot.begin(),temp.begin(), temp.end());
				break;
			}
			case  player1:
			{
				blockdomino_player1.insert(blockdomino_player1.begin(),temp.begin(), temp.end());
				break;
			}
			case  player2:
			{
				blockdomino_player2.insert(blockdomino_player2.begin(),temp.begin(), temp.end());
				break;
			}
			case  onboard:
			{
				blockdomino_onboard.insert(blockdomino_onboard.begin(),temp.begin(), temp.end());
				break;
			}
		}
	}

	return 0;
}

void ManagementDomino::clear_board()
{
	blockdomino_jackpot.clear();
	blockdomino_onboard.clear();
	blockdomino_player1.clear();
	blockdomino_player2.clear();
}

void ManagementDomino::clear_board_without_onboard()
{
	blockdomino_jackpot.clear();
	blockdomino_player1.clear();
	blockdomino_player2.clear();
}



void ManagementDomino::draw_pull(int howmanyblocks, ::pool where)
{
    srand((unsigned)time(NULL));

	if(howmanyblocks<2)
		howmanyblocks = 2;


	for (int i = 0; i < howmanyblocks; i++)
	{
		int a = rand() % 7;
		int b = rand() % 7;
		switch(where)
		{
		case :: jackpot:
			{
				blockdomino_jackpot.push_back(BlockDomino(a,b));
				break;
			}
		case :: player1:
			{
				blockdomino_player1.push_back(BlockDomino(a,b));
				break;
			}
		case :: player2:
			{
				blockdomino_player2.push_back(BlockDomino(a,b));
				break;
			}
		case :: onboard:
			{
				blockdomino_onboard.push_back(BlockDomino(a,b));
				break;
			}
		}
	}
}
