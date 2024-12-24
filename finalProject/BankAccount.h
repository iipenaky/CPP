// Prevents multiple inclusions of the header file
#ifndef BANKACCOUNT_H    
#define BANKACCOUNT_H 

#include <iostream>             
#include <thread>               
#include <mutex>                
#include <condition_variable>   
#include <vector>               
#include <chrono>               
#include <fstream>              
#include <string>              
#include <ctime>                
#include <iomanip>                  
#include <cmath>

using namespace std;            

// Declaration of the Bank Account class
class BankAccount {
protected:
    // The current balance
    double balance;   
    // Ensures safe access to shared balance across threads          
    mutex mtx;             
    // File stream for recording transactions     
    ofstream output;    
    // Timed locking mechanism
    timed_mutex timeout;   
    // Synchronizes threads with conditions     
    condition_variable cv;      

public:
    // Constructor initializes the balance to 0 and opens the transaction record file
    BankAccount() : balance(0) {
        // Open file in append mode
        output.open("transactions.txt", ios::app);  
    }

    // Destructor to close the record file properly
    ~BankAccount() {
        if (output.is_open()) {  // Check if the file is still open
            output.close();      // Close the file
            cout << "File closed";
        }
    }

    // CurrentDateTime function from https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
    const string currentDateTime() {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        // Format the date&time string as "YYYY-MM-DD HH:MM:SS"
        strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
        return buf;
    }

    void record_transaction(string transaction) {
        // Proceed only if the file is open
        if (output.is_open()) {  
            // Get the current timestamp
            string timestamp = currentDateTime(); 

            // Write the timestamp and transaction details to the file
            output << timestamp << " || " << transaction << endl;
        }
    }

    // Function for depositing money, to be implemented by savings and checking classes
    virtual void deposit(double amount, int customer_id) = 0;

    // Function for withdrawing money, to be implemented by savings and checking classes
    virtual void withdraw(double amount, int customer_id) = 0;

    // Function for applying interest, to be implemented by savings class
    virtual void add_interest() = 0;

    // Returns the current account balance
    double get_balance() {
        // Lock access to balance for thread safety
        lock_guard<mutex> lock(mtx);  
        // Return the balance
        return balance;               
    }

    // Function to round money to two decimal places
    double round_money(double value) {
        return round(value * 100.0) / 100.0;
    }
};

#endif  
