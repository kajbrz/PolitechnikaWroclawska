#pragma once
/*
#define _USE_MATH_DEFINES_
#include <cmath> 
..\politechnikawroclawska\lab3\circle.cpp(38): error C2065: 'M_PI' : undeclared identifier
*/

#define M_PI 3.14159265359
#include <iostream>

struct location
{
	float x;
	float y;
	friend std::ostream & operator<< (std::ostream &wyjscie, const location &s) ;
};
class Circle
{
private:
	float radius;
	::location location;
public :
	Circle(float radius, ::location  location);
	Circle(float radius,float x, float y);
	void set_location(float x, float y);
	void set_location(::location location);
    ::location get_location();
    void set_radius(float r);
    float get_radius();
    float get_circumference();
    float get_area();

	
	Circle operator*(const Circle &circle);
	Circle operator+(const Circle &circle);
};
