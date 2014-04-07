#include "stdafx.h"
#include "Student.h"
Student::Student(int NumberOfRegister, int Semester=0,int Age=0,sex Sex=sex::male,std::string Name="unknown",
				 std::string FirstName="unknown",std::string Branch="unknown", std::string Faculty="unknown")
	: Human(Age,Sex,Name,FirstName)
{
	set_NumberOfRegister(NumberOfRegister);
	set_Semester(Semester);
	set_Branch(Branch);
	set_Faculty(Faculty);
}

Student::Student()
	: Human(0,sex::male,"unknown","unknown")	
{
	set_NumberOfRegister(0);
	set_Semester(0);
	set_Branch("unknown");
	set_Faculty("unknown");
}

Student::~Student()
{
}

void Student::set_NumberOfRegister(int NumberOfRegister)
{
	this->NumberOfRegister = NumberOfRegister;
}

void Student::set_Semester(int Semester)
{
	this->Semester = Semester;
}

int Student::get_NumberOfRegister()
{
	return this->NumberOfRegister;
}

int Student::get_Semester()
{
	return this->Semester;
}

std::string Student::get_Branch()
{
	return this->Branch;
}
void Student::set_Branch(std::string Branch)
{
	this->Branch = Branch;
}

std::string Student::get_Faculty()
{
	return this->Faculty;
}
void Student::set_Faculty(std::string Faculty)
{
	this->Faculty = Faculty;
}

Student& Student::operator=(Student& a)
{	
	this->set_Age(a.get_Age());
	this->set_ArrayVar(a.get_ArrayVar(), a.get_Count());
	this->set_FirstName(a.get_FirstName());
	this->set_Name(a.get_Name());
	this->set_Sex(a.get_Sex());	

	this->set_NumberOfRegister(a.get_NumberOfRegister());
	this->set_Semester(a.get_Semester());
	this->set_Branch(a.get_Branch());
	this->set_Faculty(a.get_Faculty());
	
	return *this;
}

ostream & operator<< (ostream &wyjscie, Student &student)         
{
	
	wyjscie << "\nName: " << student.get_Name() 
		<< "\nFirstName: " << student.get_FirstName()
		<< "\nSex: " << student.get_Sex()
		<< "\nAge: " << student.get_Age()
		<< "\nBranch: " << student.get_Branch()
		<< "\nFaculty: " << student.get_Faculty()
		<< "\nNumber of Register: " << student.get_NumberOfRegister();
	return wyjscie;
}