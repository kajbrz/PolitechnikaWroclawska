// Circle.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#include "Circle.h"

int main()
{
	struct location location;
	location.x = 2.f;
    location.y = 4.f;
    Circle circle(4, location);
	
	Circle circle2 = Circle(1,1,1) + Circle(2,2,2);
	Circle circle3 = Circle(1,1,1) * Circle(2,2,2);

	cout.setf(ios::fixed);
	cout.precision(2);

    cout << "\nCircle location is: " << circle.get_location();
	cout << "\nCircle radius is: " << circle.get_radius();
    cout << "\nCircle location is: " << circle.get_circumference();
    cout << "\nCircle area is: " << circle.get_area();
	
    cout << "\n\n circle2 location is: " << circle2.get_location();
	cout << "\n circle2 radius is: " << circle2.get_radius();
    cout << "\n circle2 location is: " << circle2.get_circumference();
    cout << "\n circle2 area is: " << circle2.get_area();

    cout << "\n\ncircle3 location is: " << circle3.get_location();
	cout << "\n circle3 radius is: " << circle3.get_radius();
    cout << "\n circle3 location is: " << circle3.get_circumference();
    cout << "\n circle3 area is: " << circle3.get_area();



	system("PAUSE");
	return 0;
}

