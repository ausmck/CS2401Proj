/*
 *  Austin McKibben
 *  CS2401
 *  9/15/2019
 * 
 *  Checkbook class Implemantaion
 *
 */

#include<iostream>
#include<fstream>
#include<string>
#include "check.h"
#include "checkbook.h"




void Checkbook::load_from_file(std::istream& ins) {\
    int tempNum;

    ins >> balance;
    ins >> used;

    for(int i = 0; i < used ; i++) {
        ins >> tempNum;
        cks[i].set_check_num(tempNum);
        cks[i].write_check(ins);
    }
}

void Checkbook::deposit(double depamount) {
    balance += depamount;
}

void Checkbook::write_check(std::istream& ins) {
    int chkTmp = 0;
    std::cout << "Enter a check number: ";
    ins >> chkTmp;
    for(int i = 0; i < used; i++) {
        if(cks[i].get_num() == chkTmp) {
            std::cout << "Error: Check number already in use" << std::endl;
            return;
        }
    }

    used++;
    cks[used - 1].set_check_num(chkTmp);
    std::cout << "Enter the date, the recipient, and the amount: ";
    cks[used - 1].write_check(std::cin);

    balance -= cks[used - 1].get_amount();
}

double Checkbook::get_balance() {
    return balance;
}

void Checkbook::show_all(std::ostream& outs)const {
    int offset = 0;

    outs << "         Balance : $" << balance << std::endl;
    outs << "Number of Checks : " << used << std::endl << std::endl;

    for(int i = 0; i < used; i++ ) {
        if(cks[i].get_num() == 0) {
            offset++;
        }
        
        outs << "    Check Number : " << cks[i+offset].get_num() << std::endl;
        outs << "            Date : " << cks[i+offset].get_date() << std::endl;
        outs << "          Pay to : " << cks[i+offset].get_payto() << std::endl;
        outs << "          amount : $" << cks[i+offset].get_amount() << std::endl << std::endl;   
    } 
}

void Checkbook::remove(int rmnum) {
    int i;
    for(i = 0; i < used; i++) {
        if(cks[i].get_num() == rmnum) {
            cks[i].set_check_num(0);
            balance += cks[i].get_amount();
            used--;
            return;
        }
    }

    if((i == used) || (rmnum == 0)) {
        std::cout << "Error: Invalid check number" << std::endl << std::endl;
    }

}

void Checkbook::number_sort() {
    Check tmp;
    bool done = false;


    while(!done) {
        done = true;
        for(int i = 0; i < used-1; i++) {
            if(cks[i].get_num() > cks[i+1].get_num()) {
                tmp = cks[i+1];
                cks[i+1] = cks[i];
                cks[i] = tmp;
                done = false;
            }
        }
    }
}

void Checkbook::payto_sort() {
    Check tmp;
    char payto1;
    char payto2;
    bool done = false;

    while(!done) {
        done = true;
        for(int i = 0; i < used-1; i++) {

            payto1 = cks[i].get_payto().at(0);
            payto2 = cks[i+1].get_payto().at(0);

            if(payto1 > payto2) {
                tmp = cks[i+1];
                cks[i+1] = cks[i];
                cks[i] = tmp;
                done = false;
            }
        }
    }
}

void Checkbook::date_sort() {
    Check tmp;
    bool done = false;

    while(!done) {
        done = true;
        for(int i = 0; i < used-1; i++) {
            if(cks[i].get_date() > cks[i+1].get_date()) {
                tmp = cks[i+1];
                cks[i+1] = cks[i];
                cks[i] = tmp;
                done = false;
            }
        }
    }
}

void Checkbook::show(std::string payto_find) {
    double totAmt = 0;
    for(int i = 0; i < used; i++) {
        if(cks[i].get_payto() == payto_find) {
            std::cout << "    Check Number : " << cks[i].get_num() << std::endl;
            std::cout << "            Date : " << cks[i].get_date() << std::endl;
            std::cout << "          Pay to : " << cks[i].get_payto() << std::endl;
            std::cout << "          amount : $" << cks[i].get_amount() << std::endl << std::endl;
            totAmt += cks[i].get_amount();
        }
    }
    if(totAmt != 0) {
        std::cout << "    Total Amount : $" << totAmt << std::endl;
    } else {
        std::cout << "Error: Unable to find payee" << std::endl;
    }
}

double Checkbook::average() {
    double average = 0;
    double amtCks = 0;

    for(int i = 0; i < used; i++) {
        if(cks[i].get_num() != 0) {
            amtCks += cks[i].get_amount();
        }
    }

    average = amtCks / (used);
    return average;
}

void Checkbook::save(std::ofstream& outs)const {
    int offset = 0;

    outs << balance << std::endl;
    outs << used << std::endl;
    for(int i = 0; i < used; i++) {
        if(cks[i].get_num() == 0) {
            offset++;
        }
        outs << cks[i+offset];
    }
}