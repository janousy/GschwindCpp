#include <iostream>
#include "playfield.h"

using namespace std;

void print_playfield(playfield pf) {
    for (int h = 0; h < pf.height; h++) {
        for (int w = 0; w < pf.width; w++) {
            cout << pf.stoneat(h, w) << " ";
        }
        cout << endl;
    }
}


void insert_stone(playfield pf, int w) {
    int h = 0;
    while(pf.stoneat(h,w) == 0 && h < playfield::height) {
        h++;
    }
    pf.rep[h][w] = 1;
}

int main() {
    playfield pf;
    bool game_ended = false;

    for (int h = 0; h < pf.height; h++) {
        for (int w = 0; w < pf.width; w++) {
            pf.rep[h][w] = 0;
        }
    }

    print_playfield(pf);
    while(!game_ended) {
        for(;;) {
            int input;
            cin >> input;
            insert_stone(pf, input);
            print_playfield(pf);
        }
    }

    return 0;
}
