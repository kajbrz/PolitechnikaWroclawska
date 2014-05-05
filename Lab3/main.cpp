// Circle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Circle.h"

int main()
{     
    Circle circle(4, 2, 15);

	cout.setf(ios::fixed);
	cout.precision(2);
    cout << "\nCircle location is: " << circle.get_location();
	cout << "\nCircle radius is: " << circle.get_radius();
    cout << "\nCircle location is: " << circle.get_circumference();
    cout << "\nCircle area is: " << circle.get_area();  
	return 0;
}

