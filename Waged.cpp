// Waged.cpp implementation file
#include "Waged.h"
#include <sstream>
#include <iomanip>
using std::ostringstream;
using std::setprecision;
using std::fixed;

// initializes base-class ctor and this object's private data member
Waged::Waged(const string &title, double weeklyHours, double hourlyRate, double timeSpan, double totalOvertime)
    : Job(title),  m_weeklyHours(weeklyHours), m_hourlyRate(hourlyRate), m_timeSpan(timeSpan), m_totalOvertime(totalOvertime) {}

// overrides base-class virtual member function to return this object's earnings
double Waged::earnings() const {
    return (52.0 * m_weeklyHours * m_hourlyRate) * m_timeSpan + m_totalOvertime;
}

// overrides base-class virtual member function to return string that displays info about this object
string Waged::toString() const {
    ostringstream outputString; // instantiates ostringstream object
    outputString << setprecision (2) << fixed // formats numeric output to hundredth decimal place
                 << getTitle() // accesses base-class private data member via base-class member function
                 << " with wage of $"
                 << m_hourlyRate
                 << " at "
                 << m_weeklyHours
                 << " hours/week for "
                 << m_timeSpan
                 << " years and overtime totaling $"
                 << m_totalOvertime
                 << " has earnings of $"
                 << earnings();

    return outputString.str(); // returns string contents of ostringstream object
}
