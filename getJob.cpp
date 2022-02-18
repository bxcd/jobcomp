// getJob.cpp source file
#include "Contracted.h"
#include "Salaried.h"
#include "Waged.h"
#include <iostream>
#include <limits>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::numeric_limits;
using std::streamsize;

string strtoupper( string ); // function declaration links getJob.cpp to strtoupper.cpp

// returns pointer to job object instantiated in heap
Job* getJob() {
	Job* pJob = 0; // initializes pointer to null by default
	string title, job; // instantiates string objects for storing user inputs
  const string errorMsg = "Try inputting numbers (whole or decimal) only.\n";

	// prompts user for input and passes user input to string object
	cout << "\nEnter the job's title (or 'done')..." << endl;
	getline( cin, title );
	// checks if user wants to stop getting jobs
	if ( strtoupper( title ) == "DONE" ) {
		return pJob; // returns null pointer to end array of pointers to job objects
	}
    // iterates until an object is returned
    while ( 1 ) {
        // prompts user for input and passes user input to string object
        cout << "Enter job type..." << endl;
        cin >> job;
        cin.ignore( numeric_limits< streamsize >::max(), '\n' ); // discards space and subsequent inputs
        // checks if user entered valid job, instantiates a new object and returns pointer to object
        if ( strtoupper( job ) == "CONTRACTED" ) {
            double contractRate; // declares double variable for storing contract rate
						double contractQuantity; // declares double variable for storing contract quantity
            // validates, or otherwise, rejects and repeats, input
            while ( ( cout << "Enter the average contract amount..." << endl ) && !( cin >> contractRate ) ) {
                cin.clear(); // clears bad input flag
                cin.ignore( numeric_limits< streamsize >::max(), '\n' ); // discards input
                cout << "You did not enter a valid average contract amount." + errorMsg;
            }
						while ( ( cout << "Enter the number of contracts..." << endl ) && !( cin >> contractQuantity ) ) {
                cin.clear(); // clears bad input flag
                cin.ignore( numeric_limits< streamsize >::max(), '\n' ); // discards input
                cout << "You did not enter a valid number of contracts." + errorMsg;
            }
            cin.ignore( numeric_limits< streamsize >::max(), '\n' ); // discards space and subsequent inputs
            pJob = new Contracted( title, contractRate, contractQuantity ); // instantiates new job object in heap
            return pJob; // returns pointer to job object
        }
        // checks if user entered valid job, instantiates a new object and returns pointer to object
        else if ( strtoupper( job ) == "SALARIED" ) {
						double annualRate; // declares double variable for storing annual rate
						double timeSpan; // declares double variable for storing time span
						double totalBonus; // declares double variable for storing total bonus
            // validates, or otherwise, rejects and repeats, input
            while ( ( cout << "Enter the salary..." << endl ) && !( cin >> annualRate ) ) {
                cin.clear(); // clears bad input flag
                cin.ignore( numeric_limits< streamsize >::max(), '\n' ); // discards input
                cout << "You did not enter a valid salary." + errorMsg;
            }
						while ( ( cout << "Enter the number of years..." << endl ) && !( cin >> timeSpan ) ) {
                cin.clear(); // clears bad input flag
                cin.ignore( numeric_limits< streamsize >::max(), '\n' ); // discards input
                cout << "You did not enter a valid number of years." + errorMsg;
            }
						while ( ( cout << "Enter the aggregate bonus amount..." << endl ) && !( cin >> totalBonus ) ) {
                cin.clear(); // clears bad input flag
                cin.ignore( numeric_limits< streamsize >::max(), '\n' ); // discards input
                cout << "You did not enter a valid aggregate bonus amount." + errorMsg;
            }
            cin.ignore( numeric_limits< streamsize >::max(), '\n' ); // discards space and subsequent inputs
            pJob = new Salaried( title, annualRate, timeSpan, totalBonus ); // instantiates new job object in heap
            return pJob; // returns pointer to job object
        }
        // checks if user entered valid job, instantiates a new object and returns pointer to object
        else if ( strtoupper( job ) == "WAGED" ) {
						double weeklyHours; // declares double variable for storing weekly hours
						double hourlyRate; // declares double variable for storing annual rate
						double timeSpan; // declares double variable for storing time span
						double totalOvertime; // declares double variable for storing total bonus
            // validates, or otherwise, rejects and repeats, input
						while ( ( cout << "Enter the wage..." << endl ) && !( cin >> hourlyRate ) ) {
								cin.clear(); // clears bad input flag
								cin.ignore( numeric_limits< streamsize >::max(), '\n' ); // discards input
								cout << "You did not enter a valid wage." + errorMsg;
						}
            while ( ( cout << "Enter the number of weekly hours..." << endl ) && !( cin >> weeklyHours ) ) {
                cin.clear(); // clears bad input flag
                cin.ignore( numeric_limits< streamsize >::max(), '\n' ); // discards input
                cout << "You did not enter a valid number of weekly hours." + errorMsg;
            }
						while ( ( cout << "Enter the number of years..." << endl ) && !( cin >> timeSpan ) ) {
                cin.clear(); // clears bad input flag
                cin.ignore( numeric_limits< streamsize >::max(), '\n' ); // discards input
                cout << "You did not enter a valid number of years." + errorMsg;
            }
						while ( ( cout << "Enter the aggregate overtime pay..." << endl ) && !( cin >> totalOvertime ) ) {
                cin.clear(); // clears bad input flag
                cin.ignore( numeric_limits< streamsize >::max(), '\n' ); // discards input
                cout << "You did not enter a valid aggregate overtime pay." + errorMsg;
            }
            cin.ignore( numeric_limits< streamsize >::max(), '\n' ); // discards space and subsequent inputs
            pJob = new Waged( title, weeklyHours, hourlyRate, timeSpan, totalOvertime ); // instantiates new job object in heap
            return pJob; // returns pointer to job object
        }
        // rejects and repeats input
        cout << "You did not enter a valid job type.  Choices are: contracted; salaried; waged.  Try again." << endl;
    }
}
