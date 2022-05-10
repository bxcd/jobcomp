 // strtoupper.cpp source file
#include <cstring>
#include <string>
using std::toupper;
using std::string;

// converts ASCI string to uppercase
string strtoupper(string str) {
    for (int loopCount = 0; str[ loopCount ]; ++loopCount) {
        str[ loopCount ] = toupper(str[ loopCount ]);
    }
    return str;
}
