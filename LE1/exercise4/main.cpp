#include <iostream>
#include <vector>
#include "rpn.h"

using namespace std;

/*
Implement an RPN (Reverse Polish Notation Calculator)
• When the user enters ‘q’ the program terminates
• When the user enters ‘n’ followed by a number, it is put on the stack
• When the user enters ‘d’ the last number is removed from the stack
• When the user enters ‘+’, ‘-’, ‘*’, ‘/’, the calculator takes the last two numbers
        from the stack applies the operation to the numbers and puts the result on the stack
• When the user enters ‘min’, the calculator takes the last two numbers from
        the stack applies the operation to the numbers and puts the minimum of the
        two numbers back onto the stack
• Use the std::vector container and its iterator
*/

//type vector is using a reverse iterator!

int parse_input(string input) {
    try {
        //disadvantage of std::stoi -> also converts 10xy to 10
        int i = stoi(input);
        return i;
    }
    catch (invalid_argument const &e) {
        cout << "Bad input: std::invalid_argument thrown" << '\n';
    }
    catch (out_of_range const &e) {
        cout << "Integer overflow: std::out_of_range thrown" << '\n';
    }
}

void print_stack(vector<int> numbers) {
    cout << "on stack: ";
    for (vector<int>::iterator i = numbers.begin(); i != numbers.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> numbers;
    rpn cc;
    string input;

    while (input != "q") {
        cout << "Your input: ";
        cin >> input;
        cout << input;
        if (input == "n") {
            cout << "Your number: ";
            cin >> input;
            int input_int = parse_input(input);
            numbers.push_back(input_int);
            input = "";
        } else if (input == "d") {
            if (numbers.empty()) {
                cout << "no element to delete" << endl;
            } else {
                numbers.pop_back();
            }
        } else if (input == "q") {
            break;
        } else if (input == "min") {
            cc.mymin(numbers);
        } else if (input == "*") {
            cc.mult(numbers);
        } else if (input == "/") {
            cc.divide(numbers);
        } else if (input == "+") {
            cc.add(numbers);
        } else if (input == "-") {
            cc.subtract(numbers);
        } else {
            cout << "invalid input" << endl;
            input = "";
        }
        print_stack(numbers);
    }
    cout << "quitting...";
    return 0;
}
