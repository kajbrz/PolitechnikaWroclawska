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
	std::string ScienceTitle;
	int CountOfPublications;
public:
	Tutor();
	Tutor(std::string,int,int,int,int,sex,std::string,std::string,std::string,std::string);	
	~Tutor();
	std::string get_ScienceTitle();
	void set_ScienceTitle(std::string);

	int get_CountOfPublications();
	void set_CountOfPublications(int);
	
	Tutor& Tutor::operator=(Tutor& a);
};

ostream & operator<< (ostream &wyjscie, Tutor &tutor)  ;

#endif