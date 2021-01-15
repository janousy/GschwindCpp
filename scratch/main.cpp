//the above example very much shortened!
#include "iostream"
using namespace std;
template<int P, int N> struct isprime2 {
    static const int res=isprime2<P,P%N?N-1:0>::res;
    //shorthand if: expression? trueCase: falseCase
    //above:  true if P%N >= 1, false if 0
};

//base case for prime
template<int P> struct isprime2<P, 1> {
    static const int res=1;
};
//base case for not prime
template<int P> struct isprime2<P, 0> {
    static const int res=0;
};
template<int P> struct isprime {
    static const int res=isprime2<P, P/2>::res;
};

int main() {
cout << isprime<3>::res << endl;
}