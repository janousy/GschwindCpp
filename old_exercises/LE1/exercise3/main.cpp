#include <iostream>

#include <iostream>
#include <fstream>
#include<set>

using namespace std;

/*Implement a simple spell checker. The spell checker takes two files
as command line arguments, a dictionary file containing a list of
correctly spelled words and a file whose content is to be checked.
Upon startup, your program stores the words contained in the
        dictionary file in a set<string>.  Then it reads every word in the file
to spell check, checks whether each word is correctly spelled (ie
contained in the dictionary file) and if not displays it on cout.*/

/*
Build command:
g++ -std=c++11  main.cpp -o main
./main "text.txt" "dictionary.txt"
*/

int main(int argc, char *argv[]) {

    std::fstream text(argv[1]);
    std::fstream dict_file(argv[2]);

    set<string> dictionary;
    string word;
    /* could be extended if wanted*/
    std::set<std::string> symbols = {".", ",", "?", "!"};

    // is_open() => returns whether the stream is currently associated to a file
    if(dict_file.is_open()) {
        while(dict_file >> word){
            dictionary.insert(word);
        }
        if(text.is_open()) {
            while(text >> word){
                /*if last character is a symbol we remove it for special cases like the end of the sentence.
                 * word.back returns a pointer to the last char of the string.*/
                if(symbols.count(&word.back()) != 0) word.pop_back();
                /*check if word is not a symbol and not in dictionary */
                if(symbols.count(word) == 0 && dictionary.count(word) == 0) {
                    cout << word << endl;
                }
            }
        }
        else cout << "error opening text file" << endl;
    }
    else cout << "error opening dictionary file" << endl;

    return 0;
}
