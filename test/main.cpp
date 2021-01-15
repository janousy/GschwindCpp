#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a = 3;
    int b = 5;
    int &pa = a;
    cout << pa;
    pa = b;
    cout << pa;
}
