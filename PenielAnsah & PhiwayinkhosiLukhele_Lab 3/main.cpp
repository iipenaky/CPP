#include <iostream>
#include "cylinderType.h"  

using namespace std;

int main() {
    double radius, height, shippingCostPerLiter, paintCostPerSqFoot;

    // Prompt user for input
    cout << "Enter the radius of the base of the container in feet: ";
    cin >> radius;
    cout << "Enter the height of the container in feet: ";
    cin >> height;
    cout << "Enter the shipping cost per liter: ";
    cin >> shippingCostPerLiter;
    cout << "Enter the paint cost per square foot: ";
    cin >> paintCostPerSqFoot;

    cylinderType container = cylinderType(radius, height);

    double volumeInCubicFeet = container.calcVolume();
    double volumeInLiters = volumeInCubicFeet * 28.32;

    double surfaceArea = container.calcArea();

    double shippingCost = volumeInLiters * shippingCostPerLiter;

    double paintCost = surfaceArea * paintCostPerSqFoot;

    cout << "Shipping Cost: $" << shippingCost << endl;
    cout << "Paint Cost: $" << paintCost << endl;

    return 0;
}
