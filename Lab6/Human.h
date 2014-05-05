#pragma once
#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include "Mamal.h"
#include <sstream>

using namespace std;

enum sex
{
	female,
	male
}; 
#include <string>
class Human 
	:public Mamal
{
private:
	int age;
	enum sex sex;
	std::string name;
	std::string firstname;

	string* favorite_books; //favorite books

	int count;
public:
	static int licznik_obiektow;
	Human();
	Human(int,enum sex,std::string,std::string);
	virtual ~Human();

	int get_age();
	void set_age(int age);

	
	string* get_favorite_books();
	void set_favorite_books(string*, int);

	int get_count(){return count;};

	enum sex get_sex();
	void set_sex(enum sex);

	std::string get_name();
	void set_name(std::string);

	std::string get_firstname();
	void set_firstname(std::string);

	Human& operator=(Human&);

	virtual std::string birthday();
};

ostream & operator<< (ostream &wyjscie, const sex &sex); 
ostream & operator<< (ostream &wyjscie, Human &human) ;
#endif