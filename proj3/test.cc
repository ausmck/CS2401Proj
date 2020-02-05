#include <iostream>
#include <fstream>
#include <string>
#include "course.h"
#include "node.h"
#include "college.h"

using namespace std;

// This function displays the menu and returns the user's choice
int menu();

int main(){
    int choice;
    course c1, c2;
    string coursename;
    ifstream fin;
    ofstream fout;
    string fullname;

    College test;

    



    c1.set_course("CS3000", "A", 4);
    c2.input(cin);



    test.add(c1);
    test.add(c2);
    for(int i = 0; i < 5; i++)
        test.add(c1);
    test.display(cout);

}