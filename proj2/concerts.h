/***************************************************************
    This is a sequence container which works with a dynamic array of
    Performances. It allows the application program to control the order
    in which the Performances are stored, as well as some other 
    searching and sorting functions.
    Since it is a dynamic array the capacity is a variable, initially 
    set to 5 and increased in denominations of 5. used is the variable 
    that tracks how many of the available array positions are occupied.
	John Dolan		Ohio University EECS	September 2019
**********************************************************************/
#include<iostream>
#include<string>
#include<algorithm>
#include "performance.h"
#ifndef CONCERTS_H
#define CONCERTS_H

class Concerts{
    public:
	//Default constructor - allocates an array of five performances
	Concerts( );
	// Big 3
	~Concerts();
	Concerts(const Concerts& other);
	void operator = (const Concerts& other);
	//Functions for internal iterator
	void start();
	void advance();
        bool is_item()const;
	Performance current()const;
	// Functions that put Performances into the container
	// Read section 3.2 of the text for documentation on what they do
        void insert(const Performance& p);
	void attach(const Performance& p);
	// Function that removes the current item while maintaining
	// the order of the other items
	void remove_current();
	// Other Concerts functions
	void show_all(std::ostream& outs)const;
	void sort_by_date(); // ascending order
	// Displays all show with ticket prices <= amt entered
	void see_all_less_than(double amt)const;
	// Returns the first Performance found by a certain group
	Performance find_show(const std::string& agroup)const;
	// Used primariy to avoid entering duplicate performances
	bool already_in(const Performance& p)const;
	// File input and output for the backup file
	void load(std::istream& ifs);
	void save(std::ostream& ofs)const;
    private:
	void resize();
	Performance* data;
	size_t capacity;
	size_t used;
	size_t current_index;
};

#endif
