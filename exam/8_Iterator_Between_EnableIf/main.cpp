#include <iostream>
#include <iostream>
#include "vector"
#include "set"

using namespace std;

/*
Reimplement our distance function that used dynamic algorithm
    selection with the enable_if feature we have seen in this lecture
Hint: If you use the using directives from a previous slide life gets easier and
the code more readable
*/

/*
 => readability gets a bit more complex
 => no more in need of dispatcher function (provided by enable_if)
*/


//type alias declaration
template<typename I> using IteratorCategoryOf =
typename std::iterator_traits<I>::iterator_category;

template<typename I> using IsRandomAccessIterator =
std::is_base_of<std::random_access_iterator_tag,
        IteratorCategoryOf<I>>;


template<typename I>
typename enable_if<IsRandomAccessIterator<I>::value, bool>::type
between(I fst, I lst, I it) {
    std::cout << "called for random-access iterator\n";
    return fst < it && it < lst;
}

template<typename I>
typename enable_if<!IsRandomAccessIterator<I>::value, bool>::type
between(I fst, I lst, I it) {
    std::cout << "called for general iterator\n";
    while (fst != lst) {
        if (fst == it) {
            return true;
        }
        fst++;
    }
    return false;
}


int main() {
    bool is_between;

    cout << std::boolalpha << IsRandomAccessIterator<set<int>::iterator>::value << endl;
    cout << std::boolalpha << IsRandomAccessIterator<vector<int>::iterator>::value << endl;

    /* bi-directional iterator */
    set<int> s{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
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

    return 0;
}

// ------------------------------------
//PREVIOUS IMPLEMENTATION:

/*template<class Iter>
bool between(Iter fst, Iter lst, Iter it, input_iterator_tag) {
    std::cout << "called for general iterator\n";
    while (fst != lst) {
        if (fst == it) {
            return true;
        }
        fst++;
    }
    return false;
}

template<class RAIter>
bool between(RAIter fst, RAIter lst, RAIter it, random_access_iterator_tag) {
    std::cout << "called for random-access iterator\n";
    if (fst < it && it < lst) {
        return true;
    } else {
        return false;
    }
}*/

/*
- The type T is enabled as member type enable_if::type if Cond is true.
- Otherwise, enable_if::type is not defined.

This is useful to hide signatures on compile time when a particular condition is not met,
 since in this case, the member enable_if::type will not be defined and attempting to compile using it should fail.
*/
