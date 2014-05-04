#pragma once
#include "Domino\InterfaceDomino.h"
#include "DominoAIstruct.h"
class DominoAI
{	
private:
	InterfaceDomino *game;
	int whoIam;
	enum level level;

public:	
	DominoAI(InterfaceDomino *game, enum level level, int whoIam);
	DominoAI(void);
	~DominoAI(void);

	void set_level(enum level level);	
	bool play();
};

