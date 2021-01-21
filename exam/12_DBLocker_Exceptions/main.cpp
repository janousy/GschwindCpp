#include <iostream>
#include <complex.h>
#include "pvector.h"

using namespace std;

int main() {
    try {
        pvector<complex<float>> pv2("/Users/janoschbaltensperger/repos/GeschwindCpp/exam/12_DBLOcker_Exceptions/pv-complex.txt");
    } catch (...) {
        // catch all exceptions
        cout << "unable to init pvector since we cant acquire lock";
    }
    return 0;
}

/*
Advantages (no finally in C++, leave scope -> deterministic call of destructors)
- other languages require finally block to free resource, easily forgotten

- I always have to write the finally block, otherwise I leak resources. Which can be easily forgotten (e.g. crash but file still locked)
- If I have several resources that need to be acquired then freed in an exception-safe manner,
    I can end up with several layers deep of try / finally blocks
    (If the error is passed multiple times I would need a try catch block in each class, to deconstruct the object of the class that passed the error to me)
- cleanup code in the destructor of the relevant class, therefore can be reused if dont have to define in multipe try catch blocks of diffrent classes
    e.g. I would have to know how to unlock the filelocker

Disadvantages:
- It involves creating an extra local variable, because the one in the try catch block gets destroyed when leaving it
- If we want to exclude the manipulation of the pvector outside of the try block, we had to change the pvector class and add operator=
*/

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
