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
	int numberofregister;
	int semester;
	std::string branch;
	std::string faculty;
	string* favorite_books2;
	int count2;
public:
	Student();
    Student(int, int,int,enum sex,std::string,std::string,std::string,std::string);
	~Student();
	int get_numberofregister();
	void set_numberofregister(int);

	int get_semester();
	void set_semester(int);
	
	std::string get_branch();

	void set_branch(std::string);

	std::string get_faculty();
	void set_faculty(std::string);
	
	Student& operator=(Student&);

	int get_count2(){return count2;}
	
	string* get_favorite_books2(){return favorite_books2;}
	void set_favorite_books2(string*, int);
	virtual string birthday();

	
	//int operator<(InterfaceMamal*);
};

ostream & operator<< (ostream &wyjscie, Student &student);



#endif