#include <iostream>
#include <fstream>
#include <istream>
#include<set>

#include "pset.h"
#include "pset.cpp"
#include "persistence_traits.h"
#include "persistence_traits.cpp"
using namespace std;

/*
Build command:
g++ -std=c++17 main.cpp -o main
run command with input and output file specified:
 ./main "text.txt" "dict.txt"
*/

int main(int argc, char *argv[]) {

    std::ifstream text(argv[1]);
    //std::fstream dict_file(argv[2]);

    //set<string> dictionary;
    pset<string> dictionary (argv[2]);
    pset<string> updatedText;
    string word;

    /* could be extended if wanted*/
    set<string> symbols = {".", ",", "?", "!"};
    string input;

    if(text.is_open()) {
        while(text >> word){
            /*if last character is a symbol we remove it for special cases like the end of the sentence.
             * word.back returns a pointer to the last char of the string.*/
            if(symbols.count(&word.back()) != 0) word.pop_back();

            /*check if word is not a symbol and not in dictionary */
            if(symbols.count(word) == 0 && !dictionary.in_set(word)) {
                std::cout << word << " " << "is not in the dictionary, would you like to add it? [Y,N]" << std::endl;
                cin >> input;
                if( input == "Y" or input == "y"){
                    dictionary.insert(word);
                    updatedText.insert(word);
                }
                else{
                    cout << "Would you like to correct the word? [corrected word, N] " << endl;
                    cin >> input;
                    if( input != "N" and input != "n" ) {
                        updatedText.insert(input);
                    }
                    else{
                        updatedText.insert(word);
                    }
                }
            }
            else{
                updatedText.insert(word);
            }
        }
    }
    else std::cout << "cant open text file" << std::endl;
    text.close();
    updatedText.add_filename(argv[1]);

    return 0;
}
