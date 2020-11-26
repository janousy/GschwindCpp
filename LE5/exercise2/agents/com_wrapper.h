//
// Created by Janosch Baltensperger on 20.11.20.
//

#ifndef EXERCISE4_COM_WRAPPER_H
#define EXERCISE4_COM_WRAPPER_H

#include "human.h"
#include "computer1.h"
#include "computer2.h"
#include "computer3.h"
#include "computer4.h"
#include "computer5.h"
#include "../playfield.h"

struct wrap2com1 : public player {
private:
    computer1<playfield> cp;
public:
    wrap2com1(computer1<playfield> c) : cp(c) {}
    int play(const playfield &field) override{
        return cp.play(field);
    }
};

struct wrap2com2 : public player {
private:
    computer2<playfield> cp;
public:
    wrap2com2(computer2<playfield> c) : cp(c) {}
    int play(const playfield &field) override{
        return cp.play(field);
    }
};

struct wrap2com3 : public player {
private:
    computer3<playfield> cp;
public:
    wrap2com3(computer3<playfield> c) : cp(c) {}
    int play(const playfield &field) override{
        return cp.play(field);
    }
};

struct wrap2com4 : public player {
private:
    computer4<playfield> cp;
public:
    wrap2com4(computer4<playfield> c) : cp(c) {}
    int play(const playfield &field) override{
        return cp.play(field);
    }
};

struct wrap2com5 : public player {
private:
    computer5<playfield> cp;
public:
    wrap2com5(computer5<playfield> c) : cp(c) {}
    int play(const playfield &field) override{
        return cp.play(field);
    }
};

struct wrap2human : public player {
private:
    human<playfield> h;
public:
    wrap2human(human<playfield> h1) : h(h1) {}
    int play(const playfield &field) override{
        return h.play(field);
    }
};

//would have been nicer to use a single wrapper for all computer types, but player is abstract


#endif //EXERCISE4_COM_WRAPPER_H
