// TicTacToe.cpp : Defines the entry point for the console application.
/*
Summary: This game is for making a two player game for tick tack toe. This is the test my current ability and to also give me a basic project to work on.
*/

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool tie(string game[]) {
	for (int i = 0; i < 9; i++) {
		if (game[i] == " ")return false;
	}
	return true;
}

int placement(int a) {//converts control input to the designated array number
	if (a > 9 || a < 0) throw "Please input valid int. Enter 0 if you need to see diagram of inputs";
	switch (a) {
	case 1: return 6;
	case 2: return 7;
	case 3: return 8;
	case 4: return 3;
	case 5: return 4;
	case 6: return 5;
	case 7: return 0;
	case 8: return 1;
	case 9: return 2;
	default: return -1;
	}
}
bool win(string game[], string s) {	//checks to see if theres a winner
	if ((game[0] == s && game[1] == s && game[2] == s) || (game[3] == s && game[4] == s && game[5] == s) || (game[6] == s && game[7] == s && game[8] == s) || (game[0] == s && game[3] == s && game[6] == s) ||
		(game[1] == s && game[4] == s && game[7] == s) || (game[2] == s && game[5] == s && game[8] == s) || (game[0] == s && game[4] == s && game[8] == s) || (game[2] == s && game[4] == s && game[6] == s)) {
		return true;
	}
	else return false;
}

void display(string a[]) {	//displays the board
	cout << "------\n";
	cout << a[0] << "|" << a[1] << "|" << a[2] << '\n' << "------\n" << a[3] << '|' << a[4] << '|' << a[5] << '\n' << "------\n" << a[6] << '|' << a[7] << '|' << a[8] << endl;
	cout << "------\n";
}

void game() {
	string help = "7|8|9\n------\n4|5|6\n------\n1|2|3";	//matches the classic phone layout for easy understanding
	string a[9] = { " "," "," "," "," "," "," "," "," " };//initializes the board with empty array
	bool p1, cont = true;	//tracks whos turn it is and also who wins;
	int tick = 0;
	int input;
	display(a);
	while (cont) {
		if (tick % 2 == 0) p1 = true; else p1 = false;	//determines whos turn it is
		if (p1)cout << "Please input Player 1 (X)" << endl; else cout << "Please input Player 2 (O)" << endl;
		cin >> input;
		try {	//testing the input for any invalid input
			input = placement(input);
			if (input == -1)cout << help << endl;
			else if (a[input] == "X" || a[input] == "O") {
				throw "Spot is already full. Please input at another spot.";
			}
			else if (p1) {
				a[input] = "X";
			}
			else {
				a[input] = "O";
			}
		}
		catch (const string e) {
			tick--;
			cout << e << endl;
		}
		catch (...) {
			tick--;
			cout << "Please input a valid int" << endl;
		}
		cout << "////////////////////////////////////////////////////////////////////////////" << endl;	//way of breaking up the board
		//displays the output
		display(a);

		//determines winner
		if (win(a, "X")) {
			cont = false;
			cout << "Player 1 Wins" << endl;
		}
		else if (win(a, "O")) {
			cont = false;
			cout << "Player 2 Wins" << endl;
		}
		else if (tie(a)) {
			cont = false;
			cout << "This is a Tie." << endl;
		}
		tick++;	//updates the turn
	}
}

int main()
{
	char start = 'a';
	bool cont = true;
	string help = "7|8|9\n------\n4|5|6\n------\n1|2|3";	//matches the classic phone layout for easy understanding
	cout << "Welcome to Tick Tac Toe! By Justice Lee" << endl;
	cout << "Simply try to get a three in a row on a grid against your opponent. As this is a two player game, one person will be Player 1 and the other Player 2. " <<
		"To mark your spot on the grid, simply press the corresponding panel number -> see diagram below" << endl;
	cout << help << endl;
	cout << "If you want to see the diagram again, simply enter 0 at any moment during the game to see the diagram." << endl;
	while (cont) {
		cout << "Start game? (y/n)" << endl;
		cin >> start;
		if (start == 'y') {
			game();
		}
		else if (start == 'n') {
			cont = false;
		}
		else {
			cout << "Invalid input. Please input y for yes or n for no." << endl;
		}
	}
	return 0;
}

