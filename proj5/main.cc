/*
 *  Austin McKibben
 *  CS2401
 *  
 *  This program generates a closet with
 *  a set of items within. The user can
 *  add new items, but cannot take any
 *  out. The user will be able to interact
 *  with the items in many preset ways.
 *  The user will also have a file so their
 *  closet will be saved.
 */

#include <iostream>
#include <list>
#include <fstream>
#include <cstdlib>
#include <string>
#include "closet_item.h"

using namespace std;

void menu();
void menu2();

int main() {

    int choice1, choice2 = 1;
    string username, filename;
    
    list<Closet_item *> closet;
    list<Closet_item *>::iterator it;

    printf("Welcome to your closet!\n");
    printf("Please enter your username : ");
    cin >> username;
    filename = username + ".txt";

    ifstream fin;
    char c;
    Closet_item *ptr;
    fin.open(filename.c_str());
    if(!fin.fail()) {
        fin >> c;
        while((!fin.eof()) || (c == '\n')) {
            switch (c) {
                case ('s'):
                    ptr = new Shirt;
                    ptr->input(fin);
                    closet.push_back(ptr);
                    break;

                case ('c'):
                    ptr = new Chameleon;
                    ptr->input(fin);
                    closet.push_back(ptr);
                    break;

                case ('d'):
                    ptr = new Door;
                    ptr->input(fin);
                    closet.push_back(ptr);
                    break;

                case ('p'):
                    ptr = new Pocketwatch;
                    ptr->input(fin);
                    closet.push_back(ptr);
                    break;

                case ('b'):
                    ptr = new Bagel;
                    ptr->input(fin);
                    closet.push_back(ptr);
                    break;
        
                default:
                    break;
            }
            fin >> c;
        }
        fin.close();
    }
    


    menu();
    cin >> choice1;
    printf("\n\n");
    while(choice1 != 0) {
        switch(choice1) {
            case 0:
                break;

            case 1:
                it = closet.begin();
                while(it != closet.end()) {
                    (*it)->output(cout);
                    ++it;
                }
                printf("\n\n");
                break;

            case 2:
                it = closet.begin();
                while(it != closet.end()) {
                    (*it)->output(cout);
                    printf("\n\n");
                    (*it)->interact();
                    printf("\n\n");
                    ++it;
                }
                printf("\n\n");
                break;

            case 3:
                menu2();
                cin >> choice2;
                switch (choice2) {
                    case 0:
                        break;
                    case 1:
                        ptr = new Shirt;
                        ptr->input(cin);
                        closet.push_back(ptr);
                        break;
                    case 2:
                        ptr = new Chameleon;
                        ptr->input(cin);
                        closet.push_back(ptr);
                        break;
                    case 3:
                        ptr = new Door;
                        ptr->input(cin);
                        closet.push_back(ptr);
                        break;
                    case 4:
                        ptr = new Pocketwatch;
                        ptr->input(cin);
                        closet.push_back(ptr);
                        break;
                    case 5:
                        ptr = new Bagel;
                        ptr->input(cin);
                        closet.push_back(ptr);
                        break;
                    default:
                        break;
                }
                break;

            default:
                break;
        }
        menu();
        cin >> choice1;
        printf("\n\n");
    }

    ofstream fout;
    fout.open(filename.c_str());
    it = closet.begin();
    while(it != closet.end()) {
        (*it)->output(fout);
        ++it;
    }
    fout.close();
    return 0;
}

void menu() {
    printf("Select an option : \n\n");
    printf("  (0) : Exit Closet\n");
    printf("  (1) : View the Closet all at once\n");
    printf("  (2) : Investigate each item\n");
    printf("  (3) : Add a new item\n\n");
    printf("  : ");
}

void menu2() {
    printf("Add what kind of item? : \n\n");
    printf("  (0) : Nevermind\n");
    printf("  (1) : Add a Shirt\n");
    printf("  (2) : Add a Chameleon\n");
    printf("  (3) : Add a Door\n");
    printf("  (4) : Add a Pocketwatch\n");
    printf("  (5) : Add a Bagel\n\n");
    printf("  : ");
}
