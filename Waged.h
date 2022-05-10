// Waged.h header file
#ifndef WAGED_H
#define WAGED_H
#include "Job.h"

// derived-class inherits base-class Job
class Waged : public Job {
public:
    Waged(const string&, double, double, double, double); // ctor
    virtual double earnings() const; // calculates and returns this object's earnings
    virtual string toString() const; // returns string containing info about this object
private:
    double m_weeklyHours; // private data member for storing this object's weekly hours
    double m_hourlyRate; // private data member for storing this object's hourly rate
    double m_timeSpan; // private data member for storing this object's time span
    double m_totalOvertime; // private data member for storing this object's total overtime
};

#endif // WAGED_H
