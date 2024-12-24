// Prevents multiple inclusions of this header file
#ifndef CHECKINGACCOUNT_H    
#define CHECKINGACCOUNT_H 
// Include the base class Bank Account
#include "BankAccount.h"    

using namespace std;        

// Declaration of the CheckingAccount class, derived from BankAccount
class CheckingAccount : public BankAccount {
public:
    // Constructor initializes balance to 0
    CheckingAccount() {
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
            + " into Checking Account. New balance: $" + to_string(balance);
        // Print the transaction to the console
        cout << transaction << "\n"; 
        // Notify any threads waiting for sufficient balance
        cv.notify_all();             
        // Record the transaction in the file
        record_transaction(transaction); 
    }

    // Withdraw money from the account
    void withdraw(double amount, int customer_id) override {
        // Acquire the lock within a 100-millisecond timeout
        if (timeout.try_lock_for(chrono::milliseconds(100))) {
            // Check if there is enough balance
            if (balance >= amount+ (amount*0.05)) { 
            // Deduct the withdrawal amount plus charges
                balance -= round_money(amount+ (amount*0.05));  
                // Create a transaction message
                string transaction = "Customer " + to_string(customer_id) + " withdrew $" + to_string(round_money(amount))
                    + " from Checking Account. New balance: $" + to_string(balance);
                // Print the transaction to the console
                cout << transaction << "\n"; 
                // Record the transaction in the file
                record_transaction(transaction); 
            } else {
                // Record when account has insufficient funds 
                string transaction = "Customer " + to_string(customer_id) + " tried to withdraw $" 
                    + to_string(amount) + " but has insufficient funds in Checking Account. Balance: $" 
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
        // Do nothing, as checking accounts don't accrue interest
        return; 
    }
};

#endif 
