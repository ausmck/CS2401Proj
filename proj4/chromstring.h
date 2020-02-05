/************************************************************************
	The Chromstring class stores a single word string, and a color
	that will be used to display that string. The three colors being
        used are Red, Yellow and Green. The "sprog" is a secret code number
        which can be used by other apps for ordering of strings. It is
        stored in the file, but not displayed to the screen.
    John Dolan - Associate Professor of Instruction
    School of Electrical Engineering and Computer Science
    Ohio University, Athens, Ohio 		October 2019
*************************************************************************/

#include<iostream>
#include<string>
#include "colors.h"

#ifndef CHROMA
#define CHROMA


class Chromstring{
    public:
	Chromstring() {}
	void input(std::istream& ins);
	void output(std::ostream& outs)const;
        string get_word()const{return word;}
	unsigned get_sporg()const;
	void set_sporg(unsigned sp);
    private:
	std::string word;
	std::string color;
	unsigned sporg;
	void assign_color();
};

istream& operator >>(std::istream& ins,Chromstring& cs);
ostream& operator <<(std::ostream& outs, const Chromstring& cs);

#endif
