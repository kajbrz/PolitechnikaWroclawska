// Laboratorium4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

#include <iostream>
using namespace std;

#include "Human.h"
#include "Student.h"
#include "Tutor.h"


/////////////////
int Human::Licznik_obiektow = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	/*KOMENTARZE 
	//Hermetyzacja przy dziedziczeniu	
	dziedzi¹c klasê bazow¹ jako prywatn¹ lub chronion¹ tracimy w pochodnych dostêp do metod
	dlatego musimy pamiêtaæ o typie dziedziczenia "public" przed klas¹:	class Student : public Human{};

	
	//Zmienne Statyczne i dziedziczenie;
	licznik_obiektow - licznik wywo³añ
	konstruktor z klasy Human jest wywo³ywany za ka¿dym razem tylko 1 raz


	//kopiowanie 
	Mo¿na skopiowaæ klasê pochodn¹ do klasy zdziedziczonej czyli student = tutor, lecz nie da siê skopiowaæ tutor= student 
	poniewa¿ tutor posiada o wiele wiêcej zmiennych
	*/
	Human human;
	Student student(231231,0,0,sex::female,"unknown","unknown","unknown","unknown"), student1;
	Tutor tutor("unknown",0,0,0,0,sex::female,"unknown","unknown","unknown","unknown");

	human = student;
	student1 = tutor;
	student = tutor;

	cout << student <<  "haha";
	}