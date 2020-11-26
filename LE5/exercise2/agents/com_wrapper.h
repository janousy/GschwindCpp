//
// Created by Janosch Baltensperger on 20.11.20.
//

#ifndef EXERCISE4_COM_WRAPPER_H
#define EXERCISE4_COM_WRAPPER_H

#include "player.h"
#include "computer.h"

template <typename F>
struct com_wrapper : public player {
private:
    computer<F> cp;
public:
    com_wrapper<F>(computer<F> c) : cp(c) {}
    int play(const playfield &field) override;
};

#endif //EXERCISE4_COM_WRAPPER_H
