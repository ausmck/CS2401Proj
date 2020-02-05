/******************************************************************
    This is the main for the final submission of project four. Begin by
    hiding the test main: mv main1.cc main1.hold
    and unhiding this:    mv main2.hold main2.cc

    Now you should be able to compile and run this without trouble since
    you know all your functions work.

    When you run it you will see the scrambeled story in various colors 
    streaming across the screen. There will be five such outputs with 
    spaces between them.
		John Dolan School of EECS Ohio University October 2019
********************************************************************/
#include <iostream>
#include <fstream>
#include "dlist.h"
#include "chromstring.h"

using namespace std;

int main()
{
	dlist<Chromstring> words;
	dlist<Chromstring>::iterator it;
	ifstream fin;
	fin.open("tale.txt");
	if (fin.fail())
	{
		cout << "Could not open input file." << endl;
		return 1;
	}
	Chromstring tmp;
	while (fin >> tmp)
	{

		if (tmp.get_word()>"Zzzz" && tmp.get_word() < "m" )
		{
			words.rear_insert(tmp);
		}
		else if (tmp.get_word()>="m" )
				// red is dominant
		{
			words.front_insert(tmp);
		}
		else // blue is dominant
		{
		   it = words.begin();
		   for(int i = 0;i < words.size()/2;i++)
			++it; // loop moves iterator to the middle
		   if(words.size()%2 == 1){
			words.insert_before(it,tmp);
		   }
		   else{
			words.insert_after(it,tmp);
		   }
		}
	}
	fin.close();

	dlist<Chromstring> copy(words); // make a copy

	// remove the front, back, and centermost Chromstring from the copy
	copy.front_remove();
	copy.rear_remove();
	it = copy.begin();
	for(int i =0; i < copy.size()/2; ++i)
		++it;
	copy.remove(it);

        int counter;
        counter = 0; 
	// output the original list frontwards
        cout<<"OUTPUT NUMBER 1\n";
	for (dlist<Chromstring>::iterator i=words.begin(); i != words.end(); ++i)
	{       
		cout << *i;
		counter++;
		if(counter%16 ==0)
		    cout<<endl;
	}

	cout << endl << endl; // some space

	// output the copy frontwards
	cout<<"OUTPUT NUMBER 2\n";
	for (dlist<Chromstring>::iterator i=copy.begin(); i != copy.end(); ++i)
	{
		cout << *i ;
                counter++;
                if(counter%16 ==0)
                    cout<<endl;

	}

	cout << endl << endl; // some space

	// output the original backwards
	cout<<"OUTPUT NUMBER 3\n";
	counter=0;
	for (dlist<Chromstring>::iterator i=words.r_begin(); i != words.r_end(); --i)
	{
		cout << *i;
                counter++;
                if(counter%16 ==0)
                    cout<<endl;
	}

	cout << endl << endl; // some space
	cout<<"OUTPUT NUMBER 4\n";
        counter=0;
	// destroy the original list by alternating between removal of first and
	// last items.  Print each item as it is removed
	counter=0;
	while (words.size() > 0)
	{
		cout<<*words.begin();
		words.front_remove();
		if(words.size() > 0){
		    cout<<*words.r_begin();
		    words.rear_remove();
		}
                counter++;
                if(counter%8 ==0)
                    cout<<endl;
	}

	cout << endl << endl; // some space

	// output the copy backwards
	cout<<"OUTPUT NUMBER 5\n";
	counter=0;
	for (dlist<Chromstring>::iterator i=copy.r_begin(); i != copy.r_end(); --i)
	{
		cout << *i;
                counter++;
                if(counter%16 ==0)
                    cout<<endl;
	}
        cout << endl << endl; // some space

	cout<<"DESTRUCTORS RUNNING\n";
	return 0;
}
