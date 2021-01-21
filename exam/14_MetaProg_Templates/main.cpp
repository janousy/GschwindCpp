#include <iostream>
// Eucliden Algorithm explanation
// https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/the-euclidean-algorithm
// is based on this properties:
// GCD(A,0) = A, GCD(0,B) = B
// If A = B⋅Q + R and B≠0 then GCD(A,B) = GCD(B,R) where Q is an integer, R is an integer between 0 and B-1

#include <iostream>
#include<cmath>
using namespace std;

//GCD ---------
template<int a, int b>
struct GCD {
    static const int RESULT = GCD<b, a % b>::RESULT;
};

//base case uses Property GCD(A,0) = A
template<int a>
struct GCD<a, 0> {
    static const int RESULT = a;
};
//GCD ---------


//LCM ---------
//LCM(a, b) = (a * b) / GCD(a, b)
template<int a, int b>
struct LCM {
    static const int RESULT = (a*b) / GCD<b, a % b>::RESULT;
};
//LCM ---------


//Potenz --------
template<int B, unsigned int E>
struct potenz {
    static const int value = B * potenz<B, E - 1>::value;
};

template<int B>
struct potenz<B, 0> {
    static const int value = 1;
};
//Potenz --------

//Fibonacci -----
//n-th Fibonacci number
// fn= fn-1 + f_n-2  für n >= 3
// fn0 = 0, fn1 = 1
template<int n>
struct fib {
    static const int RESULT = fib<n - 1>::RESULT + fib<n - 2>::RESULT;
};

//base case for n=1
template<>
struct fib<1> {
    static const int RESULT = 1;
};

//base case for n=0
template<>
struct fib<0> {
    static const int RESULT = 0;
};
//Fibonacci -----


//Factorial
template<int n>
struct fac {
    static const int RESULT = n * fac<n-1>::RESULT;
};

//base case for n=1
template<>
struct fac<1> {
    static const int RESULT = 1;
};

//base case for n=0
template<>
struct fac<0> {
    static const int RESULT = 1;
};
//Factorial

// DEC-BIN
//decimal to binary
template<int nr>
struct DecToBinary {
    static const long RESULT = 10* DecToBinary<(nr / 2)>::RESULT + (nr%2);
};

//base case for nr=0
template<>
struct DecToBinary<0> {
    static const long RESULT = 0;
};


//binary to decimal
/*
 *int temp = 1010;
  int last_digit = temp % 10;  gets last digit
  temp = temp / 10;  removes last digit
  starting 0 is a problem
 */
template<long int nr, int s=0>
struct binToDec {
    static const int RESULT = (nr % 10)*pow(2, s) + binToDec<nr /10, s+1>::RESULT;
};

//base case for nr=1
template<int s>
struct binToDec<1, s> {
    static const int RESULT = pow(2, s);
};

//base case for nr=0
template<int s>
struct binToDec<0, s> {
    static const int RESULT = 0;
};

constexpr int binToDecC(long int n, int s=0) {
    return (n == 0) ? 0 : (n == 1) ? pow(2, s) : (n % 10)*pow(2, s) + binToDecC(n/10, s+1);
}
// DEC-BIN

int main(int argc, char **argv) {
    std::cout << "GCD (90,81) = " << GCD<90, 81>::RESULT << std::endl;
    std::cout << "GCD (90,81) = " << std::gcd(90, 81) << std::endl;
    std::cout << "LCM (3,15) = " << LCM<3,5>::RESULT  << std::endl;
    std:: cout << potenz<10, 3>::value;

    std::cout << "fib(4) == " << fib<4>::RESULT << std::endl; //should be 3: fib(3)=2 + fib(2)=1
    constexpr int resFib = fibC(4);
    std::cout << "fib(4) == " << resFib << std::endl;

    cout << "fatorial of 4 " <<  fac<4>::RESULT << endl;
    cout << "fatorial of 4 " << facC(1) << endl;

    cout << DecToBinary<101588>::RESULT << endl;
    cout << DecToBinaryC(101588) << endl;

    cout << binToDec<101001101010>::RESULT << endl;
    cout << binToDecC(101001101010) << endl;
}


//meta programing
//https://tismith.id.au/2014/template-metaprogramming-fun.html


//meta programing
//https://tismith.id.au/2014/template-metaprogramming-fun.html