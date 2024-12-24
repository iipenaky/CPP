// transaction.h
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
class transaction {
private:
    string accountNumber;
    double accountBalance;
    string transactionType; 
    string currentDate;    
       

public:
    // Constructor
    transaction(string accNum, double balance, string transType, string date){
        accountNumber = accNum;
        accountBalance = balance;
        transactionType = transType;
        currentDate = date;
    }

    //getters
    string getAccountNumber() const {
        return accountNumber;
    }

    double getAccountBalance() const {
        return accountBalance;
    }

    string getTransactionType() const {
        return transactionType;
    }

    string getCurrentDate() const {
        return currentDate;
    }
};

#endif 
