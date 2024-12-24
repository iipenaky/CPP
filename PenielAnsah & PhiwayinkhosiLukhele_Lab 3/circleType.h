#ifndef CIRCLETYPE_H   
#define CIRCLETYPE_H   
#include <iostream>
#include <string>
using namespace std;

class circleType {

    public:
        void setRadius (double r);
        //Function to set the radius.
        //Postcondition: if (r>0) radius = r;

        double getRadius ();
        //Function to return the radius.
        //Postcondition: The value of radius is returned.

        double area ();
        //Function to return the area of a circle.
        //Postcondition: Area is calculated and returned.

        double circumference ();
        //Function to return the circumference of a circle.
        //Postcondition: Circumference is calculated and returned.

        void print();

        circleType (double r = 0);
        //Constructor with a default parameter.
        //Radius is set according to the parameter.
        //The default value of the radius is 0.0;
        //Postcondition: radius = r;

    private :
        double radius;
};

void circleType ::setRadius(double r)
{
    if (r >= 0)
        radius = r;
    else
        radius = 0;
}

double circleType ::getRadius(){
    return radius ;
}

double circleType ::area()
{
    return 3.1416 * radius * radius;
}

double circleType ::circumference(){

    return 2 * 3.1416 * radius;
}

circleType ::circleType(double r){
    setRadius(r);
}

void circleType::print(){
    cout << "The radius of the circle is " << getRadius() << endl;
    cout << "The area of the circle is " << area() << endl;
    cout << "The circumference of the circle is " << circumference() << endl;
} 

#endif 
