/*
 *  Austin McKibben
 *  CS2401
 *  
 *  The implementation file for the
 *  Closet_item class and its children
 */

#include <iostream>
#include <list>
#include <fstream>
#include <cstdlib>
#include <string>
#include <time.h>
#include "closet_item.h"

// Closet_item class
void Closet_item::input(std::istream& ins) {
    if(&ins == &std::cin) {
        printf("Enter a color : ");
        ins >> color;
        printf("Enter the essence : ");
        ins >> essence;
    } else {
        if(ins.peek() == '\n')
            ins.ignore();

        getline(ins, color);
        getline(ins, essence);
    }
}

void Closet_item::output(std::ostream& outs)const {
    if(&outs == &std::cout) {
        outs << "   color   : " << color << '\n';
        outs << "   essence : " << essence << '\n';
    } else {
        outs << color << '\n';
        outs << essence << '\n';
    }
}

// Shirt class
void Shirt::input(std::istream& ins) {
    std::cout << "Shirt\n";
    Closet_item::input(ins);
    if(&ins == &std::cin) {
        std::cout << "Enter a size : "; 
        ins >> size;
    } else {
        getline(ins, size);
    }
}

void Shirt::output(std::ostream& outs)const {
    if(&outs == &std::cout) {
        outs << "Shirt\n";
        Closet_item::output(outs);
        outs <<"   size    : " << size << '\n';
    } else {
        outs << 's' << '\n';
        Closet_item::output(outs);
        outs << size << '\n';
    }
}

void Shirt::interact() {
    menu();
    int choice;
    std::cin >> choice;
    while(choice != 0) {
        switch(choice) {
            case 0:
                break;
            case 1:
                printf("The Shirt is stuck in the closet by a mystical force\n");
                break;
            case 2:
                if(essence == "charred") {
                    printf("This shirt is already burned\n");
                } else {
                    printf("You burned the shirt\n");
                    essence = "charred";
                    color = "black";
                }
                break;
            default:
                break;
        }
        output(std::cout);
        menu();
        std::cin >> choice;
    }

}

void Shirt::menu() {
    printf("What will you do? : \n\n");
    printf("  (0) : Move on\n");
    printf("  (1) : Wear the shirt\n");
    printf("  (2) : Burn the Shirt\n\n");
    printf("  : ");
}

// Chameleon class
void Chameleon::input(std::istream& ins) {
    std::string a;
    Closet_item::input(ins);
    if(&ins == &std::cin) {
        std::cout << "Enter the age : ";
        ins >> age;
    } else {
        getline(ins, a);
        age = stoi(a);
    }
    rand_color();
}

void Chameleon::output(std::ostream& outs)const {
    
    if(&outs == &std::cout) {
        outs << "Chameleon\n";
        Closet_item::output(outs);
        outs << "   age     : " << age << '\n';
    } else {
        outs << 'c' << '\n';
        Closet_item::output(outs);
        outs << age << '\n';
    }
}

void Chameleon::interact() {
    menu();
    int choice;
    std::cin >> choice;
    while(choice != 0) {
        switch(choice) {
            case 0:
                break;
            case 1:
                rand_color();
                if(color == "red") {
                    printf("The chameleon did not like that\n");
                } else {
                    printf("The chameleon is indifferent to your pressence\n");
                }
                break;
            default:
                break;
        }
        output(std::cout);
        printf("\n\n");
        menu();
        std::cin >> choice;
    }

}

void Chameleon::menu() {
    printf("What will you do? : \n\n");
    printf("  (0) : Move on\n");
    printf("  (1) : Pet the Chameleon\n\n");
    printf("  : ");
}

void Chameleon::rand_color() {
    std::string c;
    srand(time(NULL));
    int num = rand();
    switch (num % 5) {
        case 0:
            color = "white";
            break;
        
        case 1:
            color = "red";
            break;
        
        case 2:
            color = "green";
            break;
        
        case 3:
            color = "blue";
            break;

        case 4:
            color = "purple";
            break;

        case 5:
            color = "black";
            break;

        default:
            color = "indigo";
            break;
    }
}

// Door class
void Door::input(std::istream& ins) {
    Closet_item::input(ins);
    if(&ins == &std::cin) {
        std::cout << "Enter the state : ";
        ins >> state;
    } else {
        getline(ins, state);
    }
}

void Door::output(std::ostream& outs)const {
    if(&outs == &std::cout) {
        outs << "Door \n";
        Closet_item::output(outs);
        outs <<"   state   : " << state << '\n';
    } else {
        outs << 'd' << '\n';
        Closet_item::output(outs);        
        outs << state << '\n';
    }
}

void Door::interact() {
    menu();
    int choice;
    std::cin >> choice;
    while(choice != 0) {
        switch(choice) {
            case 0:
                break;
            case 1:
                open_door();
                break;
            case 2:
                close_door();
                break;
            default:
                break;
        }
        output(std::cout);
        menu();
        std::cin >> choice;
    }

}

void Door::open_door() {
    if(state == "open") {
        printf("The door is already opened\n");
    } else {
        printf("You opened the door\n");
        state = "open";
    }
}

void Door::close_door() {
    if(state == "closed") {
        printf("The door is already closed\n");
    } else {
        printf("You closed the door\n");
        state = "closed";
    }
}

void Door::menu() {
    printf("What will you do? : \n\n");
    printf("  (0) : Move on\n");
    printf("  (1) : Open the door\n");
    printf("  (2) : Close the door\n\n");
    printf("  : ");
}

// Pocketwatch class
void Pocketwatch::input(std::istream& ins) {
    time_t raw;
    t = localtime(&raw);
    std::string a;
    Closet_item::input(ins);
    if(&ins == &std::cin) {
        std::cout << "Enter the minute : ";
        ins >> minutes;
        std::cout << "Enter the hour : ";
        ins >> hours;
        minutes = t->tm_min;
        hours = t->tm_hour;   
    } else {
        getline(ins, a);
        minutes = stoi(a);
        getline(ins, a);
        hours = stoi(a);
        if(essence != "broken") {
            minutes = t->tm_min;
            hours = t->tm_hour;
        }
    }
    
}

void Pocketwatch::output(std::ostream& outs)const {
    if(&outs == &std::cout) {
        outs << "Pocketwatch \n";
        Closet_item::output(outs);
        if( essence == "broken") {
            outs <<"   time    : " << hours << ':' << minutes << '\n';
        } else {
            outs <<"   time    : " << t->tm_hour << ':' << t->tm_min << '\n';
        }
    } else {
        outs << 'p' << '\n';
        Closet_item::output(outs);    
        outs << minutes << '\n';
        outs << hours << '\n';
    }
} 

void Pocketwatch::interact() {
    time_t raw;
    t = localtime(&raw);
    menu();
    int choice;
    std::cin >> choice;
    while(choice != 0) {
        switch(choice) {
            case 0:
                break;
            case 1:
                if(essence != "broken") {
                    minutes = t->tm_min;
                    hours = t->tm_hour;   
                }
                std::cout <<"The time is " << hours << ':' << minutes << '\n';
                break;
            case 2:
                printf("You have made a terrible mistake\n");
                essence = "broken";
                srand(time(NULL));
                hours = rand();
                srand(time(NULL));
                minutes = rand();
                return;
                break;
            default:
                break;
        }
        output(std::cout);
        menu();
        std::cin >> choice;
    }
}

void Pocketwatch::menu() {
    printf("What will you do? : \n\n");
    printf("  (0) : Move on\n");
    printf("  (1) : Check the time\n");
    printf("  (2) : Break the pocketwatch\n\n");
    printf("  : ");
}

// Bagel class
void Bagel::input(std::istream& ins) {
    Closet_item::input(ins);
    if(&ins == &std::cin) {
        std::cout << "Enter the type : ";
        ins >> type;
    } else {
        getline(ins, type);
    }
}

void Bagel::output(std::ostream& outs)const {
    if(&outs == &std::cout) {
        outs << "Bagel \n";
        Closet_item::output(outs);
        outs <<"   type    : " << type << '\n';
    } else {
        outs << 'b' << '\n';
        Closet_item::output(outs);        
        outs << type << '\n';
    }
}

void Bagel::interact() {
    srand(time(NULL));
    int num = rand();
    menu();
    int choice;
    std::cin >> choice;
    while(choice != 0) {
        switch(choice) {
            case 0:
                break;
            case 1:
                if(essence == "plastic") {
                    printf("You try eating the plastic, but it doesn't go well\n");
                    break;
                }
                if(essence == "old") {
                    printf("The old bagel has worms in it, so don't\n");
                    break;
                }
                
                if(num % 2 == 1) {
                    printf("This Bagel is actually plastic\n");
                    essence = "plastic";
                } else {
                    printf("The bagel was hard as a rock, so you couldn't eat it\n");
                    essence = "old";
                }
                break;
            default:
                break;
        }
        output(std::cout);
        menu();
        std::cin >> choice;
    }
}

void Bagel::menu() {
    printf("What will you do? : \n\n");
    printf("  (0) : Move on\n");
    printf("  (1) : Eat the bagel\n\n");
    printf("  : ");
}