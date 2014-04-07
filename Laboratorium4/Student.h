#pragma once
#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
using namespace std;

#include <string>
#include "Human.h"

#include <string>
class Student : public Human
{
private:
	int NumberOfRegister;
	int Semester;
	std::string Branch;
	std::string Faculty;
public:
	Student();
    Student(int, int,int,sex,std::string,std::string,std::string,std::string);
	~Student();
	int get_NumberOfRegister();
	void set_NumberOfRegister(int);

	int get_Semester();
	void set_Semester(int);
	
	std::string get_Branch();
	void set_Branch(std::string);

	std::string get_Faculty();
	void set_Faculty(std::string);
	
	Student& operator=(Student&);
};

ostream & operator<< (ostream &wyjscie, Student &student);
#endif