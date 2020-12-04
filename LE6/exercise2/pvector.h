//
// Created by Janosch Baltensperger on 28.11.20.
//

#ifndef EXERCISE2_PVECTOR_H
#define EXERCISE2_PVECTOR_H

#ifndef EXERCISE3_PVECTOR_H
#define EXERCISE3_PVECTOR_H

#include <iostream>
#include <fstream>
#include "vector"
#include "FileLocker.h"

using namespace std;

template<typename T>
class pvector {
protected:
    FileLocker fl;
    string filename;
    vector<T> v;

public:
    //lock file upon creating pvector, since operating on elements
    //lock file upon creating pvector, since operating on elements
    pvector(string fname) : filename(fname), fl(fname) {
        cout << "reading vector" << endl;
        read_vector();
    }

    ~pvector() {
        cout << "writing vector" << endl;
        write_vector();
    }

    void push_back(const T &el);

    void pop_back();

    void read_vector();

    int size();

    T at(int pos);

    void write_vector();

    void print_vector();
};


#endif //EXERCISE3_PVECTOR_H


#endif //EXERCISE2_PVECTOR_H
