#include <iostream>
using namespace std;

template<typename T>
concept Comparable = requires (T x) { x < x; };

// Using the concept “Comparable”
// Concepts specified as part of the template declaration
template<typename T> class rpn_calculator {
public:
    //specialization for comparable
    //concepts can be required after the declaration
    bool exec_min(T x, T y) requires Comparable<T> {
        //possible with adhoc concept: requires (T x) { x < x; }
        return x > y;
    }
    //fallback for non-comparable
    bool exec_min(T x, T y) {
        cerr << "not supported" << endl;
        return false;
    } //error
};

int main() {
    rpn_calculator<int> c1;
    bool larger = c1.exec_min(3,4);
    cout << larger << endl;
    return 0;
}
