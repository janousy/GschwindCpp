//
// Created by Janosch Baltensperger on 20.11.20.
//
#include "com_wrapper.h"

template <typename F>
int com_wrapper<F>::play(const playfield &field) {
    int pos = cp.play(field);
    return pos;
}