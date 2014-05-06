#pragma once
#ifndef TUTOR_H
#define TUTOR_H

#include <iostream>
using namespace std;

#include <string>
#include "Student.h"
#include "Human.h"


#include <string>
class Tutor : public Student
{
private:
	std::string sciencetitle;
	int countofpublications;
public:
	Tutor();
	Tutor(std::string,int,int,int,int,::sex,std::string,std::string,std::string,std::string);
	~Tutor();
	std::string get_sciencetitle();
	void set_sciencetitle(std::string);

	int get_countofpublications();
	void set_countofpublications(int);

	Tutor& operator=(Tutor& a);
};

ostream & operator<< (ostream &wyjscie, Tutor &tutor)  ;

#endif
