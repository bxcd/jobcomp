// Job.cpp implementation file
#include "Job.h"

// initializes this object's private data member
Job::Job( const string &title )
    : m_title( title ) {}

// returns this object's title
string Job::getTitle() const {
    return m_title;
}
