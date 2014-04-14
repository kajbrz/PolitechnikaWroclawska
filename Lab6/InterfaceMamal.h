#pragma once

#include <iostream>
using namespace std;
class InterfaceMamal
{
public:	
	InterfaceMamal(void);
	~InterfaceMamal(void);
	
	virtual int get_Semester() = 0;
	virtual int IsOlderFrom(InterfaceMamal* interfaceMamal)
	{
		/*
		cout << "\nWywolanie funkcji:";
		cout << "pointer: " << interfaceMamal->get_Semester();
		cout << "this: " << this->get_Semester();
		*/
		if(interfaceMamal->get_Semester() > this->get_Semester())
		{
			return 1;
		}
		else 
			return 0;
	}
};

