//
// Created by Janosch Baltensperger on 22.11.20.
//

#ifndef EXERCISE4_PLAYER_H
#define EXERCISE4_PLAYER_H

#include "../myPlayfield.h"
#include "../playfield.h"


class player {
public:
    virtual int play(const playfield &field) = 0;
};

#endif //EXERCISE4_PLAYER_H
