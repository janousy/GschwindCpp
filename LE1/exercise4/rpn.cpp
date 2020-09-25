//
// Created by Janosch Baltensperger on 23.09.20.
//

#include "rpn.h"
#include <iostream>

using namespace std;

rpn::rpn() {}

bool rpn::has_valid_size(vector<int> &numbers) {
    if (numbers.size() < 2) {
        cout << "invalid operation" << endl;
        return false;
    } else {
        return true;
    }
}

vector<int> &rpn::mymin(vector<int> &numbers) {
    if (!has_valid_size(numbers)) {
        return numbers;
    } else {
        int min_val = std::min(numbers.at(numbers.size() - 2), numbers.at(numbers.size() - 1));
        numbers.pop_back();
        numbers.pop_back();
        numbers.push_back(min_val);
        return numbers;
    }
}

//could have used lambda functions

vector<int> &rpn::mult(vector<int> &numbers) {
    if (!has_valid_size(numbers)) {
        return numbers;
    } else {
        int res = numbers.at(numbers.size() - 2) * numbers.at(numbers.size() - 1);
        numbers.pop_back();
        numbers.pop_back();
        numbers.push_back(res);
        return numbers;
    }
}

vector<int> &rpn::divide(vector<int> &numbers) {
    if (!has_valid_size(numbers)) {
        return numbers;
    } else {
        int res = numbers.at(numbers.size() - 2) / numbers.at(numbers.size() - 1);
        numbers.pop_back();
        numbers.pop_back();
        numbers.push_back(res);
        return numbers;
    }
}

vector<int> &rpn::add(vector<int> &numbers) {
    if (!has_valid_size(numbers)) {
        return numbers;
    } else {
        int res = numbers.at(numbers.size() - 2) + numbers.at(numbers.size() - 1);
        numbers.pop_back();
        numbers.pop_back();
        numbers.push_back(res);
        return numbers;
    }
}

vector<int> &rpn::subtract(vector<int> &numbers) {
    if (!has_valid_size(numbers)) {
        return numbers;
    } else {
        int res = numbers.at(numbers.size() - 2) - numbers.at(numbers.size() - 1);
        numbers.pop_back();
        numbers.pop_back();
        numbers.push_back(res);
        return numbers;
    }
}