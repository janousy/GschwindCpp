#include <iostream>
using namespace std;

//Formatter with state
struct Form {
    int prc, wdt, fmt;
    Form(int p=6) : prc(p) { fmt=wdt=0; }
    Form& scientific() {
        fmt=ios_base::scientific;
        return *this;
    }
    Form& precision(int p) { prc=p; return *this; }
};

//output operator
ostream& operator<<(ostream& os, const Form &f) {
    os.setf(f.fmt,ios_base::floatfield);
    // ...change other output settings...
    return os;
}

Form gen4(4);
void f(double d) {
    Form sci8=gen4;
    sci8.scientific().precision(8);
    cout << sci8 << d << endl;
    // from now on, all output will use the format defined by sci8
    // (until changed again)
}

int main() {
    f(2.345);
    // from now on, all output will use the format defined by sci8
    // (until changed again)
}