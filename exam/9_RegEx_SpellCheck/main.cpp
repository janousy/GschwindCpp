#include <iostream>
#include <fstream>
#include <istream>
#include<set>
#include <stdio.h>
#include "regex"
#include "algorithm"
using namespace std;

int main(int argc, char *argv[]) {

    std::fstream text("/Users/janoschbaltensperger/repos/GeschwindCpp/LE5/exercise1/text.txt");
    vector<string> inputWords;

    std::fstream dictionary("/Users/janoschbaltensperger/repos/GeschwindCpp/LE5/exercise1/dictionary.txt");
    string line;
    string regexString;
    vector<string> regexes; //dictionary items

    //push dictionary into regex vector
    if (dictionary.is_open()) {
        while (dictionary >> regexString) {
            regexes.push_back(regexString);
        }
    } else std::cout << "cant open text file" << std::endl;


    if (text.is_open()) {
        //check every line
        while (std::getline(text, line)) {
            
            std::regex config("\\w+"); //omit punctuation

            //make line iterable over words in line, with applied regex configuration
            auto line_begin = std::sregex_iterator(line.begin(), line.end(),  config);
            auto line_end = std::sregex_iterator();

            //check every word in line
            for (std::sregex_iterator i = line_begin; i != line_end; ++i) {
                std::smatch match = *i;
                std::string word = match.str(); //read word contained in matcher
                bool inDict = false;

                //check if retrieved word is matches with *any* regex from dictionary
                for(auto r = regexes.begin(); r != regexes.end(); ++r){
                    regex regexEx(*r);
                    if (regex_match(word, regexEx)){
                        inDict = true;
                        break;
                    }
                }
                //print words not matching any regex
                if(!inDict){
                    cout << word << endl;
                }
            }
        }
    } else std::cout << "cant open text file" << std::endl;

    return 0;
}
