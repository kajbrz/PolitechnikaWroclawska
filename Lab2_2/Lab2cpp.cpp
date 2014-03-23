// Lab2cpp.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

#define M_PI 3.14159265359

struct location{    
    double circle_location_x;
    double circle_location_y;
};

class Circle{
private:
    location Location;
    double radius; 
public:    
    void set_location(double x, double y)
    {
        Location.circle_location_x=x;
        Location.circle_location_y=y;
    }
    void get_location(){
        cout << setprecision(2) << Location.circle_location_x << "x" << Location.circle_location_y;    
    }
    void set_radius(float r){
        radius=r;
    }
    double get_radius()
    {
        return radius;
    }
    double get_circumference()
    {
        return M_PI*2*radius;
    }
    double get_area()
    {
        return M_PI*radius*radius;
    }

};


int main()
{
    Circle circle;
    circle.set_radius(15);
    circle.set_location(4,2);
    	
	cout.setf(ios::fixed);
    cout << "\nCircle location is: "; circle.get_location();
    cout <<  "\nCircle radius is: " << circle.get_radius();
    cout << "\nCircle circumference is: " << circle.get_circumference();
    cout <<  "\nCircle area is: " << circle.get_area();    
    cout << "\nD";
}