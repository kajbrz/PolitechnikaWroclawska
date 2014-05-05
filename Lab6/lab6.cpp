// lab6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Tutor.h"
#include "Student2.h"
int _tmain(int argc, _TCHAR* argv[])
{
	//Nie mo�na zainicjalzowa� klasy abstrakcynej -> klasy posiadajcej cho� jedn� niezdefiniowan� funkcj� wirtualn� - virtual
	//Mamal mamal;
	//Taka definicja jest zabroniona je�li nie zainicjalizujemy prze�adujemy w klasie metody abstrakcyjnej klasy bazowej 
	/*
	Human human;	
	human.set_Age(15);	
	Student student;
	student.set_Age(15);
	cout << endl << "Human: " << human.birthday();
	cout << endl << "Student: " << student.birthday();
	//////////////////////////////
	
	Mamal *p_Mamal;
	p_Mamal = &human;

	cout << "\n\n" << p_Mamal ->birthday();
	
	p_Mamal = &student;
	cout << "\n\n" <<p_Mamal->birthday();


	Mamal *p_Mamal2 = new Human;
	cout << "\nWsk2:\n\n" << (p_Mamal2)->birthday();
	cout << "\n\n" << static_cast<Student*>(p_Mamal2)->birthday();

	delete p_Mamal2;
	*/
	//////////////////////////////


	Student pierwszy; //u�ywamy tutraj interface kt�ry jest dziedziczony
	pierwszy.set_semester(5);

	Student2 drugi;
	drugi.set_semester(9);
	
	Tutor trzeci;
	trzeci.set_semester(11);
	
	//Wska�nik na interface InterfaceMamal
	//Przy u�yciu tylko jednej metody tej klasy mo�emy por�wna� dwa r�ne w hierarchii klasy

	InterfaceMamal *ptr_p, *ptr_d, *ptr_t;
	ptr_p = &pierwszy;
	ptr_d = &drugi;
	ptr_t = &trzeci;


	//funkcja isOlderFrom por�wnuje warto�ci Semester na r�znej wysoko�ci hierrachi. 
	//Co jest jednoznaczne z polimorfizmem

	if(ptr_p->isolderfrom(ptr_d))
	{
		cout << "\n\nPierwszy mlodszy";
	}
	else
	{
		cout << "\n\nDrugi mlodszy";
	}
	
	if(ptr_t->isolderfrom(ptr_d))
	{
		cout << "\n\ntrzeci mlodszy";
	}
	else
	{
		cout << "\n\nDrugi mlodszy";
	}
	


	return 0;
}

