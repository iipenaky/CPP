#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>


#include <iostream>
#include <string>
using namespace std;

// A customer class
class Customer {
    protected:
        string accountNumber;
        string firstName;
        string lastName;
        string dateOfBirth;
        string gender;
        string address;
        string phone;
        string email;

    public:
        Customer(string accNum, string fName, string lName, string dob, string gen, 
                 string addr, string ph, string em);
        Customer();
        void setAccountNumber(string accNum);
        void setFirstName(string fName);
        void setLastName(string lName);
        void setDateOfBirth(string dob);
        void setGender(string gen);
        void setAddress(string addr);
        void setPhone(string ph);
        void setEmail(string em);
        string getAccountNumber() const;
        string getFirstName() const;
        string getLastName() const;
        string getDateOfBirth() const;
        string getGender() const;
        string getAddress() const;
        string getPhone() const;
        string getEmail() const;
        void displayCustomerInfo() ;
};

// Constructor
Customer :: Customer(){}

 // Setters
void Customer :: setAccountNumber(string accNum) {
        accountNumber = accNum; 
}
void Customer :: setFirstName(string fName) {
         firstName = fName; 
}
void Customer :: setLastName(string lName) { 
        lastName = lName; 
}
void Customer :: setDateOfBirth(string dob) {
        dateOfBirth = dob; 
}
void Customer :: setGender(string gen) { 
        gender = gen; 
}
void Customer :: setAddress(string addr) { 
        address = addr; 
}
void Customer :: setPhone(string ph) { 
        phone = ph; 
}
void Customer :: setEmail(string em) { 
        email = em; 
}

        // Getters
string Customer ::  getAccountNumber() const{ return accountNumber; }
string Customer :: getFirstName() const { return firstName; }
string Customer :: getLastName() const { return lastName; }
string Customer :: getDateOfBirth() const { return dateOfBirth; }
string Customer :: getGender() const { return gender; }
string Customer :: getAddress() const { return address; }
string Customer :: getPhone() const { return phone; }
string Customer :: getEmail() const { return email; }

        // Display Customer information
void Customer ::displayCustomerInfo()  {
            cout << "Account Number: " << accountNumber << endl;
            cout << "Name: " << firstName << " " << lastName << endl;
            cout << "Date of Birth: " << dateOfBirth << endl;
            cout << "Gender: " << gender << endl;
            cout << "Address: " << address << endl;
            cout << "Phone: " << phone << endl;
            cout << "Email: " << email << endl;
        }

#endif