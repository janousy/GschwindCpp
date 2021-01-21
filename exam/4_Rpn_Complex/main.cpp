/*
Upgrade your RPN calculator:
Make sure your RPN calculator runs fine with complex numbers
 - Which challenge(s) did you face? How did you solve them?
 - Note: It is sufficient to use only concepts we had discussed so far in the lecture!
*/

/*
 Challenges:
 - basic operations are implemented for complex numbers!
 - serializer << and dezerializders >> are provided by std:complex<T>
 - You can use that only if you specialize the entire class. You can't specialize just one member function of the class.
 => use further template specialization for mymin function (inline)
 => another way: use inheritance and override mymin function
 */

#include <complex>
#include "pvector.h"
#include "rpn.h"

using namespace std;


int main() {
    pvector<complex<int>> pv1("/Users/janoschbaltensperger/repos/GeschwindCpp/LE3/exercise3/pv-complex.txt");
    rpn<complex<int>> cc1;

    cc1.read_input(pv1);
    pv1.print_vector();
}
