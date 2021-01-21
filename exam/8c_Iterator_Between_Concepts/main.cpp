
#include <iostream>
#include <string>
#include "concepts"
#include "vector"
#include "set"

using namespace std;

template<typename T>
concept Comparable = requires (T x) { x < x; };



template<typename Iter>
bool between(Iter fst, Iter lst, Iter it) {
    std::cout << "called for general iterator\n";
    while(fst != lst) {
        if(fst == it) {
            return true;
        }
        fst++;
    }
    return false;
}

template<Comparable RAIter>
bool between(RAIter fst, RAIter lst, RAIter it) {
    std::cout << "called for random-access iterator\n";
    if (fst < it && it < lst) {
        return true;
    } else {
        return false;
    }
}

/* or to replace above
template<typename RAIter>
bool between(RAIter fst, RAIter lst, RAIter it) requires Comparable<RAIter>  {
  std::cout << "called for random-access iterator\n";
  if (fst < it && it < lst) {
    return true;
  } else {
    return false;
  }
}
*/

int main() {
    bool is_between;

    set<int> s {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    set<int>::iterator it1 = s.begin();
    for (int i = 0; i < 4; i++) {
        it1++;
    }
    cout << "*it1: " << *it1 << endl;
    is_between = between(s.begin(), it1, s.end());
    cout << std::boolalpha << is_between << endl;

    /* random access iterator */
    vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int>::iterator it2 = v.begin();
    for (int i = 0; i < 5; i++) {
        it2++;
    }
    cout << "*it2: " << *it2 << endl;
    is_between = between(v.begin(), v.end(), it2);
    cout << std::boolalpha << is_between << endl;

    is_between = between(v.begin(), it2, v.end());
    cout << std::boolalpha << is_between << endl;

    return 0;
}