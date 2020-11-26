//
// Created by Janosch Baltensperger on 26.11.20.
//

#ifndef EXERCISE2_COMPUTER5_H
#define EXERCISE2_COMPUTER5_H

#include <iostream>
using namespace std;

// by Ives Boutellier
template <typename F>
struct computer5 {
    char number;
    char opponent;
    static const int width = 7;
    static const int height = 6;
    computer5(int i): number(i){};

    char rep[width][height];

    void set_number(int tag) {
        number = tag;
        if (number == 1){
            opponent = 2;
        }else{
            opponent = 1;
        }
    }

    int stoneat(int x, int y) const {
        return rep[x][y];
    }

    int gravity(int x) {
        int y = 0;
        for (int yi = y; yi < (height - 1); yi++) {
            if (stoneat(x, yi + 1) == 0) {
                y++;
            } else break;
        }
        return y;
    }

    bool is_Empty(int x, int y){
        if (stoneat(x,y) != 0) {
            std::cout << "the Input position is not empty"<< std::endl;
            return false;}
        else{
            return true;
        }}

    bool check_possibilities(int x, int y, int k, char player) {
        int xi;
        int yi;
        int counter = 0;
        //std::cout << "Horizontal check"  << std::endl;
        for (xi = 0; xi <= ((int) width) - 1; xi++) {
            if (stoneat(xi, y) == player) { counter++;}
            else {counter = 0;}
            if (counter >= k) { return true; }
        }
        //
        counter = 0;
        //vertical check
        for (yi = 0; yi <= ((int) height) - 1; yi++) {
            //std::cout << "vertical check" << counter << std::endl;
            if (stoneat(x, yi) == player) { counter++; }
            else counter = 0;
            if (counter >= k) { return true; }
        }

        counter = 0;
        // diagonal down right check;
        xi = x;
        yi = y;
        for (;;) {
            //std::cout << "diagonal down right check" << counter << std::endl;
            if ((xi > ((int) width - 1)) || (yi > ((int) height - 1))) {break;}
            if (stoneat(xi, yi) == player) counter++;
            else {break;}
            if (counter >= k) { return true; }
            xi++;
            yi++;

        }
        //std::cout << counter;
        counter--;
        //diagonal up left check
        xi = x;
        yi = y;
        for (;;) {
            //std::cout << "diagonal up left check" << counter << std::endl;
            if ((xi < 0) || (yi < 0)) {break;}
            if (stoneat(xi, yi) == player) counter++;
            else {break;}
            if (counter >= k) { return true; }
            xi--;
            yi--;
        }

        //std::cout << counter;
        counter = 0;
        //diagonal up right check
        xi = x;
        yi = y;
        for (;;) {
            //std::cout << "diagonal up right check" << counter << std::endl;
            if ((xi > ((int) width - 1)) || (yi < 0)) {break;}
            if (stoneat(xi, yi) == player) counter++;
            else {break;}
            if (counter >= k) { return true; }
            xi++;
            yi--;
        }
        counter--;
        //diagonal down left check
        xi = x, yi = y;
        for (;;) {
            if ((xi < 0) || (yi > ((int) height - 1))) {break;}
            if (stoneat(xi, yi) == player) counter++;
            else {break;}
            if (counter >= k) { return true; }
            xi--;
            yi++;
        }
    }

    int get_move() {
        // do all x, for each let gravity work, insert into representation, then evaluate which is best
        int x, y;
        int output;

        for (int xi = 0; xi < width; xi++) {
            x = xi;
            if (!is_Empty(x, 0)) {
                continue;
            }
            y = gravity(x);

            rep[x][y] = opponent;
            /*
            std::cout << "__________________" << std::endl;
            std::cout << "CHECKING FOR OPPONENT" << std::endl;
            std::cout << "__________________" << std::endl;
            std::cout << "__________________" << std::endl;
             */
            if (check_possibilities(x, y, 4, opponent)) {
                output = x;
                return output;
            }
            rep[x][y] = 0;
        }


        for (int k = 4; k > 1; k--) {
            for (int xi = 0; xi < width; xi++) {
                x = xi;
                if (!is_Empty(x, 0)) {
                    continue;
                }
                y = gravity(x);
                rep[x][y] = number;
                /*
                std::cout << "________" << k << "__________" << std::endl;
                std::cout << "CHECKING FOR MYSELF" << std::endl;
                std::cout << "__________________" << std::endl;
                std::cout << "__________________" << std::endl;*/
                if (check_possibilities(x, y, k, number)) {
                    //std::cout << k << " saw a chance for myself" << std::endl;

                    output = x;
                    return output;
                }
                rep[x][y] = 0;
            }

        }

        srand((unsigned) time(0));
        int randomNumber;
        randomNumber = (rand() % 6) + 1;
        output = randomNumber;

        return output;
    };

    int play(const F &field){
        int x;
        char player;
        for (int w =0; w < width; w++){
            for (int h=0; h < height; h++){
                player = field.stoneat(w,h);
                rep[w][h] = player;}}

        x = get_move();
        return x;
    }
};


#endif //EXERCISE2_COMPUTER5_H
