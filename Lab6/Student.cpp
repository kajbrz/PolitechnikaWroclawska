#include "Student.h"
Student::Student(int numberofregister, int semester=0,int age=0,::sex sex=male,std::string name="unknown",
				 std::string firstname="unknown",std::string branch="unknown", std::string faculty="unknown")
	: Human(age,sex,name,firstname)
{
	favorite_books2 = new string[1];
	count2 = 1;
	this->numberofregister = numberofregister;
	this->semester = semester;
	this->branch = branch;
	this->faculty = faculty;
}

Student::Student()
	: Human(0,male,"unknown","unknown")
{

	this->favorite_books2 = new string[1];
	this->count2 = 1;
	this->numberofregister = 0;
	this->semester = 0;
	this->branch = "unknown";
	this->faculty = "unknown";
}
Student::~Student()
{
	delete [] favorite_books2;
}

void Student::set_numberofregister(int numberofregister)
{
	this->numberofregister = numberofregister;
}

void Student::set_semester(int semester)
{
	this->semester = semester;
}

int Student::get_numberofregister()
{
	return this->numberofregister;
}

int Student::get_semester()
{
	return this->semester;
}

std::string Student::get_branch()
{
	return this->branch;
}
void Student::set_branch(std::string branch)
{
	this->branch = branch;
}

std::string Student::get_faculty()
{
	return this->faculty;
}
void Student::set_faculty(std::string faculty)
{
	this->faculty = faculty;
}

void Student::set_favorite_books2(string* _favorite_books2, int count2)
{
	if(favorite_books2!=NULL)
	{
		delete [] this->favorite_books2;
		this->favorite_books2 = NULL;
	}

	favorite_books2 = new string[count2];

	for(int i=0; i<count2; i++)
	{
		this->favorite_books2[i] = _favorite_books2[i];
	}
	this->count2 = count2;
}

Student& Student::operator=(Student& a)
{

	set_age(a.get_age());
	// age = a.age //Acces is denied
	set_favorite_books(a.get_favorite_books(), a.get_count());
	set_favorite_books2(a.get_favorite_books2(), a.get_count2());
	set_firstname(a.get_firstname());
	set_name(a.get_name());
	set_sex(a.get_sex());

	set_numberofregister(a.get_numberofregister());
	set_semester(a.get_semester());
	set_branch(a.get_branch());
	set_faculty(a.get_faculty());

	return *this;
}


ostream & operator<< (ostream &wyjscie, Student &student)
{

	wyjscie << "\nname: " << student.get_name()
		<< "\nfirstname: " << student.get_firstname()
		<< "\nsex: " << student.get_sex()
		<< "\nage: " << student.get_age()
		<< "\nbranch: " << student.get_branch()
		<< "\nfaculty: " << student.get_faculty()
		<< "\nNumber of Register: " << student.get_numberofregister();
	return wyjscie;
}
std::string Student::birthday()
{
	std::stringstream stream;

	int age = int(2014 - this->get_age()) + 2;
	stream << "1/01/" << age;

	return stream.str();
}


//int Student::operator<(InterfaceMamal* interfaceMamal){	return ((interfaceMamal->age) < this->get_age());}
