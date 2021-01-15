//
// Created by Janosch Baltensperger on 30.10.20.
//

#include "computer1.h"
#include "computer1.h"
#include <iostream>

using namespace std;

//make one file

template<typename F>
int computer1<F>::play(const F &pf) {
    cout << "My computer1 player plays" << endl;
    //if possible win the game
    int c = canWin(pf);
    if (c != -1) {
        return c;
    }
    //try to keep the enemy from winning, by placing a stone at the pos where he could win
    //only possible if enemy doesnt have 2 pos where he can win, but then we should still take im 1 option
    c = otherPlayerCanWin(pf);
    if (c != -1) {
        return c;
    }

    //else place the stone such that it forms the max nr of connected stones
    return maximizeConnectedStones(pf);
}

template <typename F>
vector<int> computer1<F>::possibleStonePosition(const F &pf) {
    vector<int> pos;
    for(int x=0; x<pf.width; x++){
        if (pf.stoneat(x, 0) != pf.none){
            pos.push_back(-1);
        }
        else{
            int y=0;
            while(pf.stoneat(x, y+1) == pf.none && y+1 < pf.height) {
                y++;
            }
            pos.push_back(y);
        }
    }
    return pos;
}

template <typename F>
int computer1<F>::sum_direction(char pS, int hOrg, int wOrg, int hDir, int wDir, const F &pf) {
    int h = hOrg + hDir;
    int w = wOrg + wDir;
    int sum = 0;

    while (h< pf.height && h>= 0 && w < pf.width && w >= 0){

        if(pS == pf.stoneat(w, h)){
            sum = sum +1;
            h = h + hDir;
            w = w + wDir;
        }
        else{
            break;
        }
    }
    return sum;
}

//return the column nr where inserting the stone results in winning the game
//-1 if no possible pos to win the game
template <typename F>
int computer1<F>::canWin(const F &pf) {
    vector<int> pos = possibleStonePosition(pf);

    int x = 0;
    for (vector<int>::iterator it = pos.begin(); it != pos.end(); ++it, x++) {
        if (*it != -1) {
            if (sum_direction(playerSign, *it, x,  1, 0, pf) >= 3) {
                return x;
            }
                //check horizontal
            else if (sum_direction(playerSign, *it, x,  0, 1, pf) + sum_direction(playerSign, *it,  x,0, -1, pf) >= 3) {
                return x;
            }
                //check to top left and button right
            else if (sum_direction(playerSign, *it,  x, -1, -1, pf) + sum_direction(playerSign,  *it, x,1, 1, pf) >= 3) {
                return x;
            }
                //check to top right and button left
            else if (sum_direction(playerSign,  *it, x, -1, 1, pf) + sum_direction(playerSign,  *it,x, 1, -1, pf) >= 3) {
                return x;
            }
        }
    }
    return -1;
}


//return the column nr where if the enemy inserts the stone results in winning the game
//-1 if no possible pos to win the game
template <typename F>
int computer1<F>::otherPlayerCanWin(const F &pf){
    char otherPlayerSign;
    if(playerSign == pf.player1){
        otherPlayerSign = pf.player2;
    }
    else{
        otherPlayerSign = pf.player1;
    }
    vector<int> pos = possibleStonePosition(pf);
    int x = 0;
    for (vector<int>::iterator it = pos.begin(); it != pos.end(); ++it, x++) {
        if (*it != -1) {
            if (sum_direction(otherPlayerSign, *it, x, 1, 0, pf) >= 3) {
                return x;
            }
                //check horizontal
            else if (sum_direction(otherPlayerSign,  *it, x,  0, 1, pf) + sum_direction(otherPlayerSign,  *it, x, 0, -1, pf) >= 3) {
                return x;
            }
                //check to top left and bottom right
            else if (sum_direction(otherPlayerSign, *it,  x,-1, -1, pf) + sum_direction(otherPlayerSign,  *it, x, 1, 1, pf) >= 3) {
                return x;
            }
                //check to top right and bottom left
            else if (sum_direction(otherPlayerSign, *it, x, -1, 1, pf) + sum_direction(otherPlayerSign, *it, x, 1, -1, pf) >= 3) {
                return x;
            }
        }

    }
    return -1;
}


template <typename F>
int computer1<F>::maximizeConnectedStones(const F &pf) {

    vector<int> pos = possibleStonePosition(pf);
    int max = -1;
    int maxPos;
    int x = 0;
    int sum[4];
    for (vector<int>::iterator it = pos.begin(); it != pos.end(); it++) {

        if (*it != -1) {
            sum[0] = sum_direction(playerSign, *it, x, 1, 0, pf);
            sum[1] = sum_direction(playerSign, *it, x, 0, 1, pf) + sum_direction(playerSign, *it, x, 0, -1, pf);
            sum[2] = sum_direction(playerSign, *it, x, -1, -1, pf) + sum_direction(playerSign, *it, x, 1, 1, pf);
            sum[3] = sum_direction(playerSign, *it, x, -1, 1, pf) + sum_direction(playerSign, *it, x, 1, -1, pf);

            int maxSum = -1;
            for (int i = 0; i < 4; i++) {
                if (sum[i] > maxSum) { maxSum = sum[i]; }
            }
            if (maxSum > max) {
                max = maxSum;
                maxPos = x;
            }
        }
        x = x + 1;
    }
    return maxPos;
}