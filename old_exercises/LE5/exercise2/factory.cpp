//
// Created by Janosch Baltensperger on 24.11.20.
//

#include <iostream>
#include "factory.h"
#include "playfield.h"
#include "agents/com_wrapper.h"
#include "agents/player.h"
#include "agents/computer1.h"
#include "agents/computer1.cpp"

using namespace std;

/*
 * could use a map<string, player> if not different wrapper for every computer
 * read map inputs from config file
*/
player *factory::getPlayer(const string &type) {
    if (type == "human") {
        human<playfield> h;
        return new wrap2human(h);
    }
    else if (type == "computer1") {
        computer1<playfield> c(1);
        return new wrap2com1(c);
    }
    else if (type == "computer2") {
        computer2<playfield> c;
        return new wrap2com2(c);
    }
    else if (type == "computer3") {
        computer3<playfield> c;
        return new wrap2com3(c);
    }
    else if (type == "computer4") {
        computer4<playfield> c(1);
        return new wrap2com4(c);
    }
    else if (type == "computer5") {
        computer5<playfield> c(1);
        return new wrap2com5(c);
    }
}

/*
 * could use a map config file with types and associated wrapper objects
 * however, wrapper would still need to be extended
 * => probably xml files with type objects and corresponding objects
 * => would require a better solution for wrapper (provide wrapper with computer?)
 */