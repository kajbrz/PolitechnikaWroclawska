#include "stdafx.h"
#include "Student2.h"



Student2::Student2(void)
{
	srednia = new double[1];
	countofsrednia = 1;
	degree = degree::lic;

}


Student2::~Student2(void)
{
	delete [] srednia;
	srednia = NULL;
}

istream& operator>> (istream& wej, Student2& student2)
{
	std::string name;	
	cout << "First name: ";
	cin >> name;
	student2.set_firstname(name);

	wej >> name;
	cout << "Last name: ";
	cin >> name;
	student2.set_name(name);
	wej >> name;

	int age;
	cout << "age: ";
	cin >> age;
	student2.set_age(age);
	wej >> age;

	int numberofregister;
	cout << "numberofregister: ";
	cin >> numberofregister;
	student2.set_numberofregister(numberofregister);
	wej >> numberofregister;

	int semester;	
	cout << "semester: ";
	cin >> semester;
	student2.set_semester(semester);
	wej >>semester;

	std::string branch;	
	cout << "branch: ";
	cin >> branch;
	student2.set_branch(branch);
	wej >>branch;

	std::string faculty;
	cout << "faculty: ";
	cin >> faculty;
	student2.set_faculty(faculty);
	wej >> faculty;

	std::string degree;
	cout << "degree: ";
	cin >> degree;
	if(degree.compare("inz")==0)
	{
		student2.set_degree(degree::inz);
		wej >> std::string("inz");
	}
	else
	{
		student2.set_degree(degree::lic);
		wej >> std::string("lic");
	}
	return wej;
}

void Student2::set_degree(::degree degree)
{
	this->degree = degree;
}

ostream & operator<< (ostream &wyjscie, const degree degree)         
{
	if(degree==degree::inz)
		return wyjscie  << "inz";
	else
		return wyjscie << "lic";
}

ostream & operator<< (ostream &wyjscie, Student2 &student)         
{	
	wyjscie << "\nname: " << student.get_name() 
		<< "\nfirstname: " << student.get_firstname()
		<< "\nsex: " << student.get_sex()
		<< "\nage: " << student.get_age()
		<< "\nbranch: " << student.get_branch()
		<< "\nfaculty: " << student.get_faculty()
		<< "\ndegree: " << student.get_degree()
		<< "\nNumber of Register: " << student.get_numberofregister();
	return wyjscie;
}


Student2& Student2::operator=(Student2& a)
{	
	this->set_age(a.get_age());
	this->set_favorite_books(a.get_favorite_books(), a.get_count());
	this->set_favorite_books2(a.get_favorite_books2(), a.get_count2());
	this->set_degree(a.get_degree());
	this->set_firstname(a.get_firstname());
	this->set_name(a.get_name());
	this->set_sex(a.get_sex());	

	this->set_numberofregister(a.get_numberofregister());
	this->set_semester(a.get_semester());
	this->set_branch(a.get_branch());
	this->set_faculty(a.get_faculty());
	
	return *this;
}

	
void Student2::set_srednia(double* srednia, int count2)
{
	if(this->srednia!=NULL)
	{
		delete [] this->srednia;
		this->srednia = NULL;
	}
	
	this->srednia = new double[count2];
	
	for(int i=0; i<count2; i++)
	{
		this->srednia[i] = srednia[i];
	}
	this->countofsrednia = count2;
}
