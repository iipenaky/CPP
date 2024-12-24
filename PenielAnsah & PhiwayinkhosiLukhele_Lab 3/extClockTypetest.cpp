#include <iostream>
#include <string>
#include "clockType.h"
#include "extClockType.h"
using namespace std;

int main() {
    extClockType clock1 = extClockType(10, 30, 45, "EST");
    cout << "Initial time: ";
    clock1.printTime();

    // Change time zone to Pacific Standard Time
    clock1.setTimeZone("PST");
    cout << "After changing time zone: ";
    clock1.printTime();

    // Example of setting time
    clock1.setHr(12);
    clock1.setMin(15);
    clock1.setSec(30);
    cout << "After setting new time: ";
    clock1.printTime();

    return 0;
}
