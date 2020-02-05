/*****************
 * Austin McKibben
 * CS2401
 * 
 * This is a class that contains a linked list of college classes.
 * It can load and save classes from a file, display the list of all
 * courses, add a course alphapetically, remove a class, return the 
 * total number credit hours taken, and return the current GPA.
 * 
 *****************/ 



#include <iostream>
#include <fstream>
#include <string>
#include "course.h"
#include "node.h"
#ifndef COLLEGE_H
#define COLLEGE_H

class College {
    public:
        College();
        College(const College &other);
        ~College();
        College& operator = (const College& other);

        void load(std::istream &fin);
        void save(std::ostream &fout);

        void set_name(std::string name);
        void add(course &c);
        void display(std::ostream &cout);
        void remove(std::string coursename);
        double hours();
        double gpa();

    private:
        std::string studentName;
        node *head;
};



#endif