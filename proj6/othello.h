/*
 *  Austin McKibben  
 *  CS2401
 * 
 *  Header file for the Othello class.
 *  The board is represented by an 8x8
 *  matrix. The class has functions to 
 *  make moves, as well as find legal
 *  moves. It will display the board 
 *  once per turn. The computer will
 *  automatically play the white player
 * 
 */

#ifndef OTHELLO_H
#define OTHELLO_H
#include <iostream>
#include <queue>
#include <string> 
#include "game.h"
#include "space.h"

class Othello:public main_savitch_14::game {
    public:

        Othello();

        std::string get_user_move()const;
        who winning()const;

        void make_move(const std::string& move);
        virtual void restart();
        
        main_savitch_14::game* clone()const;
        void compute_moves(std::queue<std::string>& moves)const;
        void display_status()const;
        int evaluate()const;
        bool is_game_over()const;
        bool is_legal(const std::string& move)const;

    private:
        space board[8][8];
        char pass_counter;

        // count pieces
        int count_black()const;
        int count_white()const;

        // private booleans, used to varify valid moves in each direction, for each color
        bool b_checkup(int row, int column)const;
        bool b_checkupright(int row, int column)const;
        bool b_checkright(int row, int column)const;
        bool b_checkdownright(int row, int column)const;
        bool b_checkdown(int row, int column)const;
        bool b_checkdownleft(int row, int column)const;
        bool b_checkleft(int row, int column)const;
        bool b_checkupleft(int row, int column)const;

        bool w_checkup(int row, int column)const;
        bool w_checkupright(int row, int column)const;
        bool w_checkright(int row, int column)const;
        bool w_checkdownright(int row, int column)const;
        bool w_checkdown(int row, int column)const;
        bool w_checkdownleft(int row, int column)const;
        bool w_checkleft(int row, int column)const;
        bool w_checkupleft(int row, int column)const;
};

#endif