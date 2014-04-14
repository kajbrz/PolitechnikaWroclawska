#pragma once
#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
using namespace std;

#include <string>
#include "Human.h"
#include "InterfaceMamal.h"

#include <string>
class Student : public Human, public InterfaceMamal
{
private:
	int NumberOfRegister;
	int Semester;
	std::string Branch;
	std::string Faculty;
	string* Favorite_Books2;
	int count2;
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

	int get_count2(){return count2;}
	
	string* get_Favorite_Books2(){return Favorite_Books2;}
	void set_Favorite_Books2(string*, int);
	virtual string birthday();

	
	//int operator<(InterfaceMamal*);
};

ostream & operator<< (ostream &wyjscie, Student &student);



#endif