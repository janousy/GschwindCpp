#include<vector>
#include<list>
#include<iostream>
#include "map"
#include "set"
#include "deque"

using namespace std;



//used for merging vectors, list and deques
template<template<typename D, typename C> class T, template<typename D, typename E> class P, typename D, typename C, typename E>
void merge(T<D, C> &cont1, P<D, E> &cont2){
    auto begin = cont2.begin();
    auto end = cont2.end();
    auto end1 = cont1.end();
    while(begin != end){
        auto obj = *begin;
        cont1.insert(end1, obj);
        end1 = cont1.end();
        ++begin;
    }
}

//used to merge a set with a vector or a list or a deque
template<template<typename D, typename C, typename F> class T, template<typename D, typename E> class P, typename D, typename C, typename E, typename F>
void merge(T<D, C, F> &cont1, P<D, E> &cont2){
    auto begin = cont2.begin();
    auto end = cont2.end();
    auto end1 = cont1.end();
    while(begin != end){
        auto obj = *begin;
        cont1.insert(end1, obj);
        end1 = cont1.end();
        ++begin;
    }
}

//used to merge a vector or a list or a deque  with a set
template<template<typename D, typename C> class T, template<typename D, typename E, typename F> class P, typename D, typename C, typename E, typename F>
void merge(T<D, C> &cont1, P<D, E, F> &cont2){
    auto begin = cont2.begin();
    auto end = cont2.end();
    auto end1 = cont1.end();
    while(begin != end){
        auto obj = *begin;
        cont1.insert(end1, obj);
        end1 = cont1.end();
        ++begin;
    }
}

//used to merge a set with a set
template<template<typename D, typename C, typename F> class T, template<typename D, typename E, typename G> class P, typename D, typename C, typename E, typename F, typename G>
void merge(T<D, C, F> &cont1, P<D, E, G> &cont2){
    auto begin = cont2.begin();
    auto end = cont2.end();
    auto end1 = cont1.end();
    while(begin != end){
        auto obj = *begin;
        cont1.insert(end1, obj);
        end1 = cont1.end();
        ++begin;
    }
}

//used for maps, only merge if same type of key and same type of mapped obj
template<template<typename K, typename T, typename D, typename  E> class I, template<typename K, typename T, typename F, typename G> class J, typename K, typename T, typename D, typename  E, typename F, typename G>
void merge(I<K, T, D, E> &cont1, J<K, T, F, G> &cont2){
    auto begin = cont2.begin();
    auto end = cont2.end();
    auto end1 = cont1.end();
    while(begin != end){
        auto obj = *begin;
        cont1.insert(end1, obj);
        end1 = cont1.end();
        ++begin;
    }
}

template<typename T,typename P>
void merge(T cont1, P cont2){
    cout << "cant merge container that dont contain the same type of objects" << endl;

}



int main(int argc, char* argv[]) {
    list<int> l = { 1, 3 };
    deque<int> dq = {2,4};
    merge(dq, l);
    cout << "merging deque and a list resulting in deque: " << endl;
    for (auto i : dq) {
        cout << i<< endl;
    }

    list<int> l1 = { 1, 3 };
    vector<int> v2 = {2, 5};
    cout << "merging list and vector resulting in list: " << endl;
    merge(l1, v2);
    for (auto i : l1) {
        cout << i<< endl;
    }

    list<int> l2 = { 1,3 };
    vector<int> v3 = {2,5};
    cout << "merging  a vector and a list resulting in vector: " << endl;
    merge(v3, l2);
    for (auto i : v3) {
        cout << i<< endl;
    }

    vector<int> v1 = {1,2};
    set<int> s1 = {1,4};
    cout << "merging a set and vector result set containing: " << endl;
    merge(s1, v1);
    for (auto i : s1) {
        cout << i<< endl;
    }

    cout << "merging a vector and a set result vetor containing: " << endl;
    merge(v1, s1);
    for (auto i : v1) {
        cout << i<< endl;
    }

    set<int> s3 = {1,4};
    set<int> s2 = {2,4};
    cout << "merging a set with a set result set containing: " << endl;
    merge(s1, s3);
    for (auto i : s1) {
        cout << i<< endl;
    }

    map<int, int> map1;
    // insert elements in random order
    map1.insert(pair<int, int>(1, 40));
    map1.insert(pair<int, int>(2, 30));
    map1.insert(pair<int, int>(3, 60));

    map<int, int> map2;
    // insert elements in random order
    map2.insert(pair<int, int>(1, 100));
    map2.insert(pair<int, int>(5, 30));
    map2.insert(pair<int, int>(6, 60));

    //key must be unique therfore adding 1,40 gets ignored
    merge(map2, map1);

    cout << "merging to maps results in" << endl;
    for (auto i : map2) {
        cout << i.first << " " << i.second<< endl;
    }

    cout << "merging a map with a list" << endl;
    merge(map2, l1);

    cout << "merging vectors that contain different typ of obj" << endl;
    vector<string> vS = {"Jan", "Mia"};
    merge(v1, vS);
}


