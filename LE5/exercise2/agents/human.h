//
// Created by Janosch Baltensperger on 09.10.20.
//

#ifndef EXERCISE4_HUMAN_H
#define EXERCISE4_HUMAN_H

#include <iostream>
#include "../myPlayfield.h"
#include "player.h"
using namespace std;

template<typename F>
class human : public player {
public:
    int play(const F &field) {
        int w;
        cout << "turn: ";
        cin >> w;
        return w;
    };
};

#endif //EXERCISE4_HUMAN_H
