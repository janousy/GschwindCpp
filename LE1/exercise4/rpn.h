//
// Created by Janosch Baltensperger on 23.09.20.
//

#ifndef EXERCISE4_RPN_H
#define EXERCISE4_RPN_H
#include <vector>
using namespace std;

class rpn {
public:
    rpn();
    vector<int> mymin(vector<int> numbers);
    vector<int> mult(vector<int > &numbers);
    vector<int> divide(vector<int > numbers);
    vector<int> subtract(vector<int > numbers);
    vector<int> add(vector<int > numbers);
    bool has_valid_size(vector<int> numbers);
};


#endif //EXERCISE4_RPN_H
