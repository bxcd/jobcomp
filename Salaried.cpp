// Salaried.cpp implementation file
#include "Salaried.h"
#include <sstream>
#include <iomanip>
using std::ostringstream;
using std::setprecision;
using std::fixed;

// initializes base-class ctor and this object's private data member
Salaried::Salaried( const string& title, double annualRate, double timeSpan, double totalBonus )
    : Job( title ), m_annualRate( annualRate ), m_timeSpan( timeSpan ), m_totalBonus( totalBonus ) {}

// overrides base-class virtual member function to return this object's earnings
double Salaried::earnings() const {
    return m_annualRate * m_timeSpan + m_totalBonus;
}

// overrides base-class virtual member function to return string that displays info about this object
string Salaried::toString() const {
    ostringstream outputString; // instantiates ostringstream object
    outputString << setprecision ( 2 ) << fixed // formats numeric output to hundredth decimal place
                 << getTitle() // accesses base-class private data member via base-class member function
                 << " with a salary of $"
                 << m_annualRate
                 << " for "
                 << m_timeSpan
                 << " years with bonuses totaling $"
                 << m_totalBonus
                 << " has earnings of $"
                 << earnings();

    return outputString.str(); // returns string contents of ostringstream object
}
