


#include "Circle.cpp"

#include <string>
#include <sstream>

#define M_PI 3.14159265359


void CCircle::set_location(double x, double y)
{

    Location.circle_location_x = x;
    Location.circle_location_y = y;
}
std::string CCircle::get_location()
{
	std::stringstream zwrot;
	zwrot << Location.circle_location_x <<  "x"  <<  Location.circle_location_y;
    return zwrot.str();
}
void CCircle::set_radius(float r)
{
    radius = r;
}
double CCircle::get_radius()
{
    return radius;
}
CCircle::CCircle(float x, float y, float r)
{
    set_radius(r);
    set_location(x, y);
}
double CCircle::get_circumference()
{
    return M_PI * 2 * radius;
}
double CCircle::get_area()
{
    return M_PI * radius * radius;
}