#pragma once
#ifndef STUDENT2_H
#define STUDENT2_H

#include "Student.h"
#include "Human.h"

#include <string>
using namespace std;
enum degree
{
	inz,
	lic,
};

	

class Student2 :
	public Student
{
private:
	double* Srednia;
	int countOfSrednia;
	degree Degree;
public:
	Student2(void);
	~Student2(void);
	
	void set_Average();
	
	void set_Degree(degree Degree);
	inline degree get_Degree(){return Degree;}

	Student2& Student2::operator=(Student2& );
	friend istream& operator>> (istream&, Student2&);

	double* get_Srednia(){return this->Srednia;}
	void set_Srednia(double* Srednia, int count2);
	int get_countOfSrednia(){return countOfSrednia;}
	void set_countOfSrednia(int countOfSrednia){this->countOfSrednia = countOfSrednia;} 
	
};


ostream & operator<< (ostream &wyjscie, const degree Degree);
ostream & operator<< (ostream &wyjscie, Student2 &student);     
#endif
