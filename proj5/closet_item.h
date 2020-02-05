/*
 *  Austin McKibben
 *  CS2401
 *  
 *  Header file for the Closet_item
 *  class and its children. The 
 *  Closet_item class comes with a 
 *  set of input and output functions,  
 *  as well as interact functions 
 *  specific to each child. The
 *  children include Shirt, Chameleon,
 *  Door, Pocketwatch, and Bagel.
 */
#include <iostream>
#include <list>
#include <fstream>
#include <cstdlib>
#include <string>
#include <time.h>

class Closet_item {
    public:
        Closet_item(std::string c = "white", std::string e = "none")
            {color = c; essence = e;};

        virtual void input(std::istream& ins);
        virtual void output(std::ostream& outs)const;

        virtual void interact() = 0;

    protected:
        virtual void menu() = 0;
        std::string color;
        std::string essence;
};

class Shirt:public Closet_item {
    public:
        Shirt(std::string c = "white", std::string e = "Physical", std::string s = "M")
            {color = c; essence = e; size = s;};

        void input(std::istream& ins);
        void output(std::ostream& outs)const;

        void interact();

    protected:
        void menu();
        std::string size;
};

class Chameleon:public Closet_item {
    public:
        Chameleon(std::string c = "no", std::string e = "animal", int a = 0)
            {rand_color(); essence = e; age = a;};

        void input(std::istream& ins);
        void output(std::ostream& outs)const;

        void interact();

        void change_color()
            {rand_color();};

    protected:
        void menu();
        void rand_color();
        int age;
};

class Door:public Closet_item {
    public:
        Door(std::string c = "white", std::string e = "physical", std::string s = "closed") 
            {color = c; essence = e; state = s;};

        void input(std::istream& ins);
        void output(std::ostream& outs)const;

        void interact();

        void open_door();
        void close_door();

    private:
        void menu();
        std::string state;
};


class Pocketwatch:public Closet_item {
    public:
        Pocketwatch(std::string c = "white", std::string e = "Physical", int m = 0, int h = 0)
            {color = c; essence = e; minutes = m; hours = h;};

        void input(std::istream& ins);
        void output(std::ostream& outs)const;

        void interact();

    private:
        void menu();
        struct tm *t;
        int minutes;
        int hours;
};

class Bagel:public Closet_item {
    public:
        Bagel(std::string c = "white", std::string e = "Physical", std::string t = "plain")
            {color = c; essence = e; type = t;};

        void input(std::istream& ins);
        void output(std::ostream& outs)const;

        void interact();

    private:
        void menu();
        std::string type;
};