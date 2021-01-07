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
    bool has_valid_size(pvector<T> &pv);

public:
    void mymin(pvector<T> &pv);

    void add(pvector<T> &pv);

    void subtract(pvector<T> &pv);

    void mult(pvector<T> &pv);

    void divide(pvector<T> &pv);
};

#endif //EXERCISE3_RPN_H
