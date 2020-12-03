#include <iostream>
#include <complex.h>
#include "pvector.h"
#include "pvector.cpp"

using namespace std;

int main() {
    try {
        pvector<complex<float>> pv1("/Users/janoschbaltensperger/repos/GeschwindCpp/LE6/exercise2/pv-complex.txt");
        pv1.push_back((2.3, 5.6));
    } catch (exception e) {
        cout << "unable to init pvector";
    }

    return 0;
}

/*
Implement a small class such as the DBLocker class
 - Instead, it is called FileLocker to lock a file
    you do not actually have to lock the file, sufficient to print
    standard out that the file is now “locked”, respectively “unlocked
- If you really want to lock the file, see man 2 flock on Unix(-like) systems
- Use that class in your RPN calculator or pvector class for the file of
        the persistent vector § What are the benefits
        of this class over a vanilla finally handler?
*/
