#include <iostream>
using namespace std;

struct subn {
    const char *s;
    size_t n; //unsigned integer type, only nr>=0
    subn(const char *s, size_t n) : s(s), n(n) { /*void*/ }
};

// How to display the output manipulator
inline std::ostream &operator<<(std::ostream &os, subn s) {
    while (s.n-- && *s.s) os << *(s.s++);
    return os;
}

int main() {
    const char *s = "Here comes the sun…";
    cout << subn(s, 10) << endl;
    return 0;
}
