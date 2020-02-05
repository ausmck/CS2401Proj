/*
 * Austin McKibben
 * 9-26-19
 * 
 */

#include<iostream>
#include<string>
#include "date.h"
#include "performance.h"

Performance::Performance(const std::string& w1, const std::string& w2, const Date& d1, double c) {
    who = w1;
    where = w2;
    when = d1;
    cost = c;
}
	
void Performance::input(std::istream& ins) {
    ins >> when;

    while(ins.peek() == '\n') {
		ins.ignore();
		getline(ins, who);
	}

	getline(ins, where);
	

    ins >> cost;
}

void Performance::output(std::ostream& outs)const {
    outs << when << std::endl;
    outs << who << std::endl;
    outs << where << std::endl;
    outs << cost << std::endl;
}

bool Performance::operator ==(const Performance& p)const {
    if( (where == p.where) && (when == p.when) ) {
        return true;
    }

    return false;
}

bool Performance::operator !=(const Performance& p)const {
    if( (where == p.where) && (when == p.when) ) {
        return false;
    }

    return true;
}

std::istream& operator >> (std::istream& ins, Performance& p) {
    p.input(ins);
    return ins;
}
std::ostream& operator << (std::ostream& outs, const Performance& p) {
    p.output(outs);
    return outs;
}
