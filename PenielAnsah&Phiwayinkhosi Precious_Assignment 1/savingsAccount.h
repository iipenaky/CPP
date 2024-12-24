
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <iostream>
#include <string>
#include "Account.h"
using namespace std;
// A savings account class inheriting from Account
class savingsAccount : public Account {
    private:
        double interestRate;
    public: 
        savingsAccount(double accountBalance, double interest);
        void setInterest(double interest);
        double getInterest() const;
        double calculateInterest();
};

// constructor
savingsAccount :: savingsAccount(double balance, double rate) : Account(balance){
    setInterest(rate);
};

// A method to set interest
void savingsAccount :: setInterest(double interest) {
    interestRate = interest;
}

// A method to get interest
double savingsAccount :: getInterest() const{
    return interestRate;
}


//calculating savings account interest received
double savingsAccount :: calculateInterest(){
    double interest = interestRate * accountBalance;
    return interest;
}

#endif