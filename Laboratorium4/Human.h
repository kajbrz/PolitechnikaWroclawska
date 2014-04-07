#pragma once
#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
using namespace std;

enum sex
{
	female,
	male
}; 
#include <string>
class Human
{
private:
	int Age;
	sex Sex;
	std::string Name;
	std::string FirstName;

	int* ArrayVar;
	int count;
public:
	static int Licznik_obiektow;
	Human();
	Human(int,sex,std::string,std::string);
	~Human();

	int get_Age();
	void set_Age(int age);

	
	int* get_ArrayVar();
	void set_ArrayVar(int*, int);

	int get_Count(){return count;};

	sex get_Sex();
	void set_Sex(sex);

	std::string get_Name();
	void set_Name(std::string);

	std::string get_FirstName();
	void set_FirstName(std::string);

	Human& operator=(Human&);
};

ostream & operator<< (ostream &wyjscie, const sex &Sex); 
ostream & operator<< (ostream &wyjscie, Human &human) ;
#endif