#include <iostream>
#include "regex"
#include "vector"

using namespace std;

smatch find_rgx2(regex r, vector<string> v){
    smatch matches;
    for(auto it = v.begin(); it != v.end(); it++) {
        regex_search(*it,matches,r);
    }
    return matches;
}

bool find_rgx(regex r, vector<string> v){
    for(auto it = v.begin(); it != v.end(); it++) {
        if(regex_match(*it, r)) {
            return true;
        }
    }
    return false;
}


int main() {
    regex r("(.)*(x)+(.)*");
    vector<string> v;
    v.push_back("abcde");
    v.push_back("dexert");
    v.push_back("1233251345");
    smatch m = find_rgx2(r,v);
    if(m.size() > 0) {
        cout << "matched: " << m[0] << endl;
    }
    return 0;
}
