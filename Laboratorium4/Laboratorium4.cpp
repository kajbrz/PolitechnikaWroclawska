// Laboratorium4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

#include <iostream>
using namespace std;

enum sex
{
	female,
	male
};

class Human
{
private:
	int Age;
	::sex Sex;
	std::string Name;
	std::string FirstName;

	int* ArrayVar;
	int count;
public:
	static int Licznik_obiektow;
	Human(int,::sex,std::string,std::string);
	Human();
	~Human();

	int get_Age();
	void set_Age(int age);

	
	int* get_ArrayVar();
	void set_ArrayVar(int* ArrayVar, int count);

	int get_Count(){return count;};

	::sex get_Sex();
	void set_Sex(::sex sex);

	std::string get_Name();
	void set_Name(std::string);

	std::string get_FirstName();
	void set_FirstName(std::string);

	Human& operator=(Human&);
};

class Student : public Human
{
private:
	int NumberOfRegister;
	int Semester;
	std::string Branch;
	std::string Faculty;
public:
    Student(int, int,int,::sex,std::string,std::string,std::string,std::string);
	Student();
	~Student();
	int get_NumberOfRegister();
	void set_NumberOfRegister(int NumberOfRegister);

	int get_Semester();
	void set_Semester(int);
	
	std::string get_Branch();
	void set_Branch(std::string Branch);

	std::string get_Faculty();
	void set_Faculty(std::string Branch);
	
	Student& operator=(Student&);
};

class Tutor : public Student
{
private:
	std::string ScienceTitle;
	int CountOfPublications;
public:
	Tutor(std::string,int,int,int,int,::sex,std::string,std::string,std::string,std::string);	
	Tutor::Tutor();
	~Tutor();
	std::string get_ScienceTitle();
	void set_ScienceTitle(std::string);

	int get_CountOfPublications();
	void set_CountOfPublications(int);
	
	Tutor& Tutor::operator=(Tutor& a);
};
/////////////////
///////COUT//////

ostream & operator<< (ostream &wyjscie, const sex Sex)         
{
	if(Sex==sex::male)
		return wyjscie  << "male";
	else
		return wyjscie << "female";
}

ostream & operator<< (ostream &wyjscie, Human human)         
{	
	wyjscie << "\nName: " << human.get_Name() 
		<< "\nFirstName: " << human.get_FirstName()
		<< "\nSex: " << human.get_Sex()
		<< "\nAge: " << human.get_Age();
	return wyjscie;
}

ostream & operator<< (ostream &wyjscie, Student student)         
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
ostream & operator<< (ostream &wyjscie, Tutor tutor)         
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






/////////////////
int Human::Licznik_obiektow = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	/*KOMENTARZE 
	//Hermetyzacja przy dziedziczeniu	
	dziedzi¹c klasê bazow¹ jako prywatn¹ lub chronion¹ tracimy w pochodnych dostêp do metod
	dlatego musimy pamiêtaæ o typie dziedziczenia "public" przed klas¹:
		class Student : public Human{};

	
	//Zmienne Statyczne i dziedziczenie;
	licznik_obiektow - licznik wywo³añ
	konstruktor z klasy Human jest wywo³ywany za ka¿dym razem tylko 1 raz


	//kopiowanie 
	Mo¿na skopiowaæ klasê pochodn¹ do klasy zdziedziczonej czyli student = tutor, lecz nie da siê skopiowaæ tutor= student 
	poniewa¿ tutor posiada o wiele wiêcej zmiennych
	*/
	Human human1(21,sex::male,"Kajetan","Brzuszczak");
	cout << "Human: " << human1;
	cout << "\nWywolan: " << human1.Licznik_obiektow;
	
	Student student1(209869,2,21,sex::male,"Kajetan","Brzuszczak", "Electronic", "IT");	
	cout << "\n\nStudent: " << student1 ;
	cout << "\nWywolan: " << student1.Licznik_obiektow;

	Student student2;
	student2.get_ArrayVar()[0] = 100;
	cout<<student2.get_ArrayVar()[0];
	cout<<"KiERAMBA\n";
	Tutor tutor("Doktor Nauk", 8, 888756, 10, 32,sex::female,"Boguslawa", "Len", "IT&Managment", "Mechatronics");
	tutor.get_ArrayVar()[0] = 153;
	cout<<"\n"<<tutor.get_ArrayVar()[0]<<"...........";
	cout<<"KiERAMBA\n";
	{
		Student student3;

	}
	cout<<"\n"<<tutor.get_ArrayVar()[0]<<"...........";
	cout << "\n\nStudent2 :" << student2;
	cout << "\n\nTutor: " << tutor;
	
	student2.get_ArrayVar()[0] = 100;
	cout<<"\n"<<student2.get_ArrayVar()[0]<<"\n\n";
	
	student2 = tutor;
	cout << "\n\nStudent2 after attribute" << student2;

	

	return 0;
}











///////////////////////////
//////KONSTRUKTURY///////////
Human::Human(int Age=0,sex Sex=sex::male,std::string Name="unknown",std::string FirstName="unknown")
	:ArrayVar(NULL)
{
	cout<<"konstr human";
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


Student::Student(int NumberOfRegister, int Semester=0,int Age=0,sex Sex=sex::male,std::string Name="unknown",
				 std::string FirstName="unknown",std::string Branch="unknown", std::string Faculty="unknown")
	: Human(Age,Sex,Name,FirstName)
{
	cout<<"konstr student";
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

Tutor::Tutor(std::string ScienceTitle = "unknown",int CountOfPublications =0, int NumberOfRegister =0, int Semester=0,int Age=0,
			 sex Sex=sex::male,std::string Name="unknown",std::string FirstName="unknown",std::string Branch="unknown", std::string Faculty="unknown")
			 : Student(NumberOfRegister,Semester,Age,Sex,Name,FirstName,Faculty,Branch)//OKOÑ
{
	cout<<"Siemka konstr tutor";
	set_ScienceTitle(ScienceTitle);
	set_CountOfPublications(CountOfPublications);
}
Tutor::Tutor()
	:Student(0,0,0,sex::female,"unknown","unknown","unknown","unknown")
{
	set_ScienceTitle("unknown");
	set_CountOfPublications(0);
}

///////////////////////////


////////SETTERS And GETTERS from class Human/////////
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
	return this->Sex; // ruchanko
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
////////SETTERS And GETTERS from class Human/////////


////////SETTERS And GETTERS from class Student/////////
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

////////SETTERS And GETTERS from class Student/////////


////////SETTERS And GETTERS from class Tutor/////////
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
////////SETTERS And GETTERS from class Tutor/////////


int* Human::get_ArrayVar()
{
	return this->ArrayVar;
}
void Human::set_ArrayVar(int* _ArrayVar, int count) 
{
	if(ArrayVar!=NULL)
	{
	
		cout<<"aa: "<<Human::get_ArrayVar()[0]<<"\n";
		delete [] Human::get_ArrayVar();
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
	delete [] ArrayVar;
	ArrayVar = 0;
	cout<<"AAA";
	count = 0;
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

Student::~Student()
{
	cout<<"KKK";
}

Tutor::~Tutor()
{
	;
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
Tutor& Tutor::operator=(Tutor& a)
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
	
	this->set_CountOfPublications(a.get_CountOfPublications());
	this->set_ScienceTitle(a.get_ScienceTitle());
	return *this;
}