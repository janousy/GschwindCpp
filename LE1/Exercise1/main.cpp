#include <iostream>

#include <iostream>
#include <fstream>

/* Exercise 1.1
 * Implement a program that converts Unix style text files to MSDOS
    style text files and vice-versa
• Unix uses ‘\n’ as line separators
• MSDOS uses ‘\r’ followed by ‘\n’ as line separators
• How do you deal with incorrectly formatted MSDOS text files?
 */

int main(int argc, char *argv[]) {
    std::cout << "Hello, World!" << std::endl;

    std::ifstream ifs(argv[1]);
    std::ofstream ofs(argv[2]);
    char c;

    int length = ifs.tellg();
    std::cout << "Reading file of length: " << length << std::endl;

    for (;;) {
        if (!ifs.good()) {
            break;
        }
        ifs.get(c);
        if (c == '\n') ofs << "\r\n"; else ofs << c;
    }

    return 0;
}
