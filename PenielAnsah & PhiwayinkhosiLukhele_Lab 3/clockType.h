#ifndef CLOCKTYPE_H   
#define CLOCKTYPE_H   
#include <iostream>
#include <string>   
using namespace std; 

// Define a class called clockType
class clockType {
    public:
        // Method to set hours
        void setHr(int );
        // Method to set minutes
        void setMin(int );
        // Method to set seconds
        void setSec(int );
        

        int getHr() const {
            return hr; 
        };
        
        int getMin() const {
            return min;
        };
        
        int getSec() const {
            return sec; 
        };

    private:
        int hr;  
        int min; 
        int sec; 
};

void clockType::setHr(int h) {
   hr = h;
}

void clockType::setMin(int m) {
    min = m;
}

void clockType::setSec(int s) {
    sec = s; 
}


#endif 