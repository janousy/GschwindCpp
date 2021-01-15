//
// Created by Janosch Baltensperger on 26.11.20.
//

#ifndef EXERCISE2_HELPER_H
#define EXERCISE2_HELPER_H

#include "playfield.h"
#include <iostream>
using namespace std;

void print_playfield(playfield &pf) {
    for (int h = 0; h < pf.height; h++) {
        for (int w = 0; w < pf.width; w++) {
            cout << pf.stoneat(w, h) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

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

#endif //EXERCISE2_HELPER_H
