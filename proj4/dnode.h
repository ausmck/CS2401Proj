/*
 *  dnode header file
 *  CS2401
 *  Austin McKibben
 *
 *  Contains implementation for 
 *  the dnode class. This class
 *  has a bidirectional node structure 
 *  for more efficient traversal 
 *  through a linked list.
 */


#include<iostream>

#ifndef DNODE
#define DNODE

template<class T>
class Dnode {
    public:

        // constructor
        Dnode(const T& d = T(), Dnode *n = NULL, Dnode *p = NULL)
            {datan = d; nextn = n; previousn = p;};

        // getters
        Dnode *next()
            {return nextn;};

        Dnode *previous()
            {return previousn;};

        T data()
            {return datan;};

        // setters
        void set_next(Dnode *n) 
            {nextn = n;};

        void set_previous(Dnode *p)
            {previousn = p;};

        void set_data(const T d)
            {datan = d;};

    private:
        T datan;
        Dnode *nextn;
        Dnode *previousn;
};

#endif