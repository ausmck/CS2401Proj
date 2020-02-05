/*
 *  Node iterator header file
 *  CS2401
 *  Austin McKibben
 * 
 *  Contains the node_iterator class.
 *  Intended for use with the dlist
 *  class.
 */


#include <iostream>
#include "dnode.h"

#ifndef NODE_ITERATOR
#define NODE_ITERATOR

template <class T>
class dlist;

template <class T>
class node_iterator {
    public:

        friend class dlist<T>; // allows for use within dlist class

        // constructor
        node_iterator(Dnode<T> *i = NULL)
            {current = i;}

        // boolean operators
        bool operator ==(const node_iterator& other)
            {return (current == other.current);}

        bool operator !=(const node_iterator& other)
            {return (current != other.current);}

        // data access
        T operator *()
            {return current->data();}

        // traversal operators
        node_iterator operator ++()
            {current = current->next(); return *this;}

        node_iterator operator --()
            {current = current->previous(); return *this;}

        node_iterator operator ++(int) 
            {node_iterator original(*this); current = current->next(); return original;}

        node_iterator operator --(int) 
            {node_iterator original(*this); current = current->previous(); return original;}

    private:
        Dnode<T> *current;
};

#endif