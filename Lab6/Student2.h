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
	double* srednia;
	int countofsrednia;
	::degree degree;
public:
	Student2(void);
	~Student2(void);
	
	void set_average();
	
	void set_degree(::degree degree);
	inline ::degree get_degree(){return degree;}

	Student2& Student2::operator=(Student2& );
	friend istream& operator>> (istream&, Student2&);

	double* get_srednia(){return this->srednia;}
	void set_srednia(double* Srednia, int count2);
	int get_countofsrednia(){return countofsrednia;}
	void set_countofsrednia(int countOfSrednia){this->countofsrednia = countOfSrednia;} 
	
};


ostream & operator<< (ostream &wyjscie, const degree Degree);
ostream & operator<< (ostream &wyjscie, Student2 &student);     
#endif
