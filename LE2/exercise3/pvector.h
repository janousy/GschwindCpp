//
// Created by Janosch Baltensperger on 07.10.20.
//

#ifndef EXERCISE3_PVECTOR_H
#define EXERCISE3_PVECTOR_H

#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
class pvector {
protected:
    string filename;
    vector<T> v;

public:
    pvector(string fname) : filename(fname) {
        //read_vector();
    }

    ~pvector() {
        //write_vector();
    }

    void push_back(const T &el) {
        v.push_back(el);
    }

    void pop_back() {
        v.pop_back();
    }

    void read_vector() {
        ifstream ifs(filename);

        if (!ifs.is_open()) {
            cout << "invalid file" << endl;
            return;
        }

        for (;;) {
            T x;
            ifs >> x;
            if (!ifs.good()) {
                break;
            } else {
                v.push_back(x);
            }
        }
    }

    T at(int pos) {
        return v.at(pos);
    }

    int size() {
        return v.size();
    }

    void write_vector() {
        ofstream ofs(filename);
        for (const T &elem : v) {
            ofs << elem << endl;
        }
    }

    void print_vector() {
        for (int i = 0; i < v.size(); i++) {
            std::cout << v.at(i) << ' ';
        }
        cout << endl;
    }
};


#endif //EXERCISE3_PVECTOR_H
