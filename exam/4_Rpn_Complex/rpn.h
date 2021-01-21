//
// Created by Janosch Baltensperger on 07.10.20.
//

#ifndef EXERCISE3_RPN_H
#define EXERCISE3_RPN_H


#include <iostream>
#include <fstream>
#include "pvector.h"
#include <map>
#include <complex>

using namespace std;

template<typename T>
class rpn {
private:
    bool has_valid_size(pvector<T> &pv);
    string input_line;

public:
    void read_input(pvector<T> &pv) {
        char op;
        while (cin.good() && op != 'q') {
            T number;
            cout << "command: ";
            getline(cin, input_line);
            istringstream iss(input_line);
            while (iss.good() && iss >> op) {
                switch (op) {
                    case 'n':
                        iss >> number;
                        pv.push_back(number);
                        continue;
                    case 'd':
                        if (pv.size() > 0) { pv.pop_back(); }
                        else { cout << "cannot delete"; }
                        continue;
                    case 'q':
                        break;
                    case '+':
                        add(pv);
                        continue;
                    case '-':
                        subtract(pv);
                        continue;
                    case '*':
                        multiply(pv);
                        continue;
                    case '/':
                        divide(pv);
                        continue;
                    case 'm':
                        mymin(pv);
                        continue;
                    default:
                        cout << "invalid input" << endl;
                        break;
                }
            }
            pv.print_vector();
        }
    }


    inline
    void mymin(pvector<complex<int>> &pv) {
        cout << "no order on complex numbers" << endl;
        return;
    }

    void mymin(pvector<T> &pv){
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

    void add(pvector<T> &pv){
        if (!has_valid_size(pv)) {
            return;
        } else {
            T res = pv.at(pv.size() - 2) + pv.at(pv.size() - 1);
            pv.pop_back();
            pv.pop_back();
            pv.push_back(res);
        }
    }

    void subtract(pvector<T> &pv){
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

    void multiply(pvector<T> &pv){
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

    void divide(pvector<T> &pv){
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
