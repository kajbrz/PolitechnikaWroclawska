#include "stdafx.h"
#ifndef CIRCLE_H
#define CIRCLE_H

#include <sstream>
struct location
{
	double circle_location_x;
	double circle_location_y;
};
class Circle
{
private:
	double radius;
	location Location;
public :
    Circle(float x, float y, float r);
	void set_location(double x, double y);
    std::string get_location();
    void set_radius(float r);
    double get_radius();
    double get_circumference();
    double get_area();
};
#endif