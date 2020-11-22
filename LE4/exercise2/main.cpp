#include <iostream>
#include "vector"
#include "random"
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

/*
§ Implement a function findIf(Iterator iter, Matcher matcher) in Java
    that finds the first element in the sequence defined by iter.
    Matcher is an interface with a single method match return true if
    the element matches.
§ Implement in a separate Java file a benchmark that executes the
        above on a Vector with several millions of elements.
§ Implement the same benchmark in C++ with the C++ find_if
        method and, e.g., lambdas.
§ Try to optimize BOTH (Java and C++) solutions.  However, the
        matcher and the elements stored in the container shall be generic.
*/

template<class T>
class Matcher {
private:
    T element;

public:
    Matcher(T ele) : element(ele) {}

    bool match(T ele) {
        return ele == element;
    }

    bool matchRef(T &ele) {
        return ele == element;
    }

    bool operator()(T &ele) const {
        return ele == element;
    }
};

template<typename T, typename F>
T findIfByValue(T iter, T end, Matcher<F> matcher) {
    while (iter != end) {
        if (matcher.match(*iter)) break;
        ++iter;
    }
    return iter;
}

template<typename T, typename F> inline
T findIfByRef(T &iter, T &end, Matcher<F> &matcher) {
    while (iter != end) {
        if (matcher.matchRef(*iter)) break;
        ++iter;
    }
    return iter;
}


//as random words to a vector, nr words of length 7
void randString(vector<string> &vec, int nr) {
    int i, j;
    string str;
    char c;
    for (i = 0; i < nr; i++) {
        for (j = 0; j < 7; j++) {
            c = rand() % 26 + 'A';
            str += c;
        }
        vec.push_back(str);
        str.clear();
    }
}


int main() {

    cout << "...";
    vector<string> v1;
    randString(v1, 1000000);
    string word = "ABCDEFG";
    cout << "generated strings" << endl;

    auto begin = v1.begin();
    auto end = v1.end();
    Matcher<string> matcher(word);

    //by find_if and Lambda
    begin = v1.begin();
    end = v1.end();
    string obj = word;
    auto startL = high_resolution_clock::now();
    auto foundL = find_if(begin, end, [&obj](const auto &ele) { return ele == obj; });
    auto stopL = high_resolution_clock::now();
    auto durationL = duration_cast<milliseconds>(stopL - startL);

    std::cout << "element found: " << (foundL != end) << std::endl;
    std::cout << "milliseconds used for find_if and lambda: " << durationL.count() << endl;

    //by find_if and matcher
    begin = v1.begin();
    end = v1.end();
    auto startF = high_resolution_clock::now();
    auto foundF = find_if(begin, end, matcher);
    auto stopF = high_resolution_clock::now();
    auto durationF = duration_cast<milliseconds>(stopF - startF);

    std::cout << "element found: " << (foundF != end) << std::endl;
    std::cout << "milliseconds used for find_if with matcher - pass by reference: " << durationF.count() << std::endl;


    //by reference
    begin = v1.begin();
    end = v1.end();
    auto startR = high_resolution_clock::now();
    auto found2 = findIfByRef(begin, end, matcher);
    auto stopR = high_resolution_clock::now();
    auto durationR = duration_cast<milliseconds>(stopR - startR);

    std::cout << "element found: "<< (found2 != end) << std::endl;
    std::cout << "milliseconds used, matcher passed by reference: " << durationR.count() << std::endl;

    /*//by Value
   auto startV = high_resolution_clock::now();
   auto found = findIfByValue(begin, end, matcher);
   auto stopV = high_resolution_clock::now();
   auto durationV = duration_cast<milliseconds>(stopV - startV);

   std::cout << "element found:" << (found != end) << std::endl;
   std::cout << "milliseconds used, matcher passed by value: " << durationV.count() << std::endl;*/
}

/*
 * 1. find_if with matcher
 * 1. ~find_if lambda
 * 3. own implementation (pass by reference)
 - matcher pass by reference probably fastest for find_if
 - find_if and lambda otherwise best
 */