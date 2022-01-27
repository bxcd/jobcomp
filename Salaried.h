// Salaried.h header file
#ifndef SALARIED_H
#define SALARIED_H
#include "Job.h"

// derived-class inherits base-class Job
class Salaried : public Job {
public:
    Salaried( const string&, double, double, double ); // ctor
    virtual double earnings() const; // calculates and returns this object's earnings
    virtual string toString() const; // returns string containing info about this object
private:
    double m_annualRate; // private data member for storing this object's annual rate
    double m_timeSpan; // private data member for storing this object's time span
    double m_totalBonus; // private data member for storing this object's total bonus
};

#endif // SALARIED_H
