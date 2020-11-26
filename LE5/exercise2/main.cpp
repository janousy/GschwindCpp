#include "playfield.h"
#include <iostream>
#include "agents/computer.h"
#include "agents/computer.cpp"
#include "agents/dominique.cpp"
#include "agents/com_wrapper.h"
#include "agents//com_wrapper.cpp"
#include "factory.h"


using namespace std;

void print_playfield(playfield &pf) {
    for (int h = 0; h < pf.height; h++) {
        for (int w = 0; w < pf.width; w++) {
            cout << pf.stoneat(w, h) << " ";
        }
        cout << endl;
    }
}

int sum_direction(int hOrg, int wOrg, int hDir, int wDir,  playfield &pf){
    int h = hOrg + hDir;
    int w = wOrg + wDir;
    int sum = 0;

    while (h< pf.height && h>= 0 && w < pf.width && w >= 0){

        if(pf.stoneat(wOrg, hOrg) == pf.stoneat(w, h)){
            sum = sum +1;
            h = h + hDir;
            w = w + wDir;
        }
        else{
            break;
        }
    }
    return sum;
}

bool boardFull(playfield &pf){
    for (int h = 0; h < pf.height; h++) {
        for (int w = 0; w < pf.width; w++) {
            if (pf.stoneat(w,h) == pf.none){
                return false;
            }}}
    return true;
}

bool game_finished(int hOrg, int wOrg, playfield &pf){

    int h = hOrg;
    int w = wOrg;
    //check vertical
    if(sum_direction(h, w, 1, 0,  pf) >=3){
        return true;
    }
        //check horizontal
    else if(sum_direction(h, w, 0, 1,  pf) + sum_direction(h, w, 0, -1,  pf) >= 3){
        return true;
    }
        //check to top left and button right
    else if(sum_direction(h, w, -1, -1,  pf) + sum_direction(h, w, 1, 1,  pf) >= 3){
        return true;
    }
        //check to top right and button left
    else if(sum_direction(h, w, -1, 1,  pf) + sum_direction(h, w, 1, -1,  pf) >= 3){
        return true;
    }
    else{
        return false;
    }

}

int insert_stone(playfield &pf, int w, int playerNr) {
    if (pf.stoneat(w, 0) != pf.none){
        cout << "this column is already full pick a different one" << endl;
        return -1;}
    int h = 0;
    while(pf.stoneat(w, h+1) == pf.none && h+1 < playfield::height) {
        h++;
    }
    if (playerNr == 1){pf.rep[w][h] = pf.player1;}
    else {pf.rep[w][h] = pf.player2;}

    return h;

}

int main() {
    playfield pf;
    factory<playfield> ft;
    //human<playfield> player1;

    //my computer player
    auto p1 = ft.getPlayer("computer1");
    com_dom<playfield> p2 = {2};

    for (int h = 0; h < playfield::height; h++) {
        for (int w = 0; w < pf.width; w++) {
            pf.rep[w][h] = pf.none;}
    }

    print_playfield(pf);
    int turn = 0;
    for(;;) {
        int w;
        int h = -1;
        while (h < 0){
            if (turn == 0){
                w = p1->play(pf);
            }
            else{
                w = p2.play(pf);

            }
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

/*
Implement the “Connect 4” game using inheritance § Reuse your template-based implementation for the
    implementation of the inheritance-based version of “Connect 4”
- Interfaces to be used, to be published
- In your inheritance-based implementation of the classes, you can simply
    delegate all functionality to the template-based implementation
- If you use a generic template-based wrapper for the player interface, it
    works with your colleague’s connect 4 players
*/

/*
You obtained already computer players from  your colleagues
Create those computer players with a factory
- In the most simplistic way, implement like the one on this slide deck
- However, you should be able to discuss the design
- Would you have to change your code to add additional players?
- How would you have to change your code?
*/