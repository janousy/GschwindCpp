#include <iostream>
#include <vector>
#include "playfield.h"
#include "human.h"
#include "human.cpp"
//!! needs to be included as well for header templates

/* 4-Gewinnt Implementation
*/
using namespace std;

int sum_direction(int hOrg, int wOrg, int hDir, int wDir, playfield &pf) {
    int h = hOrg + hDir;
    int w = wOrg + wDir;
    int sum = 0;

    while (h < pf.height && h >= 0 && w < pf.width && w >= 0) {

        if (pf.stoneat(wOrg, hOrg) == pf.stoneat(w, h)) {
            sum = sum + 1;
            h = h + hDir;
            w = w + wDir;
        } else {
            break;
        }
    }
    return sum;
}

bool boardFull(playfield &pf) {
    for (int h = 0; h < pf.height; h++) {
        for (int w = 0; w < pf.width; w++) {
            if (pf.stoneat(w, h) == pf.none) {
                return false;
            }
        }
    }
    return true;
}

bool game_finished(int hOrg, int wOrg, playfield &pf) {

    int h = hOrg;
    int w = wOrg;
    //check vertical
    if (sum_direction(h, w, 1, 0, pf) >= 3) {
        return true;
    }
        //check horizontal
    else if (sum_direction(h, w, 0, 1, pf) + sum_direction(h, w, 0, -1, pf) >= 3) {
        return true;
    }
        //check to top left and button right
    else if (sum_direction(h, w, -1, -1, pf) + sum_direction(h, w, 1, 1, pf) >= 3) {
        return true;
    }
        //check to top right and button left
    else if (sum_direction(h, w, -1, 1, pf) + sum_direction(h, w, 1, -1, pf) >= 3) {
        return true;
    } else {
        return false;
    }

}

void print_playfield(playfield pf) {
    for (int h = 0; h < pf.height; h++) {
        for (int w = 0; w < pf.width; w++) {
            cout << pf.stoneat(h, w) << " ";
        }
        cout << endl;
    }
}

int insert_stone(playfield &pf, int c, int playerSign) {
    int h = 0;
    while (pf.stoneat(h + 1, c) == 0 && h + 1 < playfield::height) {
        h++;
    }
    pf.rep[h][c] = playerSign;
    return h;
}

int main() {
    human<playfield> h1;
    human<playfield> h2;
    playfield pf;

    vector<human<playfield> > players;
    players.push_back(h1);
    players.push_back(h2);


    for (int h = 0; h < pf.height; h++) {
        for (int w = 0; w < pf.width; w++) {
            pf.rep[w][h] = pf.none;}
    }

    print_playfield(pf);

    int turn = 0;
    for(;;) {
        int w;
        int h = -1;
        while (h < 0){
            w = h1.play(pf);
            h = insert_stone(pf, w, turn+1);
        }

        print_playfield(pf);
        if (game_finished(h, w,pf)){
            cout << "Game Finished player" << " "<< turn + 1 << " " << "won" << endl;
            break;
        }
        if (boardFull(pf)){
            cout << "Draw because board is full" << endl;
            break;
        }
        turn = (turn +1) % 2;
    }

    return 0;
}
