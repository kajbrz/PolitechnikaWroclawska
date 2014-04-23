#include "stdafx.h"
#include "BoardDomino.h"


BoardDomino::BoardDomino(void)
{
}

BoardDomino::~BoardDomino(void)
{
}



BlockDomino BoardDomino::get_blockdomino_jackpot(int at)
{
	return (blockdomino_jackpot.at(at));
}
BlockDomino BoardDomino::get_blockdomino_player1(int at)
{
	return blockdomino_player1.at(at);
}
BlockDomino BoardDomino::get_blockdomino_player2(int at)
{
	return blockdomino_player2.at(at);
}
BlockDomino BoardDomino::get_blockdomino_onboard(int at)
{
	return blockdomino_onboard.at(at);
}
