#include <iostream>
#include <fstream>
#include <string>
#include "course.h"
#include "node.h"
#include "college.h"

College::College() {
    studentName = "VOID"; 
    head = NULL;
}

College::College(const College &other) {
    if(other.head == NULL) {
        head = NULL;
    } else {
        head = new node(other.head->data());
        node *s_ptr;
        node *d_ptr;

        s_ptr = other.head->link();
        d_ptr = head;

        while(s_ptr != NULL) {
            d_ptr->set_link(new node(s_ptr->data()));
            d_ptr = d_ptr->link();
            s_ptr = s_ptr->link();
        }
    }
}


College::~College() {
    node *rmptr;
    while(head != NULL) {
        rmptr = head;
        head = head->link();
        delete rmptr;
    }
    delete head;

    std::cout<<"Task done\n" << std::endl;
}

College& College::operator = (const College& other) {
    if(this == &other) {
        return *this;
    }
    
    node * rmptr;
    while(head != NULL) {
        rmptr = head;
        head = head->link();
        delete rmptr;
    }

    if (other.head != NULL) {
        head = new node(other.head->data());
        node * sptr = other.head->link();
        node * dptr = head;
        while(sptr != NULL) {
            dptr->set_link(new node(sptr->data()));
            dptr = dptr->link();
            sptr = sptr->link();
        }
    }
    return *this;

}

void College::load(std::istream &fin) {
    if (fin.peek() == '\n') {
        fin.ignore();
    }
    
    getline(fin, studentName);

    course tmp;
    tmp.input(fin);
    head = new node(tmp);

    node *cursor = head;
    while(!fin.eof()) {
        if (fin.peek() == '\n') {
            fin.ignore();
        }
        tmp.input(fin);
        
        while(cursor->link() != NULL ) {
            cursor = cursor->link();
        }
        
        if (tmp != cursor->data()) {
            cursor->set_link(new node);
            cursor->link()->set_link(NULL);
            cursor->link()->set_data(tmp);
        }
    }
}

void College::save(std::ostream &fout) {
    fout << studentName << '\n';

    if(head == NULL) {
        return;
    }

    node *cursor = head;
    while(cursor->link() != NULL) {
        cursor->data().output(fout);
        cursor = cursor->link();
    }
    fout << cursor->data();

}

void College::set_name(std::string name) {
    studentName = name;
}

void College::add(course &c) {
    if (head == NULL) {
        head = new node(c);
        return;
    }

    node *cursor = head;
    node *previous;
    node *ptr = new node(c);
    std::string tmp1, tmp2, tmp3;

    tmp1 = c.get_course_number();
    
    tmp2 = cursor->data().get_course_number();

    if(tmp1[0] <= tmp2[0]) {
        head = ptr;
        head->set_link(cursor);
        
    } else {

        while( (cursor != NULL) && ( !(tmp1[0] <= tmp2[0]) ) ) {
        
            previous = cursor;
            cursor = cursor->link();
            
            if(cursor != NULL) {
                tmp2 = cursor->data().get_course_number();
            }
        }
 
        if(cursor != NULL) {
            previous->set_link(ptr);
            ptr->set_link(cursor);
        } else {
            previous->set_link(ptr);
        }
    }
}

void College::display(std::ostream &cout) {
    const node *cursor = head;
    while(cursor != NULL) {
        cout << cursor->data().get_course_number() << std::endl;
        cursor = cursor->link();
    }
}

void College::remove(std::string coursename) {
    if(head == NULL) {
        return;
    }

    if(head->data().get_course_number() == coursename) {
        node *rmptr = head;
        head = head->link();
        delete rmptr;
    } else {
        node *cursor;
        node *previous;
        cursor = head;

        while(cursor != NULL && cursor->data().get_course_number() != coursename) {
            previous = cursor;
            cursor = cursor->link();
        }

        if(cursor != NULL) {
            previous->set_link(cursor->link());
            delete cursor; 
        }
    }
}

double College::hours() {
    if(head == NULL) {
        return -1;
    }


    node *cursor = head;
    double totHours = 0;

    while (cursor->link() != NULL) {
        totHours += cursor->data().get_hours();
        cursor = cursor->link();
    }
    totHours += cursor->data().get_hours();

    return totHours;
}

double College::gpa(){
    if(head == NULL) {
        return -1;
    }

    double gpa;
    double sum = 0;
    double creditHours = 0;
    node *cursor;

    cursor = head;
    while(cursor->link() != NULL) {
        sum += cursor->data().get_number_grade() * cursor->data().get_hours();
        creditHours += cursor->data().get_hours();

        cursor = cursor->link();
    }

    gpa = sum / creditHours;

    return gpa;
}