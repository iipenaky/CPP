#include <iostream> 
#include <string>   
#include <math.h>   
#include <iomanip>  

using namespace std;

int main() {
    const double PI = 3.1416; // The constant for PI
    string shape;             // The shape to be entere dy the user
    double radius;           // The radius of a circle or cylinder
    double height;           // The height of a cylinder

    // Prompt the user to enter the type of shape
    cout << "Enter the shape type (rectangle, circle, cylinder): ";
    cin >> shape;            // Get the shape type from user input
    cout << endl;

    // If the shape is a rectangle
    if (shape == "rectangle") {
        double width;    // The width of the rectangle
        double length;   // The length of the rectangle

        // Prompt the user to enter the width of the rectangle
        cout << "Enter the width of the rectangle: ";
        cin >> width;    // Read the width from user input
        cout << endl;

        // Prompt the user to enter the length of the rectangle
        cout << "Enter the length of the rectangle: ";
        cin >> length;   // Get the length from user input
        cout << endl;

        // Calculate and display the area and perimeter of the rectangle
        cout << "Area of the rectangle = " << length * width << endl;
        cout << "Perimeter of the rectangle = " << 2 * (length + width) << endl;
    }
    // If the shape is a circle
    else if (shape == "circle") {
        // Prompt the user to enter the radius of the circle
        cout << "Enter the radius of the circle: ";
        cin >> radius;    // Get the radius from user input
        cout << endl;

        // Calculate and display the area and circumference of the circle
        cout << "Area of the circle = " << PI * pow(radius, 2.0) << endl;
        cout << "Circumference of the circle = " << 2 * PI * radius << endl;
    }
    // If the shape is a cylinder
    else if (shape == "cylinder") {
        // Prompt the user to enter the radius of the base of the cylinder
        cout << "Enter the radius of the base of the cylinder: ";
        cin >> radius;    // Get the radius from user input
        cout << endl;

        // Prompt the user to enter the height of the cylinder
        cout << "Enter the height of the cylinder: ";
        cin >> height;    // Get the height from user input
        cout << endl;

        // Calculate and display the surface area and volume of the cylinder
        cout << "Surface area of the cylinder = " << 2 * PI * radius * height + 2 * PI * pow(radius, 2.0) << endl;
        cout << "Volume of the cylinder = " << PI * pow(radius, 2.0) * height << endl;
    }
    // Check if the shape type is not recognized
    else {
        cout << "The program does not handle " << shape << endl;
    }

    // Set the output precision to 2 decimal places
    cout << fixed << showpoint << setprecision(2);

    return 0; // The end of the program
}
