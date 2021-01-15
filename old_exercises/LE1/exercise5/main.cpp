#include <iostream>
using namespace std;

/*
Which functions cannot be inlined?
 - Implement a program that shows such a function.
 § Verify your claim by looking at the compiler-generated assembly code (no need to understand all the assembly code, only whether
    your function was inlined or not)

Useful compiler options
• -O0 asks the compiler to not optimize the output (compiler probably does not inline functions (by itself))
• -O3 asks the compiler to apply almost all optimizations (compiler likely will inline functions not marked as such)
• -S asks the compiler to generate assembly code only
 */

inline void display(int number) {
    cout << number << endl;
}

int main() {
    display(10);
    return 0;
}
