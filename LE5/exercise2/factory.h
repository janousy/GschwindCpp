//
// Created by Janosch Baltensperger on 24.11.20.
//

#ifndef EXERCISE2_FACTORY_H
#define EXERCISE2_FACTORY_H

#include <string>
#include "agents/player.h"
#include "agents/human.h"
#include "agents/computer.h"
#include "agents/com_wrapper.h"

using namespace std;

template<typename F>
class factory {
public:
    player *getPlayer(const string &type) {
        if (type == "computer1") {
            computer<playfield> cp(1);
            auto wrapper = new com_wrapper<F>(cp);
            return wrapper;
        } else {
            cout << "invalid type" << endl;
        }
    }
};


#endif //EXERCISE2_FACTORY_H
