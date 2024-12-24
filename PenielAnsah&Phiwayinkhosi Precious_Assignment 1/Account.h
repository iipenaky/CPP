#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;
// An Account class
class Account : public Customer {
    protected:
        double accountBalance;

    public:
        Account(double initialBalance);
        bool depositCash(double money);
        bool withdrawCash(double money);
        double getBalance() const;  
};

// Constructor
Account::Account(double initialBalance) {
    if (initialBalance >= 0){
        accountBalance = initialBalance;
        return;
    }
    cout << "The amout doesn't exist. Please enter a valid amount of money";
    accountBalance = 0.0;
}

// Method to deposit money
bool Account::depositCash(double money) {
    if (money > 0){
        accountBalance += money;
        return true;
    }
    cout << "Please enter a valid amout of money";
    return false;
}

// Method to withdraw money
bool Account::withdrawCash(double money) {
    if (money > 0 && money <= accountBalance) {
        accountBalance -= money;
        return true;
    }
    cout << "The amount is either greater than your account balance, or invalid";
    return false;
}

// Method to get current balance
double Account::getBalance() const {
    return accountBalance;
}

#endif
