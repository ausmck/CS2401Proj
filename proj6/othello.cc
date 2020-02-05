/*
 *  Austin McKibben  
 *  CS2401
 * 
 *  Implementation file for the Othello class
 * 
 */


#include <iostream>
#include <queue>
#include <string> 
#include "game.h"
#include "space.h"
#include "othello.h"

using namespace std;



Othello::Othello() {
    pass_counter = 0;
    restart();
}

string Othello::get_user_move()const {
    queue<string> q;
    compute_moves(q);
    if(q.empty()) {
        return "XX";
    }
    return main_savitch_14::game::get_user_move();

}

main_savitch_14::game::who Othello::winning()const {
    int black = count_black();
    int white = count_white();

    if(black > white) {
        return HUMAN;
    } else if(black < white) {
        return COMPUTER;
    } else {
        return NEUTRAL;
    }
}

void Othello::make_move(const std::string& move) {

    if(move == "XX") {
        main_savitch_14::game::make_move("XX");
        ++pass_counter;
        return;
    } else {
        pass_counter = 0 ;
    }

    int column = move[0] - 'A';
    int row = move[1] - '1';
   
    if(next_mover() == HUMAN) {
        board[row][column].make_black();

        // check down
        if(b_checkdown(row, column)) {
        if(board[row+1][column].is_white()) {
            for(int i = 1; board[row+i][column].is_white(); ++i) {
                board[row+i][column].flip();
            }
        }
        }

        // check down and right
        if(b_checkdownright(row, column)) {
        if(board[row+1][column+1].is_white()) {
            for(int i = 1; board[row+i][column+i].is_white(); ++i) {
                board[row+i][column+i].flip();
            }
        }
        }

        // check right
        if(b_checkright(row, column)) {
        if(board[row][column+1].is_white()) {
            for(int i = 1; board[row][column+i].is_white(); ++i) {
                board[row][column+i].flip();
            }
        }
        }
    
        // check up and right
        if(b_checkupright(row, column)) {
        if(board[row-1][column+1].is_white()) {
            for(int i = 1; board[row-i][column+i].is_white(); ++i) {
                board[row-i][column+i].flip();
            }
        }
        }

        // check up
        if(b_checkup(row, column)) {
        if(board[row-1][column].is_white()) {
            for(int i = 1; board[row-i][column].is_white(); ++i) {
                board[row-i][column].flip();
            }
        }
        }

        // check up and left
        if(b_checkupleft(row, column)) {
        if(board[row-1][column-1].is_white()) {
            for(int i = 1; board[row-i][column-i].is_white(); ++i) {
                board[row-i][column-i].flip();
            }
        }
        }

        // check left
        if(b_checkleft(row, column)) {
        if(board[row][column-1].is_white()) {
            for(int i = 1; board[row][column-i].is_white(); ++i) {
                board[row][column-i].flip();
            }
        }
        }

        // check down and left
        if(b_checkdownleft(row, column)) {
        if(board[row+1][column-1].is_white()) {
            for(int i = 1; board[row+i][column-i].is_white(); ++i) {
                board[row+i][column-i].flip();
            }
        }
        }
    }

    if(next_mover() == COMPUTER) {
        board[row][column].make_white();

        if(w_checkdown(row, column)) {
        if(board[row+1][column].is_black()) {
            for(int i = 1; board[row+i][column].is_black(); ++i) {
                board[row+i][column].flip();
            }
        }
        }

        if(w_checkdownright(row, column)) {
        if(board[row+1][column+1].is_black()) {
            for(int i = 1; board[row+i][column+i].is_black(); ++i) {
                board[row+i][column+i].flip();
            }
        }
        }

        if(w_checkright(row, column)) {
        if(board[row][column+1].is_black()) {
            for(int i = 1; board[row][column+i].is_black(); ++i) {
                board[row][column+i].flip();
            }
        }
        }
    
        if(w_checkupright(row, column)) {
        if(board[row-1][column+1].is_black()) {
            for(int i = 1; board[row-i][column+i].is_black(); ++i) {
                board[row-i][column+i].flip();
            }
        }
        }

        if(w_checkup(row, column)) {
        if(board[row-1][column].is_black()) {
            for(int i = 1; board[row-i][column].is_black(); ++i) {
                board[row-i][column].flip();
            }
        }
        }

        if(w_checkupleft(row, column)) {
        if(board[row-1][column-1].is_black()) {
            for(int i = 1; board[row-i][column-i].is_black(); ++i) {
                board[row-i][column-i].flip();
            }
        }
        }

        if(w_checkleft(row, column)) {
        if(board[row][column-1].is_black()) {
            for(int i = 1; board[row][column-i].is_black(); ++i) {
                board[row][column-i].flip();
            }
        }
        }

        if(w_checkdownleft(row, column)) {
        if(board[row+1][column-1].is_black()) {
            for(int i = 1; board[row+i][column-i].is_black(); ++i) {
                board[row+i][column-i].flip();
            }
        }
        }
    }
    main_savitch_14::game::make_move("XX");
}

void Othello::restart() {
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            board[i][j].make_empty();
        }
    }
    
    board[3][3].make_white();
    board[3][4].make_black();
    board[4][3].make_black();
    board[4][4].make_white();
    pass_counter = 0;
}

main_savitch_14::game* Othello::clone()const {
    return new Othello(*this);
}

void Othello::compute_moves(queue<string>& moves)const {
    char c[2];
    c[0] = 'A';
    c[1] = '1';
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            string s = "";
            s += c[0];
            s += c[1];
            if(is_legal(s)) {
                moves.push(s);
            }
            c[1]++;
        }
        c[0]++;
        c[1] = '1';
    }
}

void Othello::display_status()const {
    // variables to hold unicode boarder elements
    string white = "\u2593";
    string black = "\u2591";
    string empty = "   ";
    string dnr = "\u250F";
    string dnl = "\u2513";
    string unr = "\u2517";
    string unl = "\u251B";
    string hline = "\u2501";
    string vline = "\u2503";
    string cross = "\u254B";
    string lnrnu = "\u253B";
    string lnrnd = "\u2533";
    string rnund = "\u2523";
    string lnund = "\u252B";

    // head info
    cout << "Turn : " << moves_completed() << "  White : " << count_white() 
        << "  Black : " << count_black() << endl;

    // grid
    cout << hline << hline << hline << hline << hline << hline << hline <<
        hline << hline << hline << hline << hline << hline << hline << hline <<
        hline << hline << hline << hline << hline << hline << hline << hline <<
        hline << hline << hline << hline << hline << hline << hline << hline << 
        hline << hline << hline << hline << endl;
    
    cout << "    A   B   C   D   E   F   G   H" << endl;

    cout << "  " << dnr << hline << hline << hline << lnrnd << hline << hline << hline << lnrnd << 
        hline << hline << hline << lnrnd << hline << hline << hline << lnrnd << hline << 
        hline << hline << lnrnd << hline << hline << hline << lnrnd << hline << hline << hline <<
        lnrnd << hline << hline << hline << dnl << endl;

    for(int i = 0; i < 8; ++i) {        
        cout << i+1 << ' ' << vline;
        for(int j = 0; j < 8; ++j) {
            if(board[i][j].is_empty()) {
                cout << empty;
            } else if(board[i][j].is_black()) {
                cout << black << black << black;
            } else {
                cout << white << white << white;
            }
            cout << vline;
        }
        cout << endl;
        if(i != 7) {
            cout << "  " << rnund << hline << hline << hline << cross << hline << 
                hline << hline << cross << hline << hline << hline << cross << 
                hline << hline << hline << cross << hline << hline << hline << 
                cross << hline << hline << hline << cross << hline << 
                hline << hline << cross << hline << hline << hline << lnund << 
                endl;
        }
    }

    
    cout << "  " << unr << hline << hline << hline << lnrnu << hline << hline << hline << lnrnu << 
        hline << hline << hline << lnrnu << hline << hline << hline << lnrnu << hline << 
        hline << hline << lnrnu << hline << hline << hline << lnrnu << hline << hline << hline << 
        lnrnu << hline << hline << hline << unl << endl;

}

int Othello::evaluate()const {
    int w = count_white();
    int b = count_black();
    return w-b;
}

bool Othello::is_game_over()const {
    if(moves_completed() == 60) {
        return true;
    } else if(pass_counter == 2){ 
        return true;
    } else {
        return false;
    }
}

bool Othello::is_legal(const std::string& move)const {
    int column = move[0] - 'A';
    int row = move[1] - '1';

    if(board[row][column].is_empty()) 
    {
    if(next_mover() == HUMAN) {
        if(b_checkup(row, column)) 
            return true;

        if(b_checkupright(row, column))
            return true;
        
        if(b_checkright(row, column))
            return true;

        if(b_checkdownright(row, column))
            return true;

        if(b_checkdown(row, column))
            return true;

        if(b_checkdownleft(row, column))
            return true;

        if(b_checkleft(row, column))
            return true;

        if(b_checkupleft(row, column))
            return true;
    }

    if(next_mover() == COMPUTER) {
        if(w_checkup(row, column)) 
            return true;

        if(w_checkupright(row, column))
            return true;
        
        if(w_checkright(row, column))
            return true;

        if(w_checkdownright(row, column))
            return true;

        if(w_checkdown(row, column))
            return true;

        if(w_checkdownleft(row, column))
            return true;

        if(w_checkleft(row, column))
            return true;

        if(w_checkupleft(row, column))
            return true;
    }
    }

    return false;
}

int Othello::count_black()const {
    int black = 0;
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            if(board[i][j].is_black()) {
                ++black;
            }
        }
    }
    return black;
}

int Othello::count_white()const {
    int white = 0;
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            if(board[i][j].is_white()) {
                ++white;
            }
        }
    }
    return white;
}

bool Othello::b_checkup(int row, int column)const {
    if(board[row-1][column].is_white() && ((row-1) > 0)) {  // check that the loop doesn't go out of bounds
        for(int i = 1; board[row-i][column].is_white() && ((row-i-1) >= 0); ++i) { // go along path, ensuring it doesn't go outside of the grid
            if(board[row-i-1][column].is_black()) { // once we run into a piece
                return true; // we know this is a valid move
            }
        }
    }
    return false;
}

bool Othello::b_checkupright(int row, int column)const {
    if(board[row-1][column+1].is_white() && ((row-1) > 0) && ((column+1) < 7)) {
        for(int i = 1; board[row-i][column+i].is_white() && ((row-i-1) >= 0) && ((column+i+1) <= 7); ++i) {
            if(board[row-i-1][column+i+1].is_black()) {
                return true;
            }
        }
    }
    return false;
}

bool Othello::b_checkright(int row, int column)const {
    if(board[row][column+1].is_white() && ((column+1) < 7)) {
        for(int i = 1; board[row][column+i].is_white() && ((column+i+1) <= 7); ++i) {
            if(board[row][column+i+1].is_black()) {
                return true;
            }
        }
    }
    return false;
}

bool Othello::b_checkdownright(int row, int column)const {
    if(board[row+1][column+1].is_white() && ((row+1) < 7) && ((column+1) < 7)) {
        for(int i = 1; board[row+i][column+i].is_white() && ((row+i+1) <= 7) && ((column+i+1) <= 7); ++i) {
            if(board[row+i+1][column+i+1].is_black()) {
                return true;
            }
        }
    }
    return false;
}

bool Othello::b_checkdown(int row, int column)const {
    if(board[row+1][column].is_white() && ((row+1) < 7)) {
        for(int i = 1; board[row+i][column].is_white() && ((row+i+1) <= 7); ++i) {
            if(board[row+i+1][column].is_black()) {
                return true;
            }
        }
    }
    return false;
}
bool Othello::b_checkdownleft(int row, int column)const {
    if(board[row+1][column-1].is_white() && ((row+1) < 7) && ((column-1) > 0)) {
        for(int i = 1; board[row+i][column-i].is_white() && ((row+i+1) <= 7) && ((column-i-1) >= 0); ++i) {
            if(board[row+i+1][column-i-1].is_black()) {
                return true;
            }
        }
    }
    return false;
}

bool Othello::b_checkleft(int row, int column)const {
    if(board[row][column-1].is_white() && ((column-1) > 0)) {
        for(int i = 1; board[row][column-i].is_white() && ((column-i-1) >= 0); ++i) {
            if(board[row][column-i-1].is_black()) {
                return true;
            }
        }
    }
    return false;
}

bool Othello::b_checkupleft(int row, int column)const {
    if(board[row-1][column-1].is_white() && ((row-1) > 0) && ((column-1) > 0)) {
        for(int i = 1; board[row-i][column-i].is_white() && ((row-i-1) >= 0) && ((column-i-1) >= 0); ++i) {
            if(board[row-i-1][column-i-1].is_black()) {
                return true;
            }
        }
    }
    return false;
}


bool Othello::w_checkup(int row, int column)const {
    if(board[row-1][column].is_black() && ((row-1) > 0)) {
        for(int i = 1; board[row-i][column].is_black() && ((row-i-1) >= 0); ++i) {
            if(board[row-i-1][column].is_white()) {
                return true;
            }
        }
    }
    return false;
}

bool Othello::w_checkupright(int row, int column)const {
    if(board[row-1][column+1].is_black() && ((row-1) > 0) && ((column+1) < 7)) {
        for(int i = 1; board[row-i][column+i].is_black() && ((row-i-1) >= 0) && ((column+i+1) <= 7); ++i) {
            if(board[row-i-1][column+i+1].is_white()) {
                return true;
            }
        }
    }
    return false;
}

bool Othello::w_checkright(int row, int column)const {
    if(board[row][column+1].is_black() && ((column+1) < 7)) {
        for(int i = 1; board[row][column+i].is_black() && ((column+i+1) <= 7); ++i) {
            if(board[row][column+i+1].is_white()) {
                return true;
            }
        }
    }
    return false;
}

bool Othello::w_checkdownright(int row, int column)const {
    if(board[row+1][column+1].is_black() && ((row+1) < 7) && ((column+1) < 7)) {
        for(int i = 1; board[row+i][column+i].is_black() && ((row+i+1) <= 7) && ((column+i+1) <= 7); ++i) {
            if(board[row+i+1][column+i+1].is_white()) {
                return true;
            }
        }
    }
    return false;
}

bool Othello::w_checkdown(int row, int column)const {
    if(board[row+1][column].is_black() && ((row+1) < 7)) {
        for(int i = 1; board[row+i][column].is_black() && ((row+i+1) <= 7); ++i) {
            if(board[row+i+1][column].is_white()) {
                return true;
            }
        }
    }
    return false;
}

bool Othello::w_checkdownleft(int row, int column)const {
    if(board[row+1][column-1].is_black() && ((row+1) < 7) && ((column-1) > 0)) {
        for(int i = 1; board[row+i][column-i].is_black() && ((row+i+1) <= 7) && ((column-i-1) >= 0); ++i) {
            if(board[row+i+1][column-i-1].is_white()) {
                return true;
            }
        }
    }
    return false;
}

bool Othello::w_checkleft(int row, int column)const {
    if(board[row][column-1].is_black() && ((column-1) > 0)) {
        for(int i = 1; board[row][column-i].is_black() && ((column-i-1) >= 0); ++i) {
            if(board[row][column-i-1].is_white()) {
                return true;
            }
        }
    }
    return false;
}

bool Othello::w_checkupleft(int row, int column)const {
    if(board[row-1][column-1].is_black() && ((row-1) > 0) && ((column-1) > 0)) {
        for(int i = 1; board[row-i][column-i].is_black() && ((row-i-1) >= 0) && ((column-i-1) >= 0); ++i) {
            if(board[row-i-1][column-i-1].is_white()) {
                return true;
            }
        }
    }
    return false;
}

