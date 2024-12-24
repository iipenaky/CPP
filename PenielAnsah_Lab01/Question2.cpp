#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    // Variables to store user inputs
    double netBalance;         // Balance shown in the bill
    double payment;            // Payment made
    int d1;                    // Number of days in the billing cycle
    int d2;                    // Number of days payment is made before billing cycle
    double interestRateperMonth; // Interest rate per month

    // Prompt the user for inputs and read them
    cout << "Enter the balance shown in the bill: ";
    cin >> netBalance;
    cout << endl;

    cout << "Enter the payment made: ";
    cin >> payment;
    cout << endl;

    cout << "Enter the number of days in the billing cycle: ";
    cin >> d1;
    cout << endl;

    cout << "Enter the number of days payment is made before billing cycle: ";
    cin >> d2;
    cout << endl;

    cout << "Enter the interest rate per month: ";
    cin >> interestRateperMonth;
    cout << endl;

    // Calculate the average daily balance
    double averageDailyBalance = (netBalance * d1 - payment * d2) / d1;

    // Calculate the interest based on the average daily balance and interest rate
    double interest = averageDailyBalance * interestRateperMonth;

    // Output the interest
    cout << "The interest is ";
    cout << fixed << setprecision(2) << interest << endl;

    return 0; // The end of the program
}
