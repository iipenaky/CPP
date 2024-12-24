// Prevents multiple inclusions of the header file
#ifndef SAVINGSACCOUNT_H    
#define SAVINGSACCOUNT_H 
// Include the parent class BankAccount
#include "BankAccount.h"    

// Declaration of the SavingsAccount class, derived from BankAccount
class SavingsAccount : public BankAccount {
private:
// Interest rate for the savings account
    double interest_rate = 0.15;  
    // Tracks how many times interest has been applied
    int interest_applications = 0; 

public:
    // Constructor initializes balance to 0
    SavingsAccount() {
        balance = 0; 
    }

    // Deposit money into the account
    void deposit(double amount, int customer_id) override {
        // Ensures thread-safe access to balance
        lock_guard<mutex> lock(mtx); 
         // Add the deposit amount to the balance
        balance += round_money(amount);         
        // Create a transaction message
        string transaction = "Customer " + to_string(customer_id) + " deposited $" + to_string(amount)
            + " into Savings Account. New balance: $" + to_string(balance);
        // Print the transaction to the console
        cout << transaction << "\n"; 
        // Notify any threads waiting for sufficient balance
        cv.notify_all();             
        // Record the transaction in the file
        record_transaction(transaction); 
    }

    // Withdraw money from the account
    void withdraw(double amount, int customer_id) override {
        // Acquires the lock within a 100-millisecond timeout
        if (timeout.try_lock_for(chrono::milliseconds(100))) {
            if (balance >= amount) { // Check if there is enough balance
                // Deduct the withdrawal amount
                balance -= round_money(amount);  
                // Create a transaction message
                string transaction = "Customer " + to_string(customer_id) + " withdrew $" + to_string(amount)
                    + " from Savings Account. New balance: $" + to_string(balance);
                // Print the transaction to the console
                cout << transaction << "\n"; 
                // Record the transaction in the file
                record_transaction(transaction); 
            } else {
                // Record insufficient funds 
                string transaction = "Customer " + to_string(customer_id) + " tried to withdraw $" 
                    + to_string(amount) + " but has insufficient funds in Savings Account. Balance: $" 
                    + to_string(balance);
                // Print the message to the console
                cout << transaction << "\n"; 
                // Record the transaction in the file
                record_transaction(transaction); 
            }   
            // Release the lock
            timeout.unlock();     
        } else {
            // Handle timeout if lock acquisition fails
            cout << "Timeout reached while trying to lock!\n";
        }
    }

    // Apply interest to the account
    void add_interest() override {
        // Ensure thread-safe access to balance
        lock_guard<mutex> lock(mtx); 

        // Calculate and add interest to the balance
        double interest = balance * interest_rate;
        balance += round_money(interest);

        // Record the interest application
        string transaction = "15% interest added to Savings Account. New balance: $" 
        + to_string(balance);
        // Print the transaction to the console
        cout << transaction << "\n"; 
        // Record the transaction in the file
        record_transaction(transaction); 
        // Increment the interest application counter
        interest_applications++; 
    }

    // Check if interest can still be applied
    bool should_add_interest() {
        // Ensure thread-safe access to interest_applications
        lock_guard<mutex> lock(mtx); 
        // Return true if interest can be applied
        return interest_applications < 12; 
    }
};

#endif 