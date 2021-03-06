#include <iostream>
#include "complex"
#include <math.h>

using namespace std;

// subn becomes our output manipulation class
struct aspolar {
    //C++ standard allows only static constant integral or enumeration types to be initialized inside the class
    //using bit integers instead of enums
    static const int DEG = 0x1;
    static const int RAD = 0x2;
    static const int GRAD = 0x4;
    //default RAD for flag (seems to be standard with complex numbers)
    int flag;
    complex<double> cp;

    //default RAD
    aspolar(complex<double> c, int f=aspolar::RAD) : cp(c), flag(f) {};
};

//overload output operator for aspolar struct
inline std::ostream &operator<<(std::ostream &os, aspolar a) {
    os << "Mag: " << abs(a.cp) << ",";
    os << " Phase: ";
    if(a.flag == aspolar::DEG) { //degree
        os << arg(a.cp)*180/M_PI << " DEG";
    }
    else if(a.flag == aspolar::RAD) { //radian
        os << arg(a.cp) << " RAD";
    }
    else if(a.flag == aspolar::GRAD) { //gon
        os << arg(a.cp)*200/M_PI << " GRAD";
    }
    return os;
}

// Using our output manipulator
int main() {
    complex<double> c(3.00,5.00);
    cout << c << endl;
    cout << aspolar(c, aspolar::GRAD) << endl;
    cout << aspolar(c, aspolar::DEG) << endl;
    cout << aspolar(c) << endl;
    return 0;
}

/*
The aspolar modifier takes a complex number and optionally a RAD/DEG/GRAD flag
- Displays the complex number in polar coordinates and writes it to
    the output stream without generating a temporary string to store
    the complex number
- complex<double> c=…;
    cout << aspolar(c, aspolar::DEG) << endl;
*/
