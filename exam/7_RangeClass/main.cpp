/*https://stackoverflow.com/questions/7185437/is-there-a-range-class-in-c11-for-use-with-range-based-for-loops*/
/*
 § This class should allow to do the following § for(auto i : range(10,20)) cout << i << endl;
 § Shows the numbers from 10 to 20. § What do you need for the range to work in combination with your
    range for object.
 § Hint: Eventually, you need will need an iterator that does nothing
        more than counting.
*/

/*
 ? pre increment ++it is more efficient than i++? why?
*/

#include <iostream>

using namespace std;

class iter {
private:
    int pos;

public:
    //dereference
    iter(int start) : pos(start) {}

    //dereference
    long int operator*() const { return pos; }

    //pre-increment
    iter &operator++() {
        ++pos;
        return *this;
    }

    //unequality
    bool operator!=(const iter &other) { return pos != other.pos; }

};


class range_class {
private:
    int start_val;
    int end_val;
public:

    range_class(int start, int end) : start_val(start), end_val(end) {};
    iter begin() const { return iter(start_val); }
    iter end() const { return iter(end_val); }
};

const range_class range(int begin, int end) {
    return range_class(begin, end);
}

int main() {
    // for ( range_declaration : range_expression ) loop_statement
    for (auto it: range(10, 20)) {
        cout << it << endl;
    }
}

/*
 'for' takes as an argument a range declaration and expression. the range expression
 must implement begin() and end() member functions
 should be equivalent to this:
    for (int it = obj.begin(); it =! object.end(); ++it)

=> shows numbers 1:19! (usual implementation of range loop)
*/
