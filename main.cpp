/* 
 * File:   main.cpp
 * Author: artur
 *
 * Created on 19 maj 2012, 16:32
 */

#include <cstdlib>
#include<iostream>
#include <vector>
#include"board.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    board *game = new board();
    while (!game->win('X', false) && !game->tie('X', false) && !game->win('O', false) && !game->tie('O', false)) game->move();
    return 0;
}

