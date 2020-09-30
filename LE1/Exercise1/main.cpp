#include <iostream>
#include <fstream>

//g++ main.cpp -o main
//./main "input.txt" "output.txt"

/* Exercise 1.1
Implement a program that converts Unix style text files to MSDOS
style text files and vice-versa
• Unix uses ‘\n’ as line separators
• MSDOS uses ‘\r’ followed by ‘\n’ as line separators
• How do you deal with incorrectly formatted Unix text files?
 */

int main(int argc, char *argv[]) {
    //argc: number of command line arguments
    std::cout << "Hello, World!" << std::endl;

    //std::cout << "input file: " << argv[1] << std::endl;
    //std::cout << "input file: " << argv[2] << std::endl;

    std::ifstream ifs(argv[1]);
    std::ofstream ofs(argv[2]);
    char c;
    bool stream_ended = false;

    if (ifs.is_open()) {
        for (;;) {
            if (ifs.get(c)) {
                std::cout << c << std::endl;
                if (c == '\n') ofs << "\r\n";
                else ofs << c;
            } else {
                break;
            }
        }
    } else std::cout << "cant open input file" << std::endl;

    return 0;
}
