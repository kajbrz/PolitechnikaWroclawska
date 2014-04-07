#include "stdafx.h"

#include "Human.h"

Human::Human(int Age,sex Sex=sex::male,std::string Name="unknown",std::string FirstName="unknown")
	:ArrayVar(NULL)
{
	Licznik_obiektow++;
	//wskaŸnik na tablicê
	ArrayVar = new int[1];
	count = 1;
	//wskaŸnik na tablicê
	set_Age(Age);
	set_Sex(Sex);
	set_Name(Name);
	set_FirstName(FirstName);
}
Human::Human()
	:ArrayVar(NULL)
{
	Licznik_obiektow++;
	ArrayVar = new int[1];
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

int* Human::get_ArrayVar()
{
	return this->ArrayVar;
}
void Human::set_ArrayVar(int* _ArrayVar, int count) 
{
	if(ArrayVar!=NULL)
	{
		delete [] this->ArrayVar;
		this->ArrayVar = NULL;
	}
	
	ArrayVar = new int[count];
	
	for(int i=0; i<count; i++)
	{
		this->ArrayVar[i] = _ArrayVar[i];
	}
	this->count = count;
}

Human::~Human()
{
	if(ArrayVar!=NULL)
	{
		delete [] ArrayVar;
	}
	ArrayVar = NULL;
	count = 0;
}


Human& Human::operator=(Human& a)
{
	this->set_Age(a.get_Age());
	this->set_ArrayVar(a.get_ArrayVar(), a.get_Count());
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
