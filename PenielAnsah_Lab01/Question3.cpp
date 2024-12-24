#include <iostream>
using namespace std;


/**
 * Function to determine the optimal number of units to rent
 *
 * @param totalUnits The total number of units available
 * @param rent The rent amount when all units are occupied
 * @param rentIncrease The increase in rent for an additional empty unit
 * @param maintenance The maintenance cost per unit
 * @param optimalUnits References the optimal number of units to rent
 * @return The optimal number of units to rent
 */
double getOptimalUnits(int totalUnits, double rent, double rentIncrease, double maintenance) {
    double maxProfit = 0; // maxProfit to track the highest profit
    int optimalUnits;

    // Iterate over all possible numbers of rented units
    for (int x = 0; x <= totalUnits; ++x) {
        // Calculate the rent per unit for the current number of rented units
        double rentPerUnit = rent + rentIncrease * x;
        // Calculate the number of occupied units (total units - rented units)
        int occupiedUnits = totalUnits - x;

        // The total revenue from renting the occupied units
        double totalRevenue = rentPerUnit * occupiedUnits;
        // The total maintenance cost for the occupied units
        double totalMaintenanceCost = maintenance * occupiedUnits;
        // The profit as total revenue minus total maintenance cost
        double profit = totalRevenue - totalMaintenanceCost;

        // If the current profit is greater than the recorded maximum profit
        if (profit > maxProfit) {
            // Update maxProfit with the new higher profit
            maxProfit = profit;
            // Update the optimal number of units to rent to achieve the maximum profit
            optimalUnits = occupiedUnits;
        }
    }

    // Return the optimal units for profit to be maximized
    return optimalUnits;
}

int main() {
    // Variables to store user inputs and results
    int totalUnits;      // Total number of units available
    double rent;         // Rent amount when all units are occupied
    double rentIncrease; // Increase in rent for each additional empty unit
    double maintenance; // Maintenance cost per rented unit

    // Prompts the user for the total number of units available
    cout << "Enter the total number of units: ";
    cin >> totalUnits;

    // Prompts the user for the rent amount when all units are occupied
    cout << "Enter the rent to occupy all units: ";
    cin >> rent;

    // Prompts the user for the increase in rent for each additional vacant unit
    cout << "Enter the increase in rent that results in a vacant unit: ";
    cin >> rentIncrease;

    // Prompts the user for the maintenance cost for a rented unit
    cout << "Enter the amount to maintain a rented unit: ";
    cin >> maintenance;

    // Get the optimal number of units to rent
    double optimalUnits = getOptimalUnits(totalUnits, rent, rentIncrease, maintenance);

    // Output the optimal number of units to rent and the maximum profit
    cout << "To maximize profit, rent " << optimalUnits << " units" << endl;

    return 0; // The end of the program
}
