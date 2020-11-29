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
    int flag;
    complex<double> cp;

    aspolar(complex<double> c, int f) : cp(c), flag(f) {};
    //constructor overload to make flag optional
    aspolar(complex<double> c) : cp(c) {};
};

//overload output operator for aspolar struct
inline std::ostream &operator<<(std::ostream &os, aspolar a) {
    os << "Mag: " << abs(a.cp) << ",";
    os << " Phase: ";
    if(a.flag == aspolar::DEG) { //degree
        os << arg(a.cp)*180/M_PI << " GRAD";
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
    cout << aspolar(c, aspolar::GRAD) << endl;
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
