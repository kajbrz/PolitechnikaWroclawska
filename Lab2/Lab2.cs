using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2
{

    class staticValue
    {
        public const double M_PI = 3.14159265359; 
    }

    public struct location
    {
        public double circle_location_x;
        public double circle_location_y;
    }

    class Circle
    {
       
        private double radius;
        private location Location;
        public void set_location(double x, double y)
        {
            
            Location.circle_location_x = x;
            Location.circle_location_y = y;
        }
        public string get_location()
        {
            return Location.circle_location_x + "x" + Location.circle_location_y;
        }
        public void set_radius(float r)
        {
            radius = r;
        }
        public double get_radius()
        {
            return radius;
        }
        public Circle(float x, float y, float r)
        {
            set_radius(r);
            set_location(x, y);
        }
        public double get_circumference()
        {
            return staticValue.M_PI * 2 * radius;
        }
        public double get_area()
        {
            return staticValue.M_PI * radius * radius;
        }
    }


    class Run
    {
        public static void Main()
        {
            Circle circle = new Circle(4,2,15);
            
            Console.WriteLine("Circle location is: "+ circle.get_location());            
            Console.WriteLine("Circle radius is: "+ circle.get_radius());
            Console.WriteLine("Circle location is: "+ String.Format("{0:0.00}",circle.get_circumference()));
            Console.WriteLine("Circle area is: "+ String.Format("{0:0.00}",circle.get_area()));    
        }
   }
}