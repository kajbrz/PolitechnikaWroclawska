#pragma once
#include <iostream>
struct location
{
	double circle_location_x;
	double circle_location_y;
	friend std::ostream & operator<< (std::ostream &wyjscie, const location &s) ;
};
class Circle
{
private:
	double radius;
	::location location;
public :
    Circle(float x, float y, float r);
	void set_location(double x, double y);	
	void set_location(::location location);
    ::location get_location();
    void set_radius(float r);
    double get_radius();
    double get_circumference();
    double get_area();	
};
