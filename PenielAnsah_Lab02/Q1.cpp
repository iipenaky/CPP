#include <iostream>
#include <string>
#include <cctype>  //referenced from https://www.programiz.com/cpp-programming/library-function/cctype/
using namespace std;

// Define a class called romanType
class romanType {
private:
    string romanNumeral; // To store the Roman numeral
    int integerValue;    // To store the converted integer value

    // Function to convert a Roman numeral to an integer
    int convertToInteger(string roman) {
        int intVersion = 0; // Initialize the integer version to 0
        int previous = 0;   // To keep track of the previous value
        
        // Loop through each character in the Roman numeral string
        for (int i = 0; i < roman.length(); i++) {
            char letter = roman[i]; // Get the current character
            int currentValue = 0;   // To store the current value

            // Determine the integer value of the current Roman numeral character
            if (letter == 'M'){
                currentValue = 1000;
            } else if (letter == 'D'){
                currentValue = 500;
            } else if (letter == 'C'){
                currentValue = 100;
            } else if (letter == 'L'){
                currentValue = 50;
            } else if (letter == 'X'){
                currentValue = 10;
            } else if (letter == 'V'){
                currentValue = 5;
            } else if (letter == 'I'){
                currentValue = 1;
            }
            
            // Adjust the total based on the current value and the previous value
            if (currentValue > previous) {
                intVersion = intVersion - previous; // Subtract the previous value
                intVersion = intVersion + (currentValue - previous); // Add the new value minus previous
            } else {
                intVersion += currentValue; // Just add the current value
            }

            previous = currentValue; // Update previous value for the next iteration
        }

        return intVersion; // Return the converted integer value
    }

public:
    // Function to set the Roman numeral and convert it to an integer
    void setAndConvertRoman(string roman) {
        romanNumeral = roman; // Store the Roman numeral
        integerValue = convertToInteger(roman); // Convert it to an integer
    }

    // Function to print the Roman numeral
    void printromanNumeral() {
        cout << "Roman Numeral: " << romanNumeral << endl;
    }

    // Function to print the integer value
    void printIntegerValue() {
        cout << "Integer Value: " << integerValue << endl;
    }

    // Function to check if the input is a valid Roman numeral
    bool checkIsRoman(string roman){
        // Loop through each character in the Roman numeral string
        for (int i = 0; i < roman.length(); ++i) {
            char current = roman[i]; // Get the current character
            // Check if the character is not a valid Roman numeral
            if (current != 'M' && current != 'D' && current != 'C' && current != 'L' && current != 'X' && current != 'V' && current != 'I') {
                return false; // Return false if an invalid character is found
            }
        }
        return true; // Return true if all characters are valid
    }
};

int main(){
    romanType numeral1 = romanType(); // Create an instance of the romanType class
    string roman; // To store the user's input

    // Ask the user to enter a Roman numeral
    cout << "Please enter the Roman numeral you want to convert: ";
    cin >> roman;

    // Convert the input to uppercase
    for (char& c : roman) {
        c = toupper(c);
    }
    
    // Check if the input is a valid Roman numeral
    bool isValid = numeral1.checkIsRoman(roman);
    // Loop until the user enters a valid Roman numeral
    while(isValid == false){
        cout << "Invalid Roman numeral\nPlease enter the numeral again: ";
        cin >> roman;
    }

    // Set and convert the valid Roman numeral
    numeral1.setAndConvertRoman(roman);
    int choice; // To store the user's choice for output

    // Ask the user if they want to see the Roman numeral or the integer value
    cout << "Would you want to see your roman numeral or the integer?\nEnter 1 for the roman numeral and 2 for the integer version: ";
    cin >> choice;

    // Loop until the user makes a valid choice
    while (choice != 1 && choice !=2){
        cout << "Invalid choice. Please enter again: ";
        cin >> choice;
    }

    // Print the corresponding output based on the user's choice
    if (choice == 1){
        numeral1.printromanNumeral(); // Print the Roman numeral
    } else {
        numeral1.printIntegerValue(); // Print the integer value
    }

    return 0; // End of the program
}
