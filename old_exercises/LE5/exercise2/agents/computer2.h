//
// Created by Janosch Baltensperger on 26.11.20.
//

#ifndef EXERCISE2_COMPUTER2_H
#define EXERCISE2_COMPUTER2_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//by David Wehrli
template<typename R>
struct computer2{
    int i = 7;
    string four;
    int play(const R &field){
        for (int w = 0; w != field.width; ++w) {
            for (int h = field.height-1; h >= 3; --h) {
                if (field.stoneat(w,h) != 0) {
                    if (field.stoneat(w,h) == field.stoneat(w,h-1) && field.stoneat(w,h) == field.stoneat(w,h-2) && field.stoneat(w,h-3) == 0) {
                        return w;
                    }
                }
            }
        }
        for (int h = field.height-1; h >= 0; --h){
            //cout << "H: " << h << endl;
            for (int w = 0; w != field.width - 3; ++w){
                //cout << "w: " << w << endl;
                four.append(1,field.stoneat(w,h));
                four.append(1,field.stoneat(w+1,h));
                four.append(1,field.stoneat(w+2,h));
                four.append(1,field.stoneat(w+3,h));
                //cout << "four: " << four << endl;
                if(oneO(four)) {
                    if(e3(four)) {
                        int O = four.find(field.none);
                        //cout << "O: " << O << endl;
                        four.clear();
                        if(field.stoneat(w+O,h+1) != field.none or h == 5) {
                            return w+O;
                        }
                    }
                }
                four.clear();
            }
        }
        for (int h = field.height-1; h >= 3; --h){
            //cout << "H: " << h << endl;
            for (int w = 0; w != field.width - 3; ++w){
                //cout << "w: " << w << endl;
                four.append(1,field.stoneat(w,h));
                four.append(1,field.stoneat(w+1,h-1));
                four.append(1,field.stoneat(w+2,h-2));
                four.append(1,field.stoneat(w+3,h-3));
                //cout << "four: " << four << endl;
                if(oneO(four)) {
                    if(e3(four)) {
                        int O = four.find(field.none);
                        //cout << "O: " << O << endl;
                        four.clear();
                        if(field.stoneat(w+O,h+1-O) != field.none or h-O == 5) {
                            return w+O;
                        }
                    }
                }
                four.clear();
            }
        }
        for (int h = field.height-1; h >= 3; --h){
            //cout << "H: " << h << endl;
            for (int w = field.width -1; w >= 3; --w){
                //cout << "w: " << w << endl;
                four.append(1,field.stoneat(w,h));
                four.append(1,field.stoneat(w-1,h-1));
                four.append(1,field.stoneat(w-2,h-2));
                four.append(1,field.stoneat(w-3,h-3));
                //cout << "four: " << four << endl;
                if(oneO(four)) {
                    if(e3(four)) {
                        int O = four.find(field.none);
                        //cout << "O: " << O << endl;
                        four.clear();
                        if(field.stoneat(w-O,h+1-O) != field.none or h-O == 5) {
                            return w-O;
                        }
                    }
                }
                four.clear();
            }
        }

        if(i == -1) i =7;
        --i;
        return i;

    }

    bool e3(string in) {
        char O = 0;
        int none = in.find(O);
        in.erase(in.begin()+none);
        for(int i = 1; i!=in.size(); ++i){
            if(in[i] != in[i-1]) return false;
        }
        return true;
    }

    bool oneO(string in) {
        int cntr = 0;
        for(int i = 0; i!=4; ++i){
            if(in[i] == 0) ++cntr;
        }
        if(cntr == 1) return true;
        else return false;
    }

};


#endif //EXERCISE2_COMPUTER2_H
