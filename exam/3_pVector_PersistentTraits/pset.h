//
// Created by Janosch Baltensperger on 23.10.20.
//

#ifndef EXERCISE2_PSET_H
#define EXERCISE2_PSET_H

#include <iostream>
#include <fstream>
#include "set"
#include "persistence_traits.h"

using namespace std;

template<typename T, typename P=persistence_traits<T>>
class pset {
private:
    string filename;
    set<T> s;
    typedef P persister;
    typedef typename set<T>::iterator iterator;

public:
    pset(string fname) : filename(fname) {
            read_set();
    }

    ~pset() {
        write_set();
    }

    void read_set() {
        ifstream ifs(filename);
        if (!ifs.is_open()) {
            cout << "invalid file" << endl;
            return;
        }

        //read from ifs until end of file (eof)
        while(true) {
            T x;
            persister::read(ifs,x);
            if(ifs.eof()) {break;}
            s.insert(x);
        }
    };


    void write_set() {
        ofstream ofs(filename);
        iterator fst = s.begin();
        iterator lst = s.end();
        while(fst!=lst) persister::write(ofs,*fst++);
    };

    void insert(T elem) {
        s.insert(elem);
    }

    void print_set() {
        iterator fst = s.begin();
        iterator lst = s.end();
        while(fst!=lst) {
            cout << *fst << " ";
            fst++;
        }
        cout << endl;
    };
};


#endif //EXERCISE2_PSET_H
