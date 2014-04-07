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

	string* Favorite_Books; //favorite books

	int count;
public:
	static int Licznik_obiektow;
	Human();
	Human(int,sex,std::string,std::string);
	virtual ~Human();

	int get_Age();
	void set_Age(int age);

	
	string* get_Favorite_Books();
	void set_Favorite_Books(string*, int);

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