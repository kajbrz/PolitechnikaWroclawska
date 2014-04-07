#include "stdafx.h"

#include "Human.h"

Human::Human(int Age,sex Sex=sex::male,std::string Name="unknown",std::string FirstName="unknown")
	:Favorite_Books(NULL)
{
	Licznik_obiektow++;
	//wskaŸnik na tablicê
	Favorite_Books = new string[1];
	count = 1;
	//wskaŸnik na tablicê
	set_Age(Age);
	set_Sex(Sex);
	set_Name(Name);
	set_FirstName(FirstName);
}
Human::Human()
	:Favorite_Books(NULL)
{
	Licznik_obiektow++;
	Favorite_Books = new string[1];
	count = 1;
	set_Age(0);
	set_Sex(sex::female);
	set_Name("unknown");
	set_FirstName("unknown");
}
void Human::set_Age(int age)
{
	this->Age = age;
}
int Human::get_Age()
{
	return this->Age;
}

void Human::set_Sex(sex Sex)
{
	this->Sex = Sex;
}

sex Human::get_Sex()
{
	return this->Sex; 
}

void Human::set_Name(std::string Name)
{
	this->Name = Name;
}
std::string Human::get_Name()
{
	return this->Name;
}
void Human::set_FirstName(std::string FirstName)
{
	this->FirstName = FirstName;
}

std::string Human::get_FirstName()
{
	return this->FirstName;
}

string* Human::get_Favorite_Books()
{
	return this->Favorite_Books;
}
void Human::set_Favorite_Books(string* Favorite_Books, int count) 
{
	if(Favorite_Books!=NULL)
	{
		delete [] this->Favorite_Books;
		this->Favorite_Books = NULL;
	}
	
	this->Favorite_Books = new string[count];
	
	for(int i=0; i<count; i++)
	{
		this->Favorite_Books[i] = Favorite_Books[i];
	}
	this->count = count;
}

Human::~Human()
{
	if(Favorite_Books!=NULL)
	{
		delete [] Favorite_Books;
	}
	Favorite_Books = NULL;
	count = 0;
}


Human& Human::operator=(Human& a)
{
	this->set_Age(a.get_Age());
	this->set_Favorite_Books(a.get_Favorite_Books(), a.get_Count());
	this->set_FirstName(a.get_FirstName());
	this->set_Name(a.get_Name());
	
	this->set_Sex(a.get_Sex());	

	return *this;
}

ostream & operator<< (ostream &wyjscie, const sex &Sex)         
{
	if(Sex==sex::male)
		return wyjscie  << "male";
	else
		return wyjscie << "female";
}

ostream & operator<< (ostream &wyjscie, Human &human)         
{	
	wyjscie << "\nName: " << human.get_Name() 
		<< "\nFirstName: " << human.get_FirstName()
		<< "\nSex: " << human.get_Sex()
		<< "\nAge: " << human.get_Age();
	return wyjscie;
}
