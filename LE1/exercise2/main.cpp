#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

class fraction {
    int cntr;
    int denom;

public:
    //constructor
    fraction(int c = 0, int d = 1) : cntr(c), denom(d) { /*void*/ }

    int get_counter() {
        return cntr;
    }

    void set_counter(int c) {
        cntr = c;
    }

    int get_denominator() {
        return denom;
    }

    void set_denominator(int d) {
        denom = d;
    }
};

fraction operator*(fraction a, fraction b) {
    int f1 = __algo_gcd(a.get_counter(), b.get_denominator());
    int f2 = __algo_gcd(b.get_counter(), a.get_denominator());
    return fraction((a.get_counter() / f1) * (b.get_counter() / f2),
                    (a.get_denominator() / f2) * (b.get_denominator() / f1));
}

fraction operator/(fraction a, fraction b) {
    return a * fraction(b.get_denominator(), b.get_counter());
}

fraction operator+(fraction a, fraction b) {
    int denom = (a.get_denominator() * b.get_denominator()) / __algo_gcd(a.get_denominator(), b.get_denominator());
    int cntr1 = denom / a.get_denominator() * a.get_counter();
    int cntr2 = denom / b.get_denominator() * b.get_counter();

    return fraction(cntr1 + cntr2, denom);

}

fraction operator-(fraction a, fraction b) {
    int denom = (a.get_denominator() * b.get_denominator()) / __algo_gcd(a.get_denominator(), b.get_denominator());
    int cntr1 = denom / a.get_denominator() * a.get_counter();
    int cntr2 = denom / b.get_denominator() * b.get_counter();

    return fraction(cntr1 - cntr2, denom);

}

ostream &operator<<(ostream &os, fraction f) {
    os << '(' << f.get_counter() << '/' << f.get_denominator() << ')';
    return os;
}

void check_char(char ch, istream &is) {
    char c;
    is >> c;
    if (c != ch) {
        is.putback(c);
        is.setstate(ios::badbit);
    }
}

istream &operator>>(istream &is, fraction &f) {
    fraction g;
    int counter, denom;

    check_char('(', is);
    is >> counter;
    check_char('/', is);
    is >> denom;
    check_char(')', is);
    g.set_counter(counter);
    g.set_denominator(denom);

    if (is) f = g;

    return is;
}

int main() {
    fraction f1(2, 3);
    fraction f2(1, 4);

    cout << "f1: " << f1 << std::endl;
    cout << "f2: " << f2 << std::endl;

    fraction res1 = f1 * f2;
    cout << "f1 * f2 = " << res1 << endl;

    fraction input1;
    fraction input2;

    cout << "Your first fraction: " << endl;
    cin >> input1;
    cout << input1 << endl;
    cout << "Your second fraction: " << endl;
    cin >> input2;
    cout << input2 << endl;

    cout << "operation (+,-,*,/) ?" << endl;
    string op;
    cin >> op;

    if (op == "*") {
        cout << input1 * input2;
    } else if (op == "/") {
        cout << input1 / input2;
    } else if (op == "-") {
        cout << input1 - input2;
    } else if (op == "+") {
        cout << input1 + input2;
    } else {
        cout << "invalid operation";
    }
    return 0;
}
