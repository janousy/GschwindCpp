#include "algorithm"
#include "deque"
#include "map"
#include "set"
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*
Constructs a back-insert iterator that inserts new elements at the end of x.
A back-insert iterator is a special type of output iterator designed to allow algorithms that usually overwrite
 elements (such as copy) to instead insert new elements automatically at the end of the container.
The type of x needs to have a push_back member function
 (such as the standard containers vector, deque and list).

Using the assignment operator on the returned iterator
 (either dereferenced or not), causes the container to expand by one element,
 which is initialized to the value assigned.

The returned iterator supports all other typical operations
 of output iterators but have no effect: all values assigned are inserted at the end of the container.
*/

namespace container_merge {

    template<typename itType, class C1, class C2>
    void myMerge(C1 &cont1, C2 &cont2, itType type1, itType type2) {
        auto it2_b = cont2.begin();
        auto it1_e = cont1.end();
        auto it2_e = cont2.end();
        while (it2_b != it2_e) {
            auto obj = *it2_b;
            cont1.insert(it1_e, obj);
            it1_e = cont1.end();
            ++it2_b;
        }
    }
}// namespace container_merge

template<class c1, class c2>
void myMerge(c1 &cont1, c2 &cont2) {
    typedef typename c1::iterator Iter1;
    typedef typename c2::iterator Iter2;
    Iter1 it1_b = cont1.begin();
    Iter2 it2_b = cont2.begin();
    Iter1 it1_e = cont1.end();
    Iter2 it2_e = cont2.end();
    container_merge::myMerge(cont1, cont2, typename std::iterator_traits<Iter1>::value_type(),
                             typename std::iterator_traits<Iter2>::value_type());
}

template<class c1, class c2>
c1 newMerge(c1 &cont1, c2 &cont2) {
    auto it1_b = cont1.begin();
    auto it2_b = cont2.begin();
    auto it1_e = cont1.end();
    auto it2_e = cont2.end();
    c1 cont3;

    merge(it1_b, it1_e, it2_b, it2_e, back_inserter(cont3));
    return cont3;
}

/* added functionality in comparison to my old version:
 - two sorted containers into one sorted container (by less than operator
 - merge list that contain different types as there exists a type conversion between the items:
    works for:
    [int, char, float, double]
 - cannot merge maps (push_back required)
*/

int main(int argc, char *argv[]) {

    //deque and list of different types
    list<int> l = {1, 3};
    deque<char> dq = {'s', 'd'};

    cout << "merging a list<int> with a deque<char> " << endl;
    auto c = newMerge(l, dq);
    for (auto i : c) {
        cout << i << " ";
    }
    cout << endl;

    list<int> l2 = {1, 3};
    vector<float> v3 = {4.01, 5.61};
    cout << "merging a list<int> with a vector<float>" << endl;
    c = newMerge(l2, v3);
    for (auto i : c) {
        cout << i << " ";
    }
    cout << endl;

    //maps of different types doesnt work, for new and old implementation
    map<int, int> map1;
    // insert elements in random order
    map1.insert(pair<int, int>(1, 100));
    map1.insert(pair<int, int>(5, 30));
    map1.insert(pair<int, int>(6, 60));

    map<int, int> map2;
    // insert elements in random order
    map2.insert(pair<int, int>(7, 90));
    map2.insert(pair<int, int>(8, 50));

    cout << "merging a map<int> with a map<int>" << endl;
    //myMerge(map1, map2);
    //map1 = newMerge(map1,map2);
    for(auto it = map1.cbegin(); it != map1.cend(); ++it)
    {
        std::cout << it->first << " " << it->second << " ";
    }
    cout << endl;

    //map and list doesnt work
    // no known conversion for argument 1 from 'int' to 'const value_type&' {aka 'const std::pair<const int, int>&'}
    //auto c3 = newMerge(map1,l);
}