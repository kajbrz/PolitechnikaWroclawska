#include "stdafx.h"
#include "Tutor.h"
Tutor::Tutor(std::string ScienceTitle,int CountOfPublications =0, int NumberOfRegister =0, int Semester=0,int Age=0,
			 sex Sex=sex::male,std::string Name="unknown",std::string FirstName="unknown",std::string Branch="unknown", std::string Faculty="unknown")
			 : Student(NumberOfRegister,Semester,Age,Sex,Name,FirstName,Faculty,Branch)//OKOÑ
{
	set_ScienceTitle(ScienceTitle);
	set_CountOfPublications(CountOfPublications);
}
Tutor::Tutor()
	:Student(0,0,0,sex::female,"unknown","unknown","unknown","unknown")
{
	set_ScienceTitle("unknown");
	set_CountOfPublications(0);
}
Tutor::~Tutor()
{
	;
}


std::string Tutor::get_ScienceTitle()
{
	return this->ScienceTitle;
}
void Tutor::set_ScienceTitle(std::string ScienceTitle)
{
	this->ScienceTitle = ScienceTitle;
}

int Tutor::get_CountOfPublications()
{
	return this->CountOfPublications;
}
void Tutor::set_CountOfPublications(int CountOfPublications)
{
	this->CountOfPublications = CountOfPublications;
}

Tutor& Tutor::operator=(Tutor& a)
{
	this->set_Age(a.get_Age());
	this->set_Favorite_Books(a.get_Favorite_Books(), a.get_Count());	
	this->set_Favorite_Books2(a.get_Favorite_Books2(), a.get_count2());
	this->set_FirstName(a.get_FirstName());
	this->set_Name(a.get_Name());
	this->set_Sex(a.get_Sex());	

	this->set_NumberOfRegister(a.get_NumberOfRegister());
	this->set_Semester(a.get_Semester());
	this->set_Branch(a.get_Branch());
	this->set_Faculty(a.get_Faculty());
	
	this->set_CountOfPublications(a.get_CountOfPublications());
	this->set_ScienceTitle(a.get_ScienceTitle());
	return *this;
}

ostream & operator<< (ostream &wyjscie, Tutor &tutor)         
{	
	wyjscie << "\nName: " << tutor.get_Name() 
		<< "\nFirstName: " << tutor.get_FirstName()
		<< "\nSex: " << tutor.get_Sex()
		<< "\nAge: " << tutor.get_Age()
		<< "\nBranch: " << tutor.get_Branch()
		<< "\nFaculty: " << tutor.get_Faculty()
		<< "\nNumber of Register: " << tutor.get_NumberOfRegister()
		<< "\nTitle : " << tutor.get_ScienceTitle()
		<< "\nCount of Publications: " << tutor.get_CountOfPublications();
	return wyjscie;
}
