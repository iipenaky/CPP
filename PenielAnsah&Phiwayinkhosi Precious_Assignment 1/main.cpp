// Libraries used
#include <iostream>
#include <fstream>
#include <string>
#include "Account.h"
#include "checkingAccount.h"
#include "savingsAccount.h"
#include "Customer.h"
#include "transaction.h"
#include <ctime>
#include <new> 
using namespace std;


// Function to read savings accounts from the savingsAccounts text file.
savingsAccount* readSavingsAccounts(const string filename, int &count) {
    int capacity = 1;  // intial capacity for the dynamic array
    count = 0; 
    // Allocating memory for the accounts array
    savingsAccount* accounts = static_cast<savingsAccount*>(operator new[](capacity * sizeof(savingsAccount))); // help from https://stackoverflow.com/questions/26497811/creating-an-array-of-objects-without-a-default-constructor 
    //opening the file for reading
    ifstream file(filename);
    // Check if the file failed to open
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        // delete the memory allocated
        operator delete[](accounts); 
        return nullptr;
    }
    // variable to store the account details
    string firstName, lastName, accountNumber, email, phoneNumber, line, dob, gen, addr;
    double balance;
    // read details from the file line by line
    while (getline(file, firstName)) {
        getline(file, lastName);
        getline(file, dob);
        getline(file, gen);
        getline(file, addr);
        getline(file, accountNumber);
        getline(file, email);
        getline(file, phoneNumber);
        file >> balance;
        file.ignore(); 
        getline(file, line); 

        // Check if the capacity needs to be increased.       
        if (count >= capacity) {
            capacity *= 2; // Double the capacity
            savingsAccount* newAccounts = static_cast<savingsAccount*>(operator new[](capacity * sizeof(savingsAccount))); // helped from https://stackoverflow.com/questions/26497811/creating-an-array-of-objects-without-a-default-constructor 
            for (int i = 0; i < count; ++i) {  // copy existing existing accounts into the new array with more capacity.
                new (newAccounts + i) savingsAccount(accounts[i]); 
                accounts[i].~savingsAccount(); 
            }
            operator delete[](accounts); // delete old memory
            accounts = newAccounts; 
        }

        // Initialize the next account with dynamic array placement
        new (accounts + count) savingsAccount(balance, 0.05); 
        // Set all account details for the newly added acount
        accounts[count].setFirstName(firstName);
        accounts[count].setLastName(lastName);
        accounts[count].setAccountNumber(accountNumber);
        accounts[count].setEmail(email);
        accounts[count].setPhone(phoneNumber);
        accounts[count].setAddress(addr);
        accounts[count].setDateOfBirth(dob);
        accounts[count].setGender(gen);
        
        count++; 
    }

    file.close(); 
    return accounts;
}

// Function to read checkings accounts from the checkingsAccount text file.
checkingAccount* readCheckingAccounts(const string filename, int &count) {
    int capacity = 1; 
    count = 0; 
     // Allocating memory for the accounts array
    checkingAccount* accounts = static_cast<checkingAccount*>(operator new[](capacity * sizeof(checkingAccount)));
    //opening the file for reading
    ifstream file(filename);
    // Check if the file failed to open
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        // delete the memory allocated
        operator delete[](accounts); 
        return nullptr;
    }
    // variable to store the account details
    string firstName, lastName, accountNumber, email, phoneNumber, line, dob, gen, addr;
    double balance;
    // read details from the file line by line
    while (getline(file, firstName)) {
        getline(file, lastName);
        getline(file, dob);
        getline(file, gen);
        getline(file, addr);
        getline(file, accountNumber);
        getline(file, email);
        getline(file, phoneNumber);
        file >> balance;
        file.ignore(); 
        getline(file, line); 

        // Check if the capacity needs to be increased.  
        if (count >= capacity) {
            capacity *= 2; // Double the capacity
            checkingAccount* newAccounts = static_cast<checkingAccount*>(operator new[](capacity * sizeof(checkingAccount))); // helped from https://stackoverflow.com/questions/26497811/creating-an-array-of-objects-without-a-default-constructor 
            for (int i = 0; i < count; ++i) {  // copy existing existing accounts into the new array with more capacity.
                new (newAccounts + i) checkingAccount(accounts[i]); 
                accounts[i].~checkingAccount(); 
            }
            operator delete[](accounts); // delete old memory
            accounts = newAccounts; 
        }

         // Initialize the next account with dynamic array placement
        new (accounts + count) checkingAccount(1.50, balance);
        // Set all account details for the newly added acount
        accounts[count].setFirstName(firstName);
        accounts[count].setLastName(lastName);
        accounts[count].setAccountNumber(accountNumber);
        accounts[count].setEmail(email);
        accounts[count].setPhone(phoneNumber);
        accounts[count].setAddress(addr);
        accounts[count].setDateOfBirth(dob);
        accounts[count].setGender(gen);
        
        count++;
    }

    file.close(); 
    return accounts; 
}

string getCurrentDate() {  //Sourced from https://stackoverflow.com/questions/27934034/get-current-time-in-mm-dd-yyyy-in-c 
    const int MAXLEN = 80; // Maximum length for the date  
    char s[MAXLEN]; // Buffer to hold the date string
    time_t t = time(0); // Get the current time 
    strftime(s, MAXLEN, "%Y-%m-%d", localtime(&t));// Format the date 
   return string(s); // Return the date as a string
} 



// Function to write a savings account's data to a file
void writeAccountToFile(string filename, savingsAccount account) {
    ofstream file(filename, ios::app); // Open the file in append mode
    if (file.is_open()) { // Check if the file opened successfully
        // Write account details to the file
        file << account.getFirstName() << "\n"
             << account.getLastName() << "\n"
             << account.getDateOfBirth() << "\n"
             << account.getGender() << "\n"
             << account.getAddress() << "\n"
             << account.getAccountNumber() << "\n"
             << account.getEmail() << "\n"
             << account.getPhone() << "\n"
             << account.getBalance() << "\n"
             << "EOD\n"; // Write end-of-data 
        file.close(); 
    } else {
        cerr << "Error opening file: " << filename << endl;
    }
}

// Overloaded function to write a checkings account's data to a file
void writeAccountToFile(string filename, checkingAccount account) {
    ofstream file(filename, ios::app); // Open the file in append mode
    if (file.is_open()) { // Check if the file opened successfully
    // Write account details to the file
        file << account.getFirstName() << "\n"
             << account.getLastName() << "\n"
             << account.getDateOfBirth() << "\n"
             << account.getGender() << "\n"
             << account.getAddress() << "\n"
             << account.getAccountNumber() << "\n"
             << account.getEmail() << "\n"
             << account.getPhone() << "\n"
             << account.getBalance() << "\n"
             << "EOD\n"; // Write end-of-data 
        file.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }
}

// Function to create an account
void createAccount() {
    int accountType;
    // Message to ask the user the account to be created
    cout << "Select the account type" << endl;
    cout << "1. Savings Account" << endl;
    cout << "2. Checking account" << endl;
    cout << "Choose 1 for savings, and 2 for checking: ";
    cin >> accountType;
    // Variable in the account creation
    string firstName, lastName, accountNumber, email, phoneNumber, dob, gen, addr;
    double balance;

    cout << "Enter first name: ";
    cin >> firstName;

    cout << "Enter last name: ";
    cin >> lastName;

    cout << "Enter your date of birth: ";
    cin >> dob;

    cout << "Enter your gender: ";
    cin >> gen;

    cout << "Enter your address: ";
    cin >> addr;

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter email: ";
    cin >> email;

    cout << "Enter phone number: ";
    cin >> phoneNumber;

    cout << "Enter initial balance: ";
    cin >> balance;
    
    // If account type chosen is 1, create a savings account
    if (accountType == 1) {
        // Add S infront of the savings account to indicate it is a savings account.
        accountNumber = "S" + accountNumber;
        // Set the attributes for the account
        savingsAccount newAccount(balance, 0.02);  
        newAccount.setFirstName(firstName);
        newAccount.setLastName(lastName);
        newAccount.setAccountNumber(accountNumber);
        newAccount.setEmail(email);
        newAccount.setPhone(phoneNumber);
        newAccount.setAddress(addr);
        newAccount.setGender(gen);
        newAccount.setDateOfBirth(dob);
    // write the account to the file
        writeAccountToFile("savingsAccount.txt", newAccount);
    } 
    // Check if the account type chosen is 2, indicating a checkings account.
    else if (accountType == 2) {
        // Add C infront of the checkings account to indicate it being a checkings account
        accountNumber = "C" + accountNumber;
        // Set the attributes for the account
        checkingAccount newAccount(1.50, balance); 
        newAccount.setFirstName(firstName);
        newAccount.setLastName(lastName);
        newAccount.setAccountNumber(accountNumber);
        newAccount.setEmail(email);
        newAccount.setPhone(phoneNumber);
        newAccount.setAddress(addr);
        newAccount.setGender(gen);
        newAccount.setDateOfBirth(dob);
        writeAccountToFile("checkingAccount.txt", newAccount);
    } 
    // If option chosen is not 1 or 2, prompt that it is invalid.
    else {
        cout << "Invalid account type selected.\n";
    }
}

// Function to write transaction repots to a file.
void writeTransactionToFile(string filename, transaction trans) {
    ofstream file(filename, ios::app); // Open the file in append mode
    if (file.is_open()) {// Check if the file opened successfully
        file << trans.getAccountNumber() << "\n"
             << trans.getAccountBalance() << "\n"
             << trans.getCurrentDate() << "\n"
            <<trans.getTransactionType() << "\n"
             << "EOD\n"; // Write end-of-data 
        file.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }
}

// Function to withdraw from account
void withdrawFromAccount() {
    string accountNumber;
    // Ask user for their account number.
    cout << "Enter account number starting with 'S' for savings or 'C' for checking: ";
    cin >> accountNumber;
    // If account number starts with S, it is a savings account.
    if (accountNumber[0] == 'S') {
        int count = 0;
        // Get a dynamic array of the savings account
        savingsAccount* accounts = readSavingsAccounts("savingsAccount.txt", count); 
        bool found = false;
    // Loop through the array to find the account number
        for (int i = 0; i < count; ++i) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                found = true;
                double money;
                // Ask for the amount to be withdrawn
                cout << "Enter the amount you want to withdraw: " << endl;
                cin >> money;
                // Withdraw the money
                if (accounts[i].withdrawCash(money)) {
                    cout << "Withdrawal successful.\n";
                    // write the transaction report to a file
                    transaction transaction(accountNumber, accounts[i].getBalance(), "Withdrawal", getCurrentDate());
                    writeTransactionToFile("transactions.txt", transaction);
                } else {
                    cout << "Insufficient funds for withdrawal.\n";
                }
                break;
            }
        }
        // Prompt user if not found.
        if (!found) {
            cout << "Account number doesn't exist. Please crosscheck and try again." << endl;
        }
        // Update account details the account to a file.
        ofstream file("savingsAccount.txt");
        for (int i = 0; i < count; ++i) {
            writeAccountToFile("savingsAccount.txt", accounts[i]);
        }
        // delete accounts.
        delete[] accounts; 
    }
    // If the account number starts with a C, it is acheckings account
    else if (accountNumber[0] == 'C') {
        int count = 0; 
        // Get a dynamic array of the checkings account
        checkingAccount* accounts = readCheckingAccounts("checkingAccount.txt", count); 
        bool found = false;
        // Loop through the array to find the account number
        for (int i = 0; i < count; ++i) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                found = true;
                double money;
                // Ask for the amount to be withdrawn
                cout << "Enter the amount you want to withdraw: ";
                cin >> money;
                // Withdraw the money
                if (accounts[i].withdrawCash(money)) {
                    cout << "Withdrawal successful.\n";
                    // write the transaction report to a file
                    transaction transaction(accountNumber, accounts[i].getBalance(), "Withdrawal", getCurrentDate());
                    writeTransactionToFile("transactions.txt", transaction);
                } else {
                    cout << "Insufficient funds for withdrawal.\n";
                }
                break;
            }
        }
        // Prompt user if not found.
        if (!found) {
            cout << "Account number doesn't exist. Please crosscheck and try again.\n";
        }

        // Update account details the account to a file
        ofstream file("checkingAccount.txt");
        for (int i = 0; i < count; ++i) {
            writeAccountToFile("checkingAccount.txt", accounts[i]);
        }
        // delete accounts.   
        delete[] accounts; 
    } else {
        cout << "Invalid account number format.\n";
    }
}

// Function to deposit to an account
void depositToAccount() {
    string accountNumber;
    // Ask for the account number
    cout << "Enter account number starting with 'S' for savings or 'C' for checking: ";
    cin >> accountNumber;
    // Check if account is a savings account
    if (accountNumber[0] == 'S') {
        int count = 0; 
        // Get the array of all the accounts from the file
        savingsAccount* accounts = readSavingsAccounts("savingsAccount.txt", count); 
        bool found = false;
        // Loop through the array to find the account.
        for (int i = 0; i < count; ++i) {
            // If account found,
            if (accounts[i].getAccountNumber() == accountNumber) {
                found = true;
                double money;
                // Ask the user the amount to deposit
                cout << "Enter the amount you want to deposit: " << endl;
                cin >> money;
                // deposit the money
                if (accounts[i].depositCash(money)) {
                    cout << "Deposit successful.\n";
                    // write transaction report to a file
                    transaction transaction(accountNumber, accounts[i].getBalance(), "Deposit", getCurrentDate());
                    writeTransactionToFile("transactions.txt", transaction);
                } else {
                    cout << "Something went wrong with the deposit.\n";
                }
                break;
            }
        }
        // Prompt user if not found
        if (!found) {
            cout << "Account number doesn't exist. Please crosscheck and try again." << endl;
        }
        // Write updated details to file
        ofstream file("savingsAccount.txt");
        for (int i = 0; i < count; ++i) {
            writeAccountToFile("savingsAccount.txt", accounts[i]);
        }
        // delete the accounts.
        delete[] accounts;
    }
    // Check if account is a checkings account
    else if (accountNumber[0] == 'C') {
        int count = 0; 
        // Get the array of all the accounts from the file
        checkingAccount* accounts = readCheckingAccounts("checkingAccount.txt", count); 
        bool found = false;
        // Loop through the array to find the account.
        for (int i = 0; i < count; ++i) {
            // If account found,
            if (accounts[i].getAccountNumber() == accountNumber) {
                found = true;
                double money;
                // Ask the user the amount to deposit
                cout << "Enter the amount you want to deposit: " << endl;
                cin >> money;
                // deposit the money
                if (accounts[i].depositCash(money)) {
                    cout << "Deposit successful.\n";
                    // write transaction report to a file
                    transaction transaction(accountNumber, accounts[i].getBalance(), "Deposit", getCurrentDate());
                    writeTransactionToFile("transactions.txt", transaction);
                } else {
                    cout << "Something went wrong with the deposit.\n";
                }
                break;
            }
        }
        // Prompt user if not found
        if (!found) {
            cout << "Account number doesn't exist. Please crosscheck and try again." << endl;
        }
        // Write updated details to file
        ofstream file("checkingAccount.txt");
        for (int i = 0; i < count; ++i) {
            writeAccountToFile("checkingAccount.txt", accounts[i]);
        }
        // delete the accounts.
        delete[] accounts; 
    } else {
        cout << "Invalid account number format.\n";
    }
}

// Function to add interest to a specified savings account
void addInterestToSavingsAccount() {
    string accountNumber;
    // Ask user for their savings account number
    cout << "Enter the savings account number starting with 'S': ";
    cin >> accountNumber;
    // Check if the account number starts with 'S
    if (accountNumber[0] == 'S') {
        int count = 0; 
        // Read the savings accounts from the file and get the count
        savingsAccount* accounts = readSavingsAccounts("savingsAccount.txt", count); 
        bool found = false;
        // Loop through the account to find the account
        for (int i = 0; i < count; ++i) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                found = true;
                // Calculate the interest for the account
                double interest = accounts[i].calculateInterest();
                // Deposit the interest into the account
                accounts[i].depositCash(interest);
                cout << "Interest of " << interest << " added successfully.\n";
                // Write the transaction details to the transaction file
                transaction transaction(accountNumber, accounts[i].getBalance(), "Interest Credit", getCurrentDate());
                writeTransactionToFile("transactions.txt", transaction);
                break;
            }
        }
        // Prompt user if not found
        if (!found) {
            cout << "Account number doesn't exist. Please crosscheck and try again." << endl;
        }
        // Write all accounts back to the file to save changes
        ofstream file("savingsAccount.txt");
        for (int i = 0; i < count; ++i) {
            writeAccountToFile("savingsAccount.txt", accounts[i]);
        }
        // Free the memory allocated for accounts
        delete[] accounts; 
    } else {
        cout << "Invalid savings account number format. Please enter a number starting with 'S'.\n";
    }
}

// Function to display account details based on the account number
void displayAccountDetails(string accountNumber) {
    // If it is a savings account
    if (accountNumber[0] == 'S') {
        int count = 0;
        // Get the array of all accounts in the file
        savingsAccount* accounts = readSavingsAccounts("savingsAccount.txt", count);
        bool found = false;
        // Loop through the array to find the account
        for (int i =0; i < count; i++){
            if (accounts[i].getAccountNumber()== accountNumber){
                found = true;
                cout << "\nCustomer Info: \n";
                // Display the customer's information.
                accounts[i].displayCustomerInfo();
                break;
            }
        }
        // prompt user if not found
        if (!found){
            cout << "Account number doesn't exist. Please crosscheck and try again." << endl;
        }
    }
    // If it is a checkings account
    else if (accountNumber[0] == 'C') {
        int count = 0;
        // Read accounts to an array
        checkingAccount* accounts = readCheckingAccounts("checkingAccount.txt", count);
        bool found = false;
        // Loop through the account to find the array
        for (int i =0; i < count; i++){
            if (accounts[i].getAccountNumber()== accountNumber){
                found = true;
                cout << "\n Customer Info: \n";
                // Display the customer's information
                accounts[i].displayCustomerInfo();
                break;
            }
        }
        // Prompt user if not found.
        if (!found){
            cout << "Account number doesn't exist. Please crosscheck and try again." << endl;
        }
    }
    else{
        cout << "Invalid account. Please check the account number again";
    }

} 

// Function to generate the report
void generateReport() { 
    // Variables to store the date range and customer ID
    string startDate, endDate, customerId;
    cout << "Enter start date (YYYY-MM-DD): ";
    cin >> startDate;
    cout << "Enter end date (YYYY-MM-DD): ";
    cin >> endDate; 
    cout << "Enter customer ID(Start with S if it is a savings account and C if it is a checkings account): ";
    cin >> customerId;

    // Display customer details
    displayAccountDetails(customerId);

    // open the transactions file
    ifstream transactionFile("transactions.txt");

    // Check if it wasn't opened
    if (!transactionFile.is_open()) {
        cerr << "Error opening transactions file.\n";
        return; 
    }

    // Variables to hold the attributes of the transaction
    string accountNumber, date, transactionType, line;
    double balance;
    cout << "\nTransactions for customer " << customerId << " between " << startDate << " and " << endDate << ":\n";

    // Read the transaction records from the file line by line
    while (getline(transactionFile, accountNumber)) {
        transactionFile >> balance;
        transactionFile.ignore(); 
        getline(transactionFile, date);
        getline(transactionFile, transactionType);
        getline(transactionFile, line);

        // Check if the transaction date is within the specified range
        if (date >= startDate && date <= endDate) {
            // Check if the account number matches the customer ID
            if (accountNumber == customerId) {
                // Display the transaction details to the user
                cout <<"\nAccount Number: " << accountNumber << "\n"
                     << "Balance: " << balance << "\n"
                     << "Date of Transaction: " << date << "\n"
                     << "Type of Transaction: " << transactionType << "\n";
            }
        }
    }
    transactionFile.close(); 
}

// Main function to control the flow of the bank system
int main() {
    int choice; 

    // Loop to show the menu and process user choices
    do {
        cout << "\nWelcome to the Double P Bank:)\n"
             << "1. Create a new account\n"
             << "2. Deposit to an account\n"
             << "3. Withdraw from an account\n"
             << "4. Generate a report\n"
             << "5. Add interest to a savings account\n" 
             << "6. Exit\n"
             << "Select an option: ";
        cin >> choice; 

        // Handle the user's choice with a switch statement
        switch (choice) {
            case 1:
                createAccount(); 
                break;
            case 2:
                depositToAccount(); 
                break;
            case 3:
                withdrawFromAccount(); 
                break;
            case 4:
                generateReport(); 
                break;
            case 5:
                addInterestToSavingsAccount(); 
                break;
            case 6: 
                cout << "Bye bye, Hope to see you soon..\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    } while (choice != 6);  

    return 0; 
}