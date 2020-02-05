/*
 *  Austin McKibben
 *  CS2401
 *  9/15/2019
 * 
 *  Checkbook class header file. Contains a varitety of functions
 *  to help with the implementaion of a checkbook program.
 *
 */



#ifndef CHECKBOOK
#define CHECKBOOK

#include<iostream>
#include<fstream>
#include<string>
#include "check.h"


#define CAPACITY 200

class Checkbook {
    public:

        // loads a checkbook from a backup file
        void load_from_file(std::istream& ins);

        // deposits a specified amount into the balance 
        void deposit(double depamount);

        // creates a check in cks[]
        void write_check(std::istream& ins);

        // returns the balance of the account
        double get_balance();

        // shows all checks in checkbook
        void show_all(std::ostream& outs)const;

        // removes a check from the checkbook
        void remove(int rmnum);

        // sorts checks by check number
        void number_sort();

        // sorts checks alphabetically by payto
        void payto_sort();

        // sorts checks by date
        void date_sort();

        // shows all checks written to a particualar payee
        void show(std::string payto_find);
        
        // gives an average of all checks written
        double average();

        // saves all checks to a file
        void save(std::ofstream& outs)const;

    private:
        Check cks[CAPACITY];    // holds all checks (a check with checknumber 0 indicates that it is unused)
        int used = 0;   // indicates how many checks have been used
        double balance = 0; // account balance

};



#endif