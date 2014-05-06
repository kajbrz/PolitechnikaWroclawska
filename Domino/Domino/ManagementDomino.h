#pragma once
#include "boarddomino.h"
#include <cstdlib>
/*
This class has function to move blocks from one to another place
*/
class ManagementDomino :
	public BoardDomino
{
protected:
	void draw_pull(int howmanyblocks, ::pool where);
	int transferdomino(pool, pool, int[], int, bool); // (pool from, pool to, int arrayindex[], int howmuch, bool isend)
	void clear_board(void);
	void clear_board_without_onboard(void);
public:
	ManagementDomino(void);
	~ManagementDomino(void);
};

