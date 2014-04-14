#include "stdafx.h"
#include "Student2.h"



Student2::Student2(void)
{
	Srednia = new double[1];
	countOfSrednia = 1;
	Degree = degree::lic;

}


Student2::~Student2(void)
{
	delete [] Srednia;
	Srednia = NULL;
}

istream& operator>> (istream& wej, Student2& student2)
{
	std::string Name;	
	cout << "First Name: ";
	cin >> Name;
	student2.set_FirstName(Name);
	
	cout << "Last Name: ";
	cin >> Name;
	student2.set_Name(Name);
	
	int Age;
	cout << "Age: ";
	cin >> Age;
	student2.set_Age(Age);

	int NumberOfRegister;
	cout << "NumberOfRegister: ";
	cin >> NumberOfRegister;
	student2.set_NumberOfRegister(NumberOfRegister);

	int Semester;	
	cout << "Semester: ";
	cin >> Semester;
	student2.set_Semester(Semester);

	std::string Branch;	
	cout << "Branch: ";
	cin >> Branch;
	student2.set_Branch(Branch);

	std::string Faculty;
	cout << "Faculty: ";
	cin >> Faculty;
	student2.set_Faculty(Faculty);

	std::string Degree;
	cout << "Degree: ";
	cin >> Degree;
	if(Degree.compare("inz")==0)
	{
		student2.set_Degree(degree::inz);
	}
	else
		student2.set_Degree(degree::lic);

	return wej;
}

void Student2::set_Degree(degree Degree)
{
	this->Degree = Degree;
}

ostream & operator<< (ostream &wyjscie, const degree Degree)         
{
	if(Degree==degree::inz)
		return wyjscie  << "inz";
	else
		return wyjscie << "lic";
}

ostream & operator<< (ostream &wyjscie, Student2 &student)         
{	
	wyjscie << "\nName: " << student.get_Name() 
		<< "\nFirstName: " << student.get_FirstName()
		<< "\nSex: " << student.get_Sex()
		<< "\nAge: " << student.get_Age()
		<< "\nBranch: " << student.get_Branch()
		<< "\nFaculty: " << student.get_Faculty()
		<< "\nDegree: " << student.get_Degree()
		<< "\nNumber of Register: " << student.get_NumberOfRegister();
	return wyjscie;
}


Student2& Student2::operator=(Student2& a)
{	
	this->set_Age(a.get_Age());
	this->set_Favorite_Books(a.get_Favorite_Books(), a.get_Count());
	this->set_Favorite_Books2(a.get_Favorite_Books2(), a.get_count2());
	this->set_Degree(a.get_Degree());
	this->set_FirstName(a.get_FirstName());
	this->set_Name(a.get_Name());
	this->set_Sex(a.get_Sex());	

	this->set_NumberOfRegister(a.get_NumberOfRegister());
	this->set_Semester(a.get_Semester());
	this->set_Branch(a.get_Branch());
	this->set_Faculty(a.get_Faculty());
	
	return *this;
}

	
void Student2::set_Srednia(double* Srednia, int count2)
{
	if(this->Srednia!=NULL)
	{
		delete [] this->Srednia;
		this->Srednia = NULL;
	}
	
	this->Srednia = new double[count2];
	
	for(int i=0; i<count2; i++)
	{
		this->Srednia[i] = Srednia[i];
	}
	this->countOfSrednia = count2;
}
