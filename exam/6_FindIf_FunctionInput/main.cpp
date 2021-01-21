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
T findIfByRef(T &begin, T &end, Matcher<F> &matcher) {
    while (begin != end) {
        if (matcher.matchRef(*begin)) break;
        ++begin;
    }
    return begin;
}

string target = "ab";

template <typename T>
bool unaryFind(T &ele) {
    return ele == target;
}

int main() {

    cout << "...";
    vector<string> v1;
    v1.push_back("ab");
    v1.push_back("ac");
    v1.push_back("ad");
    string target = "ab";

    auto begin = v1.begin();
    auto end = v1.end();

    //matcher
    Matcher<string> matcher(target);
    auto foundIf = find_if(begin, end, matcher);

    //by find_if and Lambda
    auto foundL = find_if(begin, end, [&target](const auto &ele) { return ele == target; });

    //by unary function
    auto foundU = find_if(begin, end, unaryFind<string>);

}
/*
 * 1. find_if with matcher
 * 1. ~find_if lambda
 * 3. own implementation (pass by reference)
 - matcher pass by reference probably fastest for find_if
 - find_if and lambda otherwise best
 */