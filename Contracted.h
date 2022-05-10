// Contracted.h header file
#ifndef CONTRACTED_H
#define CONTRACTED_H
#include "Job.h"

// derived-class inherits base-class Job
class Contracted : public Job {
public:
    Contracted(const string&, double, double); // ctor
    virtual double earnings() const; // calculates and returns this object's earnings
    virtual string toString() const; // returns string containing info about this object
private:
    double m_contractRate; // private data member for storing this object's contract rate
    double m_contractQuantity; // private data member for storing this object's contract quantity
};

#endif // CONTRACTED_H
