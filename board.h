/* 
 * File:   board.h
 * Author: artur
 *
 * Created on 20 maj 2012, 11:43
 */

#ifndef BOARD_H
#define	BOARD_H

class board {
public:
    board();
    board(const board& orig);
    virtual ~board();

    void draw();
    bool win(char Cplayer, bool verbose); // Cplayer == current player
    bool tie(char Cplayer, bool verbose);
    void move(); 
    int minimax(char currPlayer);

private:
    char boardTab [10];
    char player;


};

#endif	/* BOARD_H */

