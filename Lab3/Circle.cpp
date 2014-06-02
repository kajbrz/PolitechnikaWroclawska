#include "Circle.h"

Circle::Circle(float radius, ::location  location)
{
    this->radius = radius;
    this->location = location;
}
Circle::Circle(float radius, float x, float y)
{
    this->radius = radius;
    location.x = x;
	location.y = y;
}
void Circle::set_location(float x, float y)
{

	this->location.x = x;
    this->location.y = y;
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

float Circle::get_radius()
{
    return radius;
}

float Circle::get_circumference()
{
	return M_PI* 2* radius;
}

float Circle::get_area()
{
    return M_PI * radius * radius;
}

std::ostream & operator<< (std::ostream &wyjscie, const location &s)
 {
	 return wyjscie << " ( " << s.x << ";" << s.y << ")";
 }

Circle Circle::operator*(const Circle &circle)
{
	Circle circlenew(this->radius,this->location);
	
	circlenew.radius *= circle.radius;

	return circlenew;
}

Circle Circle::operator+(const Circle &circle)
{
	Circle circlenew(this->radius,this->location);
	
	circlenew.location.x = (circlenew.location.x + circle.location.x) /2;
	circlenew.location.y = (circlenew.location.y + circle.location.y) /2;

	circlenew.radius += circle.radius;
	return circlenew;
}