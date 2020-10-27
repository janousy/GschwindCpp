/*
Upgrade your RPN calculator:
Make sure your RPN calculator runs fine with complex numbers
 - Which challenge(s) did you face? How did you solve them?
 - Note: It is sufficient to use only concepts we had discussed so far in the lecture!
*/

/*
 Challenges:
 - complex<T>, where T either float, double, or long double. How to define
 additional typename for complex type without forcing other functions to adapt?
 - basic operations are implemented for complex numbers!
 - resolve issues why not readable in file
 - You can use that only if you specialize the entire class. You can't specialize just one member function of the class.
 => use further template specialization for mymin function (inline)
 => serializer << and dezerializders >> are provided by std:complex<T>
 => another way: use inheritance and override mymin function
 */

#include <complex>
#include "pvector.h"
#include "pvector.cpp"
#include "rpn.h"
#include "rpn.cpp"

using namespace std;


int main() {
    pvector<complex<long double>> pv1("/Users/janoschbaltensperger/repos/GeschwindCpp/LE3/exercise4/pv-complex.txt");
    rpn<complex<long double>> cc1;

    pv1.print_vector();
    cc1.read_input(pv1);
}
