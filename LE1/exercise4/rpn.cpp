//
// Created by Janosch Baltensperger on 23.09.20.
//

#include "rpn.h"
#include <iostream>

using namespace std;

rpn::rpn() {}

bool rpn::has_valid_size(vector<int> numbers) {
    if (numbers.size() < 2) {
        cout << "invalid operation";
        return false;
    } else {
        return true;
    }
}

vector<int> rpn::mymin(vector<int> numbers) {
    if (!has_valid_size(numbers)) {
        return numbers;
    } else {
        cout << "last two values on stack: " << *(numbers.rbegin()) << ", " << (*(numbers.rbegin() + 1))
             << endl;
        int min_val = std::min(*(numbers.end() - 1), *(numbers.end()));
        numbers.erase(numbers.end() - 1);
        cout << "min value: " << min_val << endl;
        numbers.push_back(min_val);
    }
}

vector<int> rpn::mult(vector<int> &numbers) {
    if (!has_valid_size(numbers)) {
        return numbers;
    } else {
        int res = numbers.at(numbers.size()-2) * numbers.at(numbers.size()-1);
        numbers.erase(numbers.end() + 2);
        cout << "res: " << res << endl;
        numbers.push_back(res);
    }
}

vector<int> rpn::divide(vector<int> numbers) {
    if (!has_valid_size(numbers)) {
        return numbers;
    } else {
        int res = *(numbers.end() - 1) / *(numbers.end());
        numbers.erase(numbers.end() - 1);
        cout << "res: " << res << endl;
        numbers.push_back(res);
    }
}

vector<int> rpn::add(vector<int> numbers) {
    if (!has_valid_size(numbers)) {
        return numbers;
    } else {
        int res = *(numbers.end() - 1) + *(numbers.end());
        numbers.erase(numbers.end() - 1);
        cout << "res: " << res << endl;
        numbers.push_back(res);
    }
}

vector<int> rpn::subtract(vector<int> numbers) {
    if (!has_valid_size(numbers)) {
        return numbers;
    } else {
        int res = *(numbers.end() - 1) - *(numbers.end());
        numbers.erase(numbers.end() - 1);
        cout << "res: " << res << endl;
        numbers.push_back(res);
    }
}