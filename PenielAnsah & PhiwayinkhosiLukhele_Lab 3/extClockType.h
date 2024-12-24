#ifndef EXTCLOCKTYPE_H   
#define EXTCLOCKTYPE_H   
#include <iostream>
#include <string>
#include "clockType.h"
using namespace std;

class extClockType : public clockType {
public:
    extClockType(int hours, int minutes, int seconds, string timeZone);

    void setTimeZone(string timeZone);

    string getTimeZone() const;

    void printTime() const;

private:
    string timeZone;  
};

extClockType::extClockType(int hours, int minutes, int seconds, string tz) {
    setHr(hours);
    setMin(minutes);
    setSec(seconds);
    timeZone = tz;
}

void extClockType::setTimeZone(string tz) {
    timeZone = tz;
}

string extClockType::getTimeZone() const {
    return timeZone;
}

void extClockType::printTime() const {
    cout << "Time: " << getHr() << ":" << getMin() << ":" << getSec();
    cout << " " << timeZone << endl;
}

#endif