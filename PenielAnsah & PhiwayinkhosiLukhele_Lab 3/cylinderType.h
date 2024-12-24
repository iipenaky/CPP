#ifndef CYLINDERTYPE_H  
#define CYLINDERTYPE_H  
#include <iostream>
#include <string>
#include "circleType.h"
using namespace std;

class cylinderType : public circleType{
    public:
        cylinderType(double r, double h);
        void setradius (double r);
        void setHeight (double h);
        double calcVolume ();
        double calcArea ();
        void printVolume();
        void printArea();
    private:
        double height;
        double radius;
};
void cylinderType ::setradius(double r) {
    circleType :: setRadius(r);
}

double cylinderType ::calcArea()
{
    double area = circleType :: area();
    double circumference = circleType :: circumference();
    return (2 * area) + (circumference* height);
}

double cylinderType ::calcVolume(){
    double area = circleType :: area();
    return area * height;
}

cylinderType :: cylinderType(double r, double h) : circleType(r) {
    setradius(r);
    setHeight(h);
}

void cylinderType::printVolume(){
    cout << "The volume of the cylinder is " << calcVolume() << endl;
} 

void cylinderType :: setHeight (double h){
    if (h >= 0)
        height = h;
    else
        height = 0;
}

void cylinderType::printArea(){
    cout << "The area of the cylinder is " << calcArea() << endl;
} 
#endif