#include "stdafx.h"

#include "Human.h"
int Human::licznik_obiektow = 0;
Human::Human(int age,::sex sex=::sex::male,std::string name="unknown",std::string firstname="unknown")
	:favorite_books(NULL)
{
	licznik_obiektow++;
	//wskaŸnik na tablicê	
	favorite_books = new string[1];
	count = 1;
	//wskaŸnik na tablicê
	this->age = age;
	this->sex = sex;
	this->name = name;
	this->firstname = firstname;
}
Human::Human()
	:favorite_books(NULL)
{
	licznik_obiektow++;
	favorite_books = new string[1];
	count = 1;
	this->age = age;
	this->sex = sex;
	this->name = name;
	this->firstname = firstname;
}
void Human::set_age(int age)
{
	this->age = age;
}
int Human::get_age()
{
	return this->age;
}

void Human::set_sex(::sex sex)
{
	this->sex = sex;
}

::sex Human::get_sex()
{
	return this->sex; 
}

void Human::set_name(std::string name)
{
	this->name = name;
}
std::string Human::get_name()
{
	return this->name;
}
void Human::set_firstname(std::string firstname)
{
	this->firstname = firstname;
}

std::string Human::get_firstname()
{
	return this->firstname;
}

string* Human::get_favorite_books()
{
	return this->favorite_books;
}
void Human::set_favorite_books(string* favorite_books, int count) 
{
	if(favorite_books!=NULL)
	{
		delete [] this->favorite_books;
		this->favorite_books = NULL;
	}
	
	this->favorite_books = new string[count];
	
	for(int i=0; i<count; i++)
	{
		this->favorite_books[i] = favorite_books[i];
	}
	this->count = count;
}

Human::~Human()
{
	if(favorite_books!=NULL)
	{
		delete [] favorite_books;
	}
	favorite_books = NULL;
	count = 0;
}


Human& Human::operator=(Human& a)
{
	this->set_age(a.get_age());
	this->set_favorite_books(a.get_favorite_books(), a.get_count());
	this->set_firstname(a.get_firstname());
	this->set_name(a.get_name());
	
	this->set_sex(a.get_sex());	

	return *this;
}

ostream & operator<< (ostream &wyjscie, const ::sex &sex)         
{
	if(sex==::sex::male)
		return wyjscie  << "male";
	else
		return wyjscie << "female";
}

ostream & operator<< (ostream &wyjscie, Human &human)         
{	
	wyjscie << "\nname: " << human.get_name() 
		<< "\nfirstname: " << human.get_firstname()
		<< "\nsex: " << human.get_sex()
		<< "\nage: " << human.get_age();
	return wyjscie;
}

std::string Human::birthday()
{
	std::stringstream Stream;
		
	int age = int(2014 - this->get_age());
	Stream << "1/01/" << age;

	return Stream.str();
}