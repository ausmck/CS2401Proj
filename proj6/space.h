/*
 *  Austin McKibben  
 *  CS2401
 * 
 *  File for the space class. The
 *  class has the ability to change
 *  between the white, black, and 
 *  empty state. This is represented
 *  by the number 2, 1, and 0 respectively.
 *  The class also has a flip function
 *  which switches the state between
 *  black and white states.
 * 
 */

#ifndef SPACE_H
#define SPACE_H
#include<iostream>

class space {
    public:
        // constructer
        space(char s = 0)
            {state = s;}

        // boolean operations
        bool is_empty()const
            {if(state == 0){return true;}else{return false;}}

        bool is_black()const
            {if(state == 1){return true;}else{return false;}}

        bool is_white()const
            {if(state == 2){return true;}else{return false;}}

        // mutators
        void make_empty()
            {state = 0;}

        void make_black()
            {state = 1;}

        void make_white()
            {state = 2;}

        // flip
        void flip() {
            if(state == 0) {
                printf("invlaid use of flip function\n");
            } else {
                if(state == 1) {
                    state = 2;
                } else {
                    state = 1;
                }
            }
        }

    private:
        // 0 is empty, 1 is black, 2 is white
        char state;
};

#endif