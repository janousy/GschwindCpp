#include <iostream>
#include <fstream>

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

    for (;;) {
        if (!ifs.good()) {
            std::cout << "stream ended" << std::endl;
            stream_ended = true;
            break;
        }
        ifs.get(c);
        //std::cout << c << std::endl;
        if (c == '\n') {
            std::cout << "converting line break" << std::endl;
            ofs << "\r\n";
        }
        else {
            if(!stream_ended) ofs << c;
        }
    }
    return 0;
}
