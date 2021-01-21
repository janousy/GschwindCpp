//
// Created by Janosch Baltensperger on 20.01.21.
//
#ifndef EXERCISE3_PVECTOR_H
#define EXERCISE3_PVECTOR_H

#include <iostream>
#include <fstream>
#include "vector"
#include "persistence_traits.h"
#include "persistence_traits.cpp"

using namespace std;

template<typename T, typename P=persistence_traits<T>>
class pvector {
private:
    string filename;
    vector<T> v;
    typedef P persister;
    typedef typename vector<T>::iterator iterator;

public:
    pvector(string fname) : filename(fname) {
        read_vector();
    }

    ~pvector() {
        write_vector();
    }

    void write_vector() {
        ofstream ofs(filename);
        iterator fst = v.begin();
        iterator lst = v.end();
        while(fst!=lst) persister::write(ofs,*fst++);
    }

    void read_vector() {
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
            v.push_back(x);
        }
    }

    void print_vector() {
        for (int i = 0; i < v.size(); i++) {
            std::cout << v.at(i) << ' ';
        }
        cout << endl;
    }


    void push_back(const T &el) {
        v.push_back(el);
    }

    void pop_back(){
        v.pop_back();
    }

    int size(){
        return v.size();
    }

    T at(int pos){
        return v.at(pos);
    }

};