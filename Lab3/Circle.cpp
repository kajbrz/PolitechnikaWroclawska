#include "stdafx.h"
#include <sstream>


struct location
{
	double circle_location_x;
	double circle_location_y;
};

class CCircle
{
private:
	double radius;
	location Location;
public :
	void set_location(double x, double y);
    std::string get_location();
    void set_radius(float r);
    double get_radius();
    CCircle(float x, float y, float r);
    double get_circumference();
    double get_area();
};
