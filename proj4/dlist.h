/*
 *  dlist header file
 *  CS2401
 *  Austin McKibben
 * 
 *  Contains the dlist class.
 *  dlist is a template container 
 *  class implimented with a 
 *  bi-directional linked list
 *  class. It is also compatable 
 *  with an iterator class for 
 *  simple traversal through the 
 *  list.
 */
#include <iostream>
#include "dnode.h"
#include "node_iterator.h"

#ifndef DLIST
#define DLIST


template<class T>
class dlist {
    public:
    
        typedef node_iterator<T> iterator;

        // constuctor
        dlist(Dnode<T> *h = NULL, Dnode<T> *t = NULL, size_t s = 0)
            {head = h; tail = t; sizel = s;}

        // big 3
        dlist(const dlist<T> &other);
        ~dlist(); 
        dlist& operator =(const dlist& other); 

         
        // prints all objects in the list
        void show(); 
        void reverse_show(); 

        // basic intertion and removal functions
        void rear_insert(const T& item);
        void front_insert(const T& item);
        void rear_remove(); 
        void front_remove(); 

        // functions for use with the iterator class
        void insert_after(iterator it, T item); 
        void insert_before(iterator it, T item); 
        void remove(iterator it); 

        size_t size() 
            {return sizel;}

        iterator begin()
            {return iterator(head);}

        iterator end()
            {return iterator(NULL);}

        iterator r_begin()
            {return iterator(tail);}

        iterator r_end()
            {return iterator(NULL);}

    private:
        Dnode<T> *head;
        Dnode<T> *tail;
        size_t sizel;
};

#include "dlist.template"


#endif