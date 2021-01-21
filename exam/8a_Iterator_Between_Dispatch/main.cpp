/* https://www.youtube.com/watch?v=yTi46Pb32qg&ab_channel=code_report */
/*
Implement an algorithm bool between(Iter fst, Iter lst, Iter i)
    that determines whether iterator i lies between iterators fst and lst.
    Your algorithm may assume that fst and lst form a valid sequence.
§ Implement your algorithm such that
• for random access iterators it uses the comparison functions, and
• for other iterators, it advances fst until lst to identify whether i is inbetween
§ Ensure that the algorithm to be used can be determined statically
*/

/*
 => use tag dispatching: https://en.cppreference.com/w/cpp/iterator/iterator_tags
 => static approach: function overload and templates
 => dynamic approach: interface polymorphism
*/

#include <iostream>
#include "vector"
#include "set"

using namespace std;

namespace iter_between {
    //TODO: find general iterator tag
    template<class Iter>
    bool between(Iter fst, Iter lst, Iter it, input_iterator_tag) {
        std::cout << "called for general iterator\n";
        while(fst != lst) {
            if(fst == it) {
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
    }
}

//iterator tag dispatcher function
template<typename Iter>
bool between(Iter first, Iter last, Iter it) {
    return iter_between::between(first, last, it, typename std::iterator_traits<Iter>::iterator_category());
}

int main() {
    bool is_between;

    //TODO: jumping outside the set results in random position
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

/*
    * vector: random access
    * set: bidirectional
    * forward_list: forward iterator
    *
    * Caveat!: calling increment might result in undefined behavior
    *   because calling operator ++ for the end of a sequence is not defined
*/
