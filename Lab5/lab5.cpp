// Laboratorium4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

#include <iostream>
using namespace std;

#include "Human.h"
#include "Student.h"
#include "Student2.h"
#include "Tutor.h"


/////////////////
int Human::Licznik_obiektow = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	/*KOMENTARZE
	//destruktor wirtualny w klasie bazowej
	Destruktor wirtualny w klasie bazowej zapewnia wywo³anie wszystkich destruktorów klas potomnych podczas niszczenia obiektu. 
	Czyli nie usun¹³by siê wskaŸnik na dynamiczn¹ tablicê w klasie Human.

	*/

	Student2 student;
	Student student2;
	student2 = student;
	cin >> student;

	cout << student;

}