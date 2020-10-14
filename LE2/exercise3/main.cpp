/*
Upgrade your RPN calculator
• Change your implementation into a template such that RPN<T>() will create your RPN calculator to work with type T; ensure you can use int, double,
    fraction as type T
• Make use of your pvector class to store the numbers the user pushes onto
        the stack persistently (i.e., when you terminate your calculator with
        numbers on the stack that they reappear when you restart it)
• Make use of separate compilation in combination with a Makefile

*/

#include "fraction.h"
#include "pvector.h"
#include "pvector.cpp"
#include "rpn.h"
#include "rpn.cpp"

using namespace std;


//reading from file and writing to file is disabled!
int main() {
    pvector<int> pv1("/Users/janoschbaltensperger/repos/GeschwindCpp/LE2/exercise3/pv-int.txt");
    pvector<double> pv2("/Users/janoschbaltensperger/repos/GeschwindCpp/LE2/exercise3/pv-double.txt");
    pvector<fraction> pv3("/Users/janoschbaltensperger/repos/GeschwindCpp/LE2/exercise3/pv-fraction.txt");

    rpn<int> cc1;
    rpn<double> cc2;
    rpn<fraction> cc3;

    cc1.divide(pv1);
    cc2.add(pv2);
    cc3.mult(pv3);


    /*  pv1.push_back(2);
      pv1.push_back(1);
      pv1.print_vector();
      cc1.subtract(pv1);
      pv1.print_vector();

      pv2.push_back(2.2);
      pv2.push_back(3.2);
      pv2.print_vector();
      cc2.add(pv2);
      pv2.print_vector();

      fraction f1(2, 3);
      fraction f2(1, 3);
      pv3.push_back(f1);
      pv3.push_back(f2);
      pv3.print_vector();
      cc3.mult(pv3);
      pv3.print_vector();*/
}
