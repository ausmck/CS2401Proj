/*************************************************************
    Project 2		CS2401		Fall 2019
    This is the main for your second project, a project which
    works with the concepts of a sequence class, an internal
    iterator, and a dynamic array.
    In order to make this main work you will need to write the
    implementation files for  two classes, one called Performance
    and one called Concerts. The header files for each of these classes
    have been given to you and should provide you with a roadmap
    for the implementations. You should NOT alter those header files
    nor this main without permission from Mr. Dolan.
    	John Dolan	Ohio University	School of EECS  Fall 2019
**************************************************************/


#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include "performance.h"
#include "concerts.h"
using namespace std;

int menu();
int menu2();

int main(){

    Performance ashow;
    Concerts shows;
    string groupname;
    int choice,choice2;
    string username, filename;
    ifstream fin;
    ofstream fout;
    bool cutout;

	cout<<"Welcome to Concert Management.\n\n";
	cout<<"Begin by entering your username: ";
	getline(cin,username);
	filename = username + ".txt";
	fin.open(filename.c_str());
    if(!fin.fail())
		shows.load(fin);
	fin.close();
	choice = 0;
	choice2 = 0;
	cutout = false;
    Concerts original(shows);

	while(choice != 9){
	    choice = menu();
	    switch(choice){
		case 1:	cin>>ashow;
		       	shows.start();
			shows.insert(ashow);
			break;
		case 2: shows.show_all(cout);
			break;
		case 3: {shows.start();
			choice2 = 0;
			while(shows.is_item()&& choice2 <= 5){
			    cout<<shows.current();
			    choice2 = menu2();
			    if(choice2 == 1)
				shows.remove_current();
			    else if(choice2 == 2){
				if(!cutout)
				cin>>ashow;
				if(shows.already_in(ashow))
				cout<<"Already in list.\n";
				else
				shows.insert(ashow);
				cutout = false;
			    }
			    else if(choice2 == 3){
				if(!cutout)
				cin >> ashow;
                               if(shows.already_in(ashow))
                                cout<<"Already in list.\n";
                                else
				shows.attach(ashow);
				cutout = false;
			    }
			    else if (choice2 == 4){
				ashow = shows.current();
				shows.remove_current();
				cutout = true;
				}
			    else if(choice2 == 5){
				shows.advance();
			    }
			    else
				cout<<"Going back to main menu.\n";
			}
      
			break;
			}
		case 4: shows.sort_by_date();
			break;
		case 5:{
			cout<<"Enter the name of the group:\n";
			if(cin.peek() == '\n') cin.ignore();
			getline(cin, groupname);
			ashow = shows.find_show(groupname);
			cout<<ashow<<endl;
			break;
			}
		case 6:{double amt;
			cout<<"Input the max single ticket price:$ ";
			cin>>amt;
			shows.see_all_less_than(amt);
			break;
		}
		case 7:	original.show_all(cout);
			break;
		default: break;
		} // bottom of the switch
	} // bottom of the while
	fout.open(filename.c_str());
    if(!fout.fail())
	    shows.save(fout);
	else
	    cout<<"Unable to save data.\n";
	fout.close();

	cout<<"Come visit Concert Management again soon.\n";
return 0;
}
int menu() {
	int ans;
	cout<<"Choose from the options below:\n";
	cout<<"1 - Add a performance to the beginning of the list.\n";
	cout<<"2 - See all your all listed concerts.\n";
	cout<<"3 - Walk through the list, one show at a time.\n";
	cout<<"4 - Sort your shows by perfomance date.\n";
	cout<<"5 - Find a group so you can learn when they will play.\n";
	cout<<"6 - See all the concerts below a certain price.\n";
	cout<<"7 - See the list you started with in today's session. \n";
	cout<<"9 - Leave the program.\n";
	cin>>ans;
    return ans;
}

int menu2(){
	int ans;
	cout<<"What would like to do with this show?\n";
	cout<<"1 - Remove from the list.\n";
	cout<<"2 - Insert a new show or cut-out show before this show.\n";
	cout<<"3 - Put a new show or cut-out show after this show.\n";
	cout<<"4 - Cut this show from the list to be inserted elsewhere.\n";
	cout<<"    If you want the show earlier in the list you will need to start a new walk-through.\n";
	cout<<"5 - Advance to the next show.\n";
	cout<<"6 - Return to main menu.\n";
	cin>>ans;
    return ans;
}
