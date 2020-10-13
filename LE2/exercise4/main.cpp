#include <iostream>
#include <vector>
#include "playfield.h"
#include "human.h"
#include "human.cpp"
//!! needs to be included as well for header templates

/* 4-Gewinnt Implementation

 g++ -Wall main.cpp -o main
 ./main
*/


using namespace std;

int sum_direction(int hOrg, int cOrg, int hDir, int cDir,  playfield &pf){
    int h = hOrg + hDir;
    int c = cOrg + cDir;
    int sum = 0;

    while (h< pf.height && h>= 0 && c< pf.width && c>= 0){

        if(pf.stoneat(hOrg,cOrg) == pf.stoneat(h,c)){
            sum = sum +1;
            h = h + hDir;
            c = c + cDir;
        }
        else{
            break;
        }
    }

    return sum;
}

bool game_finished(int hOrg, int cOrg, playfield &pf) {

    int h = hOrg;
    int c = cOrg;
    //check vertical
    if (sum_direction(h, c, 1, 0, pf) >= 3) {
        return true;
    }
        //check to top left and buttom right
    else if (sum_direction(h, c, -1, -1, pf) + sum_direction(h, c, 1, 1, pf) >= 3) {
        return true;
    }
        //check to top right and buttom left
    else if (sum_direction(h, c, -1, 1, pf) + sum_direction(h, c, 1, -1, pf) >= 3) {
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

    vector<human<playfield> > players;
    players.push_back(h1);
    players.push_back(h2);

    playfield pf;

    for (int h = 0; h < pf.height; h++) {
        for (int w = 0; w < pf.width; w++) {
            pf.rep[h][w] = pf.none;
        }
    }

    print_playfield(pf);
    int turn = 0;
    for (;;) {
        int c, h;
        c = h1.play(pf);
        h = insert_stone(pf, c, turn + 1);
        print_playfield(pf);
        if (game_finished(h, c, pf)) {
            cout << "Game Finished player" << turn + 1 << "won" << endl;
            break;
        }

        turn = (turn + 1) % 2;
    }
    return 0;
}
