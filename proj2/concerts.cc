/*
 * Austin McKibben
 * 9-26-19
 * 
 */



#include<iostream>
#include<string>
#include<algorithm>
#include "date.h"
#include "performance.h"
#include "concerts.h"

Concerts::Concerts( ) {
    data = new Performance[5];
    capacity = 5;
    used = 0;
    current_index = 0;
}

Concerts::~Concerts() {
    delete[] data;
    std::cout << "Destructor Doing thing\n";
}

Concerts::Concerts(const Concerts& other) {
    used = other.used;
    capacity = other.capacity;
    data = new Performance[capacity];

    for(size_t i = 0; i < used; i++) {
        data[i] = other.data[i];
    }
}

void Concerts::operator = (const Concerts& other) {
    if(this == &other) {
        return;
    }

    if(capacity != other.capacity) {
        delete[] data;
        data = new Performance[other.capacity];
        capacity = other.capacity;
    }

    used = other.used;
    std::copy(other.data, other.data+used, data);
}

void Concerts::start() {
    current_index = 0;
}

void Concerts::advance(){
    current_index++;
}

bool Concerts::is_item()const {
    if(current_index >= used) {
        return false;
    }
    return true;
}

Performance Concerts::current()const {
    return data[current_index];
}

void Concerts::insert(const Performance& p) {
    if(used >= capacity) {
        resize();
    }


    for(size_t i = used; i > current_index;i--) {
        data[i] = data[i-1];
    }
    data[current_index] = p;
    used++;
}

void Concerts::attach(const Performance& p) {
    if(used >= capacity) {
        resize();
    }

    used++;
    for(size_t i = used; i > current_index+1;i--) {
        data[i] = data[i-1];
    }
    data[current_index+1] = p;
        
}

void Concerts::remove_current() {
    if(this->is_item()) {
        for(size_t i = current_index; i < used; i++) {
            data[i] = data[i+1];
        }
        used--;
    }
}

void Concerts::show_all(std::ostream& outs)const {
    for(size_t i = 0; i < used; i++) {
        data[i].output(outs);
        printf("\n");
    }
}

void Concerts::sort_by_date() {
    Performance tmp;
    bool done = false;

    while(!done) {
        done = true;
        for(size_t i = 0; i < used-1; i++) {
            if(data[i].get_when() > data[i+1].get_when()) {
                tmp = data[i+1];
                data[i+1] = data[i];
                data[i] = tmp;
                done = false;
            }
        }
    }
}

void Concerts::see_all_less_than(double amt)const {
    for(size_t i = 0; i < used; i++) {
        if(data[i].how_much() <= amt) {
            data[i].output(std::cout);
        }
    }
}

Performance Concerts::find_show(const std::string& agroup)const {
    for(size_t i = 0; i < used; i++) {
        if(data[i].get_who() == agroup) {
            return data[i];
        }
    }
    Performance p;
    return p;
}

bool Concerts::already_in(const Performance& p)const {
    for(size_t i = 0; i < used; i++) {
        if(data[i] == p) {
            return true;
        }
    }
    return false;
}

void Concerts::load(std::istream& ifs) {
    size_t i = 0;
    Performance tmp;
    while(!ifs.eof()){
        
        if(used == capacity) {
            resize();
        }
        data[i].input(ifs);
        i++;
        used++;
    }
    used -= 1;
    
}

void Concerts::save(std::ostream& ofs)const {
    for(size_t i = 0; i < used; i++) {
        data[i].output(ofs);
    }
}

void Concerts::resize() {
    capacity += 5;

    Performance *tmp;

    tmp = new Performance[capacity];
    for(size_t i = 0; i < used; i++) {
        tmp[i] = data[i];
    }

    delete[] data;
    data = new Performance[capacity];
    for(size_t i = 0; i < used; i++) {
        data[i] = tmp[i];
    }

    delete[] tmp;
}