#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include <iostream>
#include <string>
#include "Account.h"
using namespace std;
// A checking account class, inheriting from Account
class checkingAccount : public Account {
    protected:
        double transactionFee;
    
    public:
        checkingAccount(double fee, double balance);
        double getFee() const;
        void setFee(double fee);
        bool withdrawCash(double money);
        bool depositCash(double money);
};
// constructor
checkingAccount :: checkingAccount(double fee, double balance) : Account(balance) {
            transactionFee = fee;
}

// A method to get the fee
double checkingAccount :: getFee() const{
    return transactionFee;
}

// A method to set the fee
void checkingAccount:: setFee (double fee) {
    transactionFee = fee;
}

// A method to withdraw cash by overriding the account withdrawing cash
bool checkingAccount :: withdrawCash (double money) {
    if ((money + transactionFee) <= accountBalance){
        accountBalance -= (money + transactionFee);
        return true;
    }
    return false;
}

// A method to deposit cash, overring the Account's method
bool checkingAccount :: depositCash (double money) {
    if( money > 0 && (accountBalance+money) >= transactionFee){
        accountBalance += (money - transactionFee);
        return true;
    }
    cout << "Enter a valid number or deposit";
    return false;
    
}

#endif