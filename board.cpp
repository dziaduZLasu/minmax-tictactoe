/* 
 * File:   board.cpp
 * Author: artur
 * 
 * Created on 20 maj 2012, 11:43
 */

#include "board.h"
#include<iostream>

board::board() {
    player = 'O';
    for (int i = 1; i <= 9; i++) boardTab[i] = ' ';
}

board::board(const board& orig) {
}

board::~board() {
}

void board::draw() {
    for (int i = 1; i <= 9; i++) {
        std::cout << " " << boardTab[i] << " ";
        if (i % 3) std::cout << "|";
        else if (i != 9) std::cout << "\n---+---+---\n";
        else std::cout << std::endl;
    }
}

bool board::win(char Cplayer, bool verbose) {
    bool test = false;
    int i;

    // Sprawdzam wiersze
    for (i = 1; i <= 7; i += 3) test |= ((boardTab[i] == Cplayer) && (boardTab[i + 1] == Cplayer) && (boardTab[i + 2] == Cplayer));

    // Sprawdzam kolumny  
    for (i = 1; i <= 3; i++) test |= ((boardTab[i] == Cplayer) && (boardTab[i + 3] == Cplayer) && (boardTab[i + 6] == Cplayer));

    // Sprawdzam przekątną 1-5-9
    test |= ((boardTab[1] == Cplayer) && (boardTab[5] == Cplayer) && (boardTab[9] == Cplayer));

    // Sprawdzam przekątną 3-5-7
    test |= ((boardTab[3] == Cplayer) && (boardTab[5] == Cplayer) && (boardTab[7] == Cplayer));

    if (test) {
        if (!verbose) {
            draw();
            std::cout << "\nGRACZ " << Cplayer << " WYGRYWA!!!\n\n";
        }
        return true;
    }
    return false;
}

bool board::tie(char Cplayer, bool verbose) {

    for (int i = 1; i <= 9; i++) if (boardTab[i] == ' ') return false;

    if (!verbose) {
        draw();
        std::cout << "\nREMIS\n\n";
    }
    return true;
}

void board::move() {
    int currMove;

    draw();
    if (player == 'O') { //CZŁOWIEK
        std::cout << "\nO : wybiera ruch : ";
        std::cin >> currMove;
    } else { // KOMPUTER
        int ruch, i, m, mmx;
        mmx = -10;
        for (i = 1; i <= 9; i++)
            if (boardTab[i] == ' ') {
                boardTab[i] = 'X';
                m = minimax('X');
                boardTab[i] = ' ';
                if (m > mmx) {
                    mmx = m;
                    ruch = i;
                }
            }


        currMove = ruch;

        std::cout << "\nX : wybiera ruch : " << currMove << std::endl;
    }
    std::cout << "---------------------------\n\n";
    if ((currMove >= 1) && (currMove <= 9) && (boardTab[currMove] == ' ')) boardTab[currMove] = player;
    player = (player == 'O') ? 'X' : 'O';
}

int board::minimax(char currPlayer) {
    int move, mmx;

    //czy już wygrał
    if (win(currPlayer, true)) return (currPlayer == 'X') ? 1 : -1;

    // remis ?
    if (tie(currPlayer, true)) return 0;

    //sprawdzam ruchy przeciwnika
    currPlayer = (currPlayer == 'X') ? 'O' : 'X';


    // min max zależnie czyje ruchy sprawdzam
    mmx = (currPlayer == 'O') ? 10 : -10;


    // rekurencyjnie drzewo gry dla node'a wywołanego z board::move()
    for (int i = 1; i <= 9; i++)
        if (boardTab[i] == ' ') {
            boardTab[i] = currPlayer;
            move = minimax(currPlayer);
            boardTab[i] = ' ';
            if (((currPlayer == 'O') && (move < mmx)) || ((currPlayer == 'X') && (move > mmx))) mmx = move;
        }
    return mmx;
}


