/**********************************************************************
	Implementation of the Chromstring class.
    John Dolan		School EECS		Ohio University
		Fall 2019
************************************************************************/
#include<iostream>
#include<string>
#include<stdlib.h>
#include "chromstring.h"
using namespace std;

std::string pick[3] =
{"\e[31m","\e[32m","\e[33m"};

void Chromstring::input(istream& ins){
if(&ins == &cin){
    ins>>word;
    assign_color();
    sporg = 0;
}
else{
    ins>>word>>color>>sporg;
}
}

void Chromstring::output(ostream& outs)const{
if(&outs == &cout){
    outs<<color<<word<<' '<<RESET;
}
else{
    outs<<word<<' '<<color<<' '<<sporg<<endl;
}
}

unsigned Chromstring::get_sporg()const{
    return sporg;
}

void Chromstring::set_sporg(unsigned sp){
    sporg = sp;
}

void Chromstring::assign_color(){
    int i = rand()%3;
    color = pick[i];
}

// Overloaded extraction operator
istream& operator >>(std::istream& ins,Chromstring& cs){
    cs.input(ins);
    return ins;
}
// Overloaded insertion operator
ostream& operator <<(std::ostream& outs, const Chromstring& cs){
    cs.output(outs);
    return outs;
}

