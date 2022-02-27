// Contracted.cpp implementation file
#include "Contracted.h"
#include <sstream>
#include <iomanip>
using std::ostringstream;
using std::setprecision;
using std::fixed;

// initializes base-class ctor and this object's private data member
Contracted::Contracted( const string &title, double contractRate, double contractQuantity )
    : Job( title ), m_contractRate( contractRate ), m_contractQuantity( contractQuantity ) {}

// overrides base-class virtual member function to return this object's earnings
double Contracted::earnings() const {
    return m_contractRate * m_contractQuantity;
}

// overrides base-class virtual member function to return string that displays info about this object
string Contracted::toString() const {
    ostringstream outputString; // instantiates ostringstream object
    outputString << setprecision ( 2 ) << fixed // formats numeric output to hundredth decimal place
                 << getTitle() // accesses base-class private data member via base-class member function
                 << " with an average contract of $"
                 << m_contractRate
                 << " and "
                 << m_contractQuantity
                 << " contracts has earnings of $"
                 << earnings();

    return outputString.str(); // returns string contents of ostringstream object
}
