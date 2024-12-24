// Include account classes
#include "BankAccount.h"       
#include "SavingsAccount.h"   
#include "CheckingAccount.h"   

// Simulates customer actions on bank accounts
void customer(BankAccount& account, int customer_id) {
    for (int i = 0; i < 5; i++) {  // Each customer performs 5 actions
        int action = rand() % 2;   // 0 for deposit, 1 for withdrawal
        int amount = rand() % 50 + 1;  // Randomly amount between $1 and $50

        // Perform the chosen action
        if (action == 0) {
            // Deposit the random amount
            account.withdraw(amount, customer_id);  
        } else {
            // Withdraw the random amount
            account.deposit(amount, customer_id); 
        }

        // Simulate processing time
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void add_interest_periodically(SavingsAccount& savings) {
    while (savings.should_add_interest()) {
        this_thread::sleep_for(chrono::milliseconds(75));
        
        // Apply interest if eligible
        if (savings.should_add_interest() && savings.get_balance() > 0) {
            savings.add_interest();
        }
    }
}


int main() {
    // Create account objects for checking and savings accounts
    CheckingAccount checking_account;
    SavingsAccount savings_account;

    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Create a multiple threads to simulate multiple customers
    vector<thread> threads;

    // Thread for applying interest to the savings account
    thread interest_thread(add_interest_periodically, ref(savings_account));

    // Simulate 10 customers performing actions
    for (int i = 1; i <= 10; ++i) { 
        if (i % 2 == 0) {
            // Even-numbered customers use the SavingsAccount
            threads.emplace_back(customer, ref(savings_account), i);
        } else {
            // Odd-numbered customers use the CheckingAccount
            threads.emplace_back(customer, ref(checking_account), i);
        }
    }

    // Wait for all customer threads to complete
    for (auto& t : threads) {
        t.join();
    }

    // Wait for the interest thread to finish
    interest_thread.join();

    // Print the final balances of both accounts
    cout << "Final Checking Account balance: $" << checking_account.get_balance() << "\n";
    cout << "Final Savings Account balance: $" << savings_account.get_balance() << "\n";

    return 0; 
}
