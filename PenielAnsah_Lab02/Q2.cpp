#include <iostream>
#include <string>
using namespace std;

class clockType {
    public:
        void setHr(int );
        void setMin(int );
        void setSec(int );
        int getHr() const {
            return hr;
        };
        int getMin() const {
            return min;
        };
        int getSec() const{
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

int main(){
    int hours;
    int minutes;
    int seconds;
    cout << "Please enter the number of hours from 0 to 23: ";
    cin >> hours;
    while (!(hours >= 0 && hours <=23)){
        cout << "The hours provided is invalid. It should be from 0 to 23\nPlease enter the number of hours again: ";
        cin >> hours;
    }
    cout << "Please enter the number of minutes from 0 to 59: ";
    cin >> minutes;
    while (!(minutes >= 0 && minutes <=59)){
        cout << "The minutes provided is invalid. It should be from 0 to 59\nPlease enter the number of minutes again: ";
        cin >> minutes;
    }

    cout << "Please enter the number of seconds from 0 to 59: ";
    cin >> seconds;
    while (!(seconds >= 0 && seconds <=59)){
        cout << "The seconds provided is invalid. It should be from 0 to 59\nPlease enter the number of seconds again: ";
        cin >> seconds;
    }

    clockType myClock = clockType();

    // Set time values
    myClock.setHr(hours);
    myClock.setMin(minutes);
    myClock.setSec(seconds);

    cout << "The time is: "  << myClock.getHr() << ":"<< myClock.getMin() << ":" << myClock.getSec();
}
