#include "BlockDomino.h"

#include <ctime>


BlockDomino::BlockDomino(int value_up=-1, int value_down=-1)
{
	if(value_up>=0 && value_up<=6)
		this->value_up = value_up;
	else
		this->value_up = 0;

	if(value_down>=0 && value_down<=6)
		this->value_down = value_down;
	else
		this->value_down = 0;

	rotate = no_rotate;

}
BlockDomino::BlockDomino()
{
	value_up   = 0;
	value_down = 0;

	rotate = no_rotate;
}

BlockDomino::~BlockDomino(void)
{
}

void BlockDomino::set_value_up(int value_up)
{
	if(value_up>=0 && value_up<=6)
		this->value_up = value_up;
	else
		this->value_up = 0;
}
int BlockDomino::get_value_up()
{
	return value_up;
}

void BlockDomino::set_value_down(int value_down)
{
	if(value_down>=0 && value_down<=6)
		this->value_down = value_down;
	else
		this->value_down = 0;
}
int BlockDomino::get_value_down()
{
	return value_down;
}

void BlockDomino::set_rotate(::rotate rotate)
{
	this->rotate = rotate;
}
::rotate BlockDomino::get_rotate()
{
	return rotate;
}
