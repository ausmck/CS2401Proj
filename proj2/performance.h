/******************************************************************
    This class is intended to hold information about a single concert
    performance, including the name of the band, the location of the 
    concert, the date of the concert and the cost of tickets.
	John Dolan	Ohio University EECS		September 2019
*******************************************************************/
#include<iostream>
#include<string>
#include "date.h"
#ifndef PERFORMANCE_H
#define PERFORMANCE_H


class Performance{
   public:
	Performance(const std::string& w1 = "NOONE", const std::string& w2 = "NOWHERE", const Date& d1=Date(3,12,1979), double c = 0.0);
	// Mutators
	void set_who(const std::string& w1){who = w1;}
	void set_where(const std::string& w2){where = w2;}
	void set_when(const Date& d){when = d;}
	void set_cost(double amt){cost = amt;}
	//Accessors
        std::string get_who()const {return who;}
        std::string get_where() const{return where;}
	Date get_when( ) const{return when;}
	double how_much( )const{return cost;}
	//Input/Output  -- these functions should work for files or console
	// Since location and group names can have spaces you will need 
  	// to use getline for the two strings that you are inputting.
	void input(std::istream& ins);
	void output(std::ostream& outs)const;
	//Comparison -- two performances are equal if date and locatin match
	bool operator ==(const Performance&p)const;
	bool operator !=(const Performance&p)const;
   private:
	std::string who;
	std::string where;
	Date when;
	double cost;
};
// prototypes for overloaded non-member, non-friend operators
std::istream& operator >> (std::istream& ins, Performance& p);
std::ostream& operator << (std::ostream& outs, const Performance& p);

#endif
