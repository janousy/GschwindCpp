#include <iostream>
// Eucliden Algorithm explanation
// https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/the-euclidean-algorithm
// is based on this properties:
// GCD(A,0) = A, GCD(0,B) = B
// If A = B⋅Q + R and B≠0 then GCD(A,B) = GCD(B,R) where Q is an integer, R is an integer between 0 and B-1

// => GCD(A,B) = GCD(B, A%B)
// if a<b it first switches the parameters: GCD<A,B> => GCD<B,A>
template<int a, int b>
struct GCD {
    static const int RESULT = GCD<b, a % b>::RESULT;
};

//base case uses Property GCD(A,0) = A
template<int a>
struct GCD<a, 0> {
    static const int RESULT = a;
};

//possible to evaluate the value of the function or variable at compile time.
constexpr int gcd(int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

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

// short if: (condition)? true: false;
//nested 2 short ifs into each other
constexpr int fibC(int n) {
    return (n == 0) ? 0 : (n == 1) ? 1 : fibC(n - 1) + fibC(n - 2);
}

int main(int argc, char **argv) {
    std::cout << "GCD (90,81) = " << GCD<90, 81>::RESULT << std::endl;
    int res = gcd(90, 81);
    std::cout << "GCD (90,81) = " << res << std::endl;

    std::cout << "fib(4) == " << fib<4>::RESULT << std::endl; //should be 3: fib(3)=2 + fib(2)=1
    int resFib = fibC(4);
    std::cout << "fib(4) == " << resFib << std::endl;
}


//meta programing
//https://tismith.id.au/2014/template-metaprogramming-fun.html