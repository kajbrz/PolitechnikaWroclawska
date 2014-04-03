
#include "stdafx.h"
#include "Circle.h"


#include <string>
#include <sstream>

#define M_PI 3.14159265359


void Circle::set_location(double x, double y)
{

    this->Location.circle_location_x = x;
    this->Location.circle_location_y = y;
}
std::string Circle::get_location()
{
	std::stringstream zwrot;
	zwrot << Location.circle_location_x <<  "x"  <<  Location.circle_location_y;
    return zwrot.str();
}
void Circle::set_radius(float r)
{
    this->radius = r;
}
double Circle::get_radius()
{
    return radius;
}
Circle::Circle(float x, float y, float r)
{
    set_radius(r);
    set_location(x, y);
}
double Circle::get_circumference()
{
    return M_PI * 2 * radius;
}
double Circle::get_area()
{
    return M_PI * radius * radius;
}