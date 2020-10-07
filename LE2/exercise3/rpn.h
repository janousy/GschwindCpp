//
// Created by Janosch Baltensperger on 07.10.20.
//

#ifndef EXERCISE3_RPN_H
#define EXERCISE3_RPN_H


#include <iostream>
#include <fstream>
#include "pvector.h"

using namespace std;

template<typename T>
class rpn {
private:
    bool has_valid_size(pvector<T> &pv) {
        if (pv.size() < 2) {
            cout << "invalid operation" << endl;
            return false;
        } else {
            return true;
        }
    }
public:
    void mymin(pvector<T> &pv) {
        if (!has_valid_size(pv)) {
            return;
        } else {
            T min_val = std::min(pv.at(pv.size() - 2), pv.at(pv.size() - 1));
            pv.pop_back();
            pv.pop_back();
            pv.push_back(min_val);
            return;
        }
    }

    void add(pvector<T> &pv) {
        if (!has_valid_size(pv)) {
            return;
        } else {
            T res = pv.at(pv.size() - 2) + pv.at(pv.size() - 1);
            pv.pop_back();
            pv.pop_back();
            pv.push_back(res);
        }
    }

    void subtract(pvector<T> &pv) {
        if (!has_valid_size(pv)) {
            return;
        } else {
            T res = pv.at(pv.size() - 2) - pv.at(pv.size() - 1);
            pv.pop_back();
            pv.pop_back();
            pv.push_back(res);
            return;
        }
    }

    void mult(pvector<T> &pv) {
        if (!has_valid_size(pv)) {
            return;
        } else {
            T res = pv.at(pv.size() - 2) * pv.at(pv.size() - 1);
            pv.pop_back();
            pv.pop_back();
            pv.push_back(res);
            return;
        }
    }

    void divide(pvector<T> &pv) {
        if (!has_valid_size(pv)) {
            return;
        } else {
            T res = pv.at(pv.size() - 2) / pv.at(pv.size() - 1);
            pv.pop_back();
            pv.pop_back();
            pv.push_back(res);
            return;
        }
    }
};

#endif //EXERCISE3_RPN_H
