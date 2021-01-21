#include <iostream>
using namespace std;

//greatest common divisor
constexpr int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

//fibonacci
constexpr int fibC(int n) {
    if(n == 0){return 0;}
    else if(n == 1){return 1;}
    else{return fibC(n-1) + fibC(n-2);}
}

//factorial
constexpr int facC(int n) {
    return (n<1)? 1: n* facC(n-1);
}

//lowest common multiple, lcm
constexpr int lcm(int a, int b) {
    return (a*b)/gcd(b, a % b);
}

constexpr long dec_to_binaryC(int nr) {
    return (nr == 0) ? 0 : (10* dec_to_binaryC(nr / 2) + (nr%2));
}

int main() {
    cout << gcd(9, 27) << endl;
    cout << fibC(9) << endl;
    cout << facC(9) << endl;
    cout << lcm(55, 45) << endl;
    cout << dec_to_binaryC(55) << endl;
    return 0;
}
