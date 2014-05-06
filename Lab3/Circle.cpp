#include "Circle.h"


Circle::Circle(float radius, ::location  location)
{
    this->radius = radius;
    this->location = location;
}

void Circle::set_location(double x, double y)
{

    this->location.circle_location_x = x;
    this->location.circle_location_y = y;
}

void Circle::set_location(::location location)
{
    this->location = location;
}

location Circle::get_location()
{
	return location;
}

void Circle::set_radius(float r)
{
    this->radius = r;
}

double Circle::get_radius()
{
    return radius;
}

double Circle::get_circumference()
{
    return M_PI * 2 * radius;
}

double Circle::get_area()
{
    return M_PI * radius * radius;
}

std::ostream & operator<< (std::ostream &wyjscie, const location &s)
 {
	 return wyjscie << " ( " << s.circle_location_x <<
		 ";" << s.circle_location_y << ")";
 }
