#include "Tutor.h"
Tutor::Tutor(std::string sciencetitle,
			 int countofpublications =0,
			 int numberofregister =0,
			 int semester=0,int age=0,
			 ::sex sex=male,
			 std::string name="unknown",
			 std::string firstname="unknown",
			 std::string branch="unknown",
			 std::string faculty="unknown")
			 : Student(numberofregister,semester,age,sex,name,firstname,branch,branch)//OKOÑ
{
	this->sciencetitle = sciencetitle;
	this->countofpublications = countofpublications;
}
Tutor::Tutor()
	:Student(0,0,0,::sex::female,"unknown","unknown","unknown","unknown")
{
	this->sciencetitle = "unknown";
	this->countofpublications = 0;
}
Tutor::~Tutor()
{
	;
}


std::string Tutor::get_sciencetitle()
{
	return this->sciencetitle;
}
void Tutor::set_sciencetitle(std::string sciencetitle)
{
	this->sciencetitle = sciencetitle;
}

int Tutor::get_countofpublications()
{
	return this->countofpublications;
}
void Tutor::set_countofpublications(int countofpublications)
{
	this->countofpublications = countofpublications;
}

Tutor& Tutor::operator=(Tutor& a)
{
	this->set_age(a.get_age());
	this->set_favorite_books(a.get_favorite_books(), a.get_count());
	this->set_favorite_books2(a.get_favorite_books2(), a.get_count2());
	this->set_firstname(a.get_firstname());
	this->set_name(a.get_name());
	this->set_sex(a.get_sex());

	this->set_numberofregister(a.get_numberofregister());
	this->set_semester(a.get_semester());
	this->set_branch(a.get_branch());
	this->set_branch(a.get_branch());

	this->set_countofpublications(a.get_countofpublications());
	this->set_sciencetitle(a.get_sciencetitle());
	return *this;
}

ostream & operator<< (ostream &wyjscie, Tutor &tutor)
{
	wyjscie << "\nname: " << tutor.get_name()
		<< "\nfirstname: " << tutor.get_firstname()
		<< "\nsex: " << tutor.get_sex()
		<< "\nage: " << tutor.get_age()
		<< "\nbranch: " << tutor.get_branch()
		<< "\nbranch: " << tutor.get_branch()
		<< "\nNumber of Register: " << tutor.get_numberofregister()
		<< "\nTitle : " << tutor.get_sciencetitle()
		<< "\ncount of Publications: " << tutor.get_countofpublications();
	return wyjscie;
}
