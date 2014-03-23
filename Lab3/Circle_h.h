#ifndef Circle_h
#define Circle_h
#include <string>

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
	void set_location(double x, double y);
    string get_location();
    void set_radius(float r);
    double get_radius();
    Circle(float x, float y, float r);
    double get_circumference();
    double get_area();
};


#endif