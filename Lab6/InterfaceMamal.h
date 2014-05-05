#pragma once

#include <iostream>
using namespace std;
class InterfaceMamal
{
public:	
	InterfaceMamal(void);
	~InterfaceMamal(void);
	
	virtual int get_semester() = 0;
	virtual int isolderfrom(InterfaceMamal* interfaceMamal)
	{
		/*
		cout << "\nWywolanie funkcji:";
		cout << "pointer: " << interfaceMamal->get_Semester();
		cout << "this: " << this->get_Semester();
		*/
		if(interfaceMamal->get_semester() > this->get_semester())
		{
			return 1;
		}
		else 
			return 0;
	}
};

