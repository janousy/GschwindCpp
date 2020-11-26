//
// Created by Janosch Baltensperger on 24.11.20.
//

#ifndef EXERCISE2_FACTORY_H
#define EXERCISE2_FACTORY_H

#include <string>
#include "agents/player.h"
#include "agents/computer1.h"
#include "agents/com_wrapper.h"

using namespace std;

class factory {
public:
    player *getPlayer(const string &type);
};


#endif //EXERCISE2_FACTORY_H
