#include <regex>
#include <iostream>
#include "vector"

using namespace std;
#pragma once
#include <iostream>
template<typename T>
T mymin(T a, T b) {
    std::cout << " templated" << std::endl;
    return a < b ? a : b;
}
char* mymin(char* a, char* b) {
    std::cout << "non templated, non const" << std::endl;
    return strcmp(a, b) < 0 ? a : b;
}
const char* mymin(const char* a, const char* b) {
    std::cout << "non templated, const" << std::endl;
    return strcmp(a, b) < 0 ? a : b;
}

int main() {
    char a = 'a';
    const char b = 'b';
    char *x = &a;
    char *y = &a;
    const char *z = &b;
    cout << mymin(x, y) << endl; //char*
    cout << mymin(x, z) << endl; // cgar*
    cout << mymin<const char *>(x, z) << endl;   // gives a compilation error (according to your notes it shouldn't
}