// main.cpp test program
#include "Job.h"
#include <vector>
#include <iostream>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

Job* getJob(); // function declaration links main.cpp to getJob.cpp

int main() {
    int loopCount = -1; // counts number of loop iterations
    vector< Job* > pJob; // declares a template class of Job pointers from vector class template

    cout << "Enter a list of jobs" << endl;
    do { // iterates before checking condition
        ++loopCount; // increments loop counter whose value is index of current array position
        pJob.insert(pJob.end(), getJob()); // assigns to Job pointer the job returned by get function
    } while (pJob[ loopCount ]); // repeat loop so long as Job pointer at current array position is non-void

    cout << "\nThe list of jobs entered..." << endl;
    // iterates so long as Job pointer at current array position is non-void
    for (loopCount = 0; pJob[ loopCount ]; ++loopCount) {
        cout << "  " << pJob[ loopCount ]->toString() << endl; // outputs list of jobs targeted by pointer array
    }

    cout << "\nSorting jobs into order by earnings..." << endl;
    int passCount = 0; // counts number of times sort loop iterates
    bool passRepeat = 1; // sets bool to true
    // iterates so long as bool is true and Job pointer at index 0 is non-void
    for (loopCount = 0; passRepeat && pJob[ loopCount ]; ++passCount, loopCount = 0) {
        passRepeat = 0; // sets bool to false
        Job* temp; // instantiates temp Job pointer
        while (pJob [ loopCount + 1 ]) { // iterates so long as Job pointer at next array position is non-void
            // checks if value targeted by Job pointer at current position is greater than that of next position
            if (pJob[ loopCount ]->earnings() < pJob[ loopCount + 1 ]->earnings()) {
                temp = pJob[ loopCount + 1 ]; // assigns value targeted by Job pointer at next position to temp
                pJob[ loopCount + 1 ] = pJob[ loopCount ]; // replaces values targeted at next with those at current position
                pJob[ loopCount ] = temp; // replaces values targeted at current with those at next position
                ++passRepeat; // sets bool to true to trigger another sort pass upon completion of the current pass
            }
            ++loopCount; // increments loop counter whose value is index of current array position
        }
    }
    cout << "Sorting completed - " << passCount << " sort passes required" << endl; // indicates number of completed sort passes

    cout << "\nThe sorted list of jobs..." << endl;
    // iterates so long as Job pointer at current array position is non-void
    for (loopCount = 0; pJob[ loopCount ]; ++loopCount) {
        cout << "  " << pJob[ loopCount ]->toString() << endl; // outputs list of jobs targeted by pointer array
    }
    // iterates so long as Job pointer at current array position is non-void
    for (loopCount = 0; pJob[ loopCount ]; ++loopCount) {
        delete pJob[ loopCount ]; // free heap memory targeted by pointer array
    }

    return 0;
}
