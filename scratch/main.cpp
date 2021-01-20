#include <regex>
#include <iostream>
#include "vector"

using namespace std;



int main() {
    vector<int> v1;
    v1.push_back(1);
    vector<int> * const vp = &v1;
    vp->push_back(2);
}