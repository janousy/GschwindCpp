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
 => use template specialization for mymin function
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

    complex<long double> c1(6.12234134, 324.2312341324);
    complex<long double> c2(1.2312341324, 2.231234143);

    pv1.push_back(c1);
    pv1.push_back(c2);
    pv1.print_vector();

    cc1.mymin(pv1);
    pv1.print_vector();
}
