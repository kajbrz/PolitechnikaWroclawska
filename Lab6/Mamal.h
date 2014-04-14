#pragma once
#ifndef MAMAL_H
#define MAMAL_H
#include <string>
class Mamal
{
public:
	virtual std::string birthday() = 0;

	Mamal(void);
	~Mamal(void);
};

#endif