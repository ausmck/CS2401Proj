#include<iostream>
#include<string>
#include<algorithm>
#include "date.h"
#include "performance.h"
#include "concerts.h"
using namespace std;


int main() {
    Concerts c1, c2;
    Performance p1;

    p1.input(cin);
    
    c1.start();
    c1.insert(p1);

    if(c1.is_item()) {
        printf("yes\n\n");
    } else {
        printf("no\n\n");
    }

    c2=c1;

    c2.start();
    c2.insert(p1);
    c2.start();
    c2.advance();
    c2.current().output(cout);

    printf("\n\n");

    c1.start();
    c1.attach(p1);
    c1.start();
    c1.advance();
    c1.remove_current();
    c1.current().output(cout);

    printf("\n\n");

    c1.show_all(cout);
    c2.show_all(cout);

    return 0;
}