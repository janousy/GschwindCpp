#include "myPlayfield.h"
#include <iostream>
#include "agents/human.h"
#include "factory.h"
#include "helper.h"

using namespace std;

int insert_stone(myPlayfield &pf, int w, int playerNr) {
    if (pf.stoneat(w, 0) != pf.none) {
        cout << "this column is already full pick a different one" << endl;
        return -1;
    }
    int h = 0;
    while (pf.stoneat(w, h + 1) == pf.none && h + 1 < myPlayfield::height) {
        h++;
    }
    if (playerNr == 1) { pf.rep[w][h] = pf.player1; }
    else { pf.rep[w][h] = pf.player2; }

    return h;

}

int main() {
    myPlayfield pf;
    factory ft;

    auto p1 = ft.getPlayer("computer1");
    auto p2 = ft.getPlayer("computer5");

    for (int h = 0; h < myPlayfield::height; h++) {
        for (int w = 0; w < pf.width; w++) {
            pf.rep[w][h] = pf.none;
        }
    }

    print_playfield(pf);

    int turn = 0;
    for (;;) {
        int w;
        int h = -1;
        while (h < 0) {
            if (turn == 0) {
                w = p1->play(pf);
            } else {
                w = p2->play(pf);

            }
            h = insert_stone(pf, w, turn + 1);
        }
        print_playfield(pf);
        if (game_finished(h, w, pf)) {
            cout << "Game Finished player" << " " << turn + 1 << " " << "won" << endl;
            break;
        }
        if (boardFull(pf)) {
            cout << "Draw because board is full" << endl;
            break;
        }
        turn = (turn + 1) % 2;
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
You obtained already computer1 players from  your colleagues
Create those computer1 players with a factory
- In the most simplistic way, implement like the one on this slide deck
- However, you should be able to discuss the design
- Would you have to change your code to add additional players?
- How would you have to change your code?
*/