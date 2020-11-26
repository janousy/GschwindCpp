//
// Created by Janosch Baltensperger on 30.10.20.
//

#ifndef EX4_CPLAYER_H
#define EX4_CPLAYER_H
#include "../playfield.h"
#include "vector"

using namespace std;

template<typename F>
struct computer{
private:
    char playerSign;
    int sum_direction(char pS, int hOrg, int wOrg, int hDir, int wDir,  const F &playfield);
    vector<int> possibleStonePosition(const F &playfield);
    int canWin(const F &field);
    int otherPlayerCanWin(const F &field);
    int maximizeConnectedStones(const F &field);
public:
    computer<F>(char sign) : playerSign(sign){
    };
    int play(const F &field);
};

#endif//EX4_CPLAYER_H
