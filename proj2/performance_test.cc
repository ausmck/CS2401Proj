#include<iostream>
#include<string>
#include "date.h"
#include "performance.h"
using namespace std;


int main(){ 
    Performance p1, p2;
    p1.input(cin);
    p2.output(cout);

    if(p1 == p2) {
        printf("true\n");
    }
    if(p1 != p2) {
        printf("false\n");
    }


    return 0;
}