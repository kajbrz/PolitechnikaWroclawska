#pragma once

/*
There will be specification of one block of domino

example:
[::]
[:.]
*/
#include "Domino_Special_Enum.h"
class BlockDomino
{
private:
	int value_up; // value of top block
	int value_down; // value of bottom block
	::rotate rotate;
public:
	BlockDomino(void);
	BlockDomino(int, int);
	~BlockDomino(void);

	//Setters and getters
	void set_value_up(int);
	int get_value_up();
	
	void set_value_down(int);
	int get_value_down();

	void set_rotate(::rotate);
	::rotate get_rotate();
	////////////////////////
};

