/*****************************************************
This is a sample of what the main should like for the second phase of 
the Othello game.The only change is that the game now announces a 
winner.
	John Dolan	Ohio University		Fall 2019
*************************************************************/
#include<iostream>
#include "othello.h"
using namespace std;
using namespace main_savitch_14;


int main(){
	// variables to hold unicode boarder elements
    string white = "\u2593";
    string black = "\u2591";
    string empty = "   ";
    string dnr = "\u250F";
    string dnl = "\u2513";
    string unr = "\u2517";
    string unl = "\u251B";
    string hline = "\u2501";
    string vline = "\u2503";
    string cross = "\u254B";
    string lnrnu = "\u253B";
    string lnrnd = "\u2533";
    string rnund = "\u2523";
    string lnund = "\u252B";

	// title 
	cout << dnr << hline << dnl   << ' '   << hline << lnrnd << hline << ' ' << vline << ' ' << vline   << ' ' << dnr << hline << hline << ' ' << vline << ' ' << ' ' 
		<< ' ' << vline << ' ' << ' ' << dnr << hline << dnl << endl;
	cout << vline << ' ' << vline << ' ' << ' ' << vline << ' '       << ' ' << rnund << hline << lnund << ' ' << rnund << hline << ' ' << ' ' << vline << ' ' << ' ' 
		<< ' ' << vline << ' ' << ' ' << vline << ' ' << vline << ' ' << endl;
	cout << unr << hline << unl   << ' '   << ' ' << vline << ' '     << ' ' << vline << ' ' << vline   << ' ' << unr << hline << hline << ' ' << unr << hline << ' ' 
		<< ' ' << unr << hline << ' ' << unr << hline << unl << endl;

	cout << endl << endl;

	cout << "HOW TO PLAY" << endl;
	cout << "  Player one is the black pieces." << endl;
	cout << "  Enter in moves according to the grid." << endl;
	cout << "  For example, to put a piece at D3, type D3." << endl;

	cout << endl << endl;

	cout << "PRESS ENTER TO PLAY";
	cin.ignore();

	cout << endl << endl;

   	Othello mygame;
	game::who winner;
	winner=mygame.play();
	if (winner == game::HUMAN)
		std::cout<<"Player 1 Wins";
	else
		std::cout<<"Player 2 Wins";
return 0;
}

