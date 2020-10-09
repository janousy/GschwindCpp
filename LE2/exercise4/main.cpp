#include <iostream>
#include <vector>
#include "playfield.h"
#include "human.h"
#include "human.cpp"
//!! needs to be included as well for header templates

using namespace std;

void print_playfield(playfield pf) {
    for (int h = 0; h < pf.height; h++) {
        for (int w = 0; w < pf.width; w++) {
            cout << pf.stoneat(h, w) << " ";
        }
        cout << endl;
    }
}

void insert_stone(playfield &pf, int w) {
    int h = 0;
    while (pf.stoneat(h+1, w) == 0 && h < playfield::height - 1) {
        h++;
    }
    pf.rep[h][w] = 1;
}

bool check_game_ended(playfield &pf) {
    return false;
}

int main() {
    human<playfield> h1;
    human<playfield> h2;

    vector<human<playfield>> players;
    players.push_back(h1);
    players.push_back(h2);

    playfield pf;

    bool game_ended = false;

    for (int h = 0; h < pf.height; h++) {
        for (int w = 0; w < pf.width; w++) {
            pf.rep[h][w] = pf.none;
        }
    }

    print_playfield(pf);
    while (!game_ended) {
        for (human<playfield> p : players) {
            int input = p.play(pf);
            insert_stone(pf, input);
            print_playfield(pf);
            game_ended = check_game_ended(pf);
        }
    }

    return 0;
}
