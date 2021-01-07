#include "pvector.h"
#include "pvector.cpp"
#include "pset.h"
#include "pset.cpp"

using namespace std;

int main() {
    pvector<double> pv1("/Users/janoschbaltensperger/repos/GeschwindCpp/LE3/exercise2/pv-double.txt");
    pv1.print_vector();
    pv1.push_back(3.1);
    pv1.print_vector();

    pset<int> ps1("/Users/janoschbaltensperger/repos/GeschwindCpp/LE3/exercise2/ps-int.txt");
    ps1.print_set();
    ps1.insert(9);
    ps1.print_set();
}
