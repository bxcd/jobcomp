// Job.h header file
#ifndef JOB_H
#define JOB_H
#include <string>
using std::string;

class Job {
public:
    explicit Job( const string& ); // ctor rejects implicit conversions
    string getTitle() const; // returns this object's title
    virtual double earnings() const = 0; // pure virtual function relies upon derived-class implementations
    virtual string toString() const = 0; // pure virtual function relies upon derived-class implementations
    virtual ~Job() {}; // dtor checks for derived-class dtor implementations
private:
    string m_title; // private data member for storing this object's title
};

#endif // JOB_H
