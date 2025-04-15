// tic.cpp : Defines the entry point for the console application.
//
#include "stdafx.h" // Add this line for precompiled headers
#include <iostream>
#include <array>
#include <cctype>
#include <cstdlib>
#include "xboxTEST.cpp"
#include <ctime>
#include <string>
#include <cmath>
#include <Windows.h>


using namespace std;
class node {
public:
	char data;
	node* next;
};

class stack {
private:
	node*head;
public:
	stack() {
		head = NULL;
	}
	void push(char a) {
		node*x = new node();
		//cout << "pushing " << a << " " << endl;
		x->data = a;
		x->next = head;
		head = x;
	}
	char pop() {
		node*q = head;
		//cout << "popping " << q->data << " " << endl;
		int top = q->data;
		head = head->next;
		return top;
		delete q;
	}
	void displayStack() {
		node*w = head;
		while (w != NULL) {
			cout << w->data << endl;
			w = w->next;
		}
		cout << endl;
	}
};
class Toe {
public:
	char tac[3][3];
	stack fun;
	char*ptr;
	int randomONE;
	int randomTWO;

	Toe() {
		makeTIC();
		turns();
		ptr = &tac[1][1];

	}
	void makeTIC() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				tac[i][j] = 'r';
			}
		}
	}
	void display() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << " " << tac[i][j] << " ";
			}
			cout << endl;
		}
	}
	void turns() {

		for (int k = 0; k < 10; k++) {
			if (k % 2 == 0) {
				fun.push('o');
			}
			else {
				fun.push('x');
			}
		}
	}

	void displayTurns() {
		for (int h = 0; h < 10; h++) {
			cout << " " << fun.pop() << endl;

		}
		cout << endl;
	}

	void clear() {
		for (int y = 0; y < 100; y++) {
			cout << endl;
		}
	}
	void numNPC() {
		 randomONE = rand() % 3;
		 randomTWO = rand() % 3;
	}

	char NPC() {
		numNPC();
		bool batman = true;
		while (batman) {
			if ((tac[randomONE][randomTWO] == 'x') || (tac[randomONE][randomTWO] == 'o')) {
				numNPC();
			}
			if ((tac[randomONE][randomTWO] != 'x') && (tac[randomONE][randomTWO] != 'o')) {
				break;
			}
			if ((tac[0][0] != 'r') && (tac[0][1] != 'r') && (tac[0][2] != 'r') && (tac[1][0] != 'r') && (tac[1][1] != 'r') && (tac[1][2] != 'r') && (tac[2][0] != 'r') && (tac[2][1] != 'r') && (tac[2][2] != 'r')) {
				break;
			}
		}
		tac[randomONE][randomTWO] = fun.pop();
		clear();
		display();
		cout << endl;
		return 'd';
	}



	void game() {
		int i = 0;
		cout << "you are X" << endl;
		cout << "X goes first" << endl;
		char choice;
		bool run = true;
		cout << "dpadUP moves up" << endl;
		cout << "dpadDOWN moves down" << endl;
		cout << "dpadLEFT moves left" << endl;
		cout << "dpadRIGHT moves right" << endl;
		cout << "'select' or 'B' to quit" << endl;
		cout << "press A to change to X" << endl;
		//cout << "enter a command" << endl;
		while (run) {
			choice = controller();
			if (choice == 'w') {
				if (ptr == &tac[0][0] || ptr == &tac[0][1] || ptr == &tac[0][2]) {
					ptr = ptr;
					*ptr = upps(*ptr);
					clear();
					display();
					cout << endl;
					*ptr = lows(*ptr);

				}
				else {
					ptr = ptr - 3;
					*ptr = upps(*ptr);
					clear();
					display();
					cout << endl;
					*ptr = lows(*ptr);

				}

			}
			if (choice == 's') {
				if (ptr == &tac[2][0] || ptr == &tac[2][1] || ptr == &tac[2][2]) {
					ptr = ptr;
					*ptr = upps(*ptr);
					clear();
					display();
					cout << endl;
					*ptr = lows(*ptr);

				}
				else {
					ptr = ptr + 3;
					*ptr = upps(*ptr);
					clear();
					display();
					cout << endl;
					*ptr = lows(*ptr);

				}

			}
			if (choice == 'a') {
				if (ptr == &tac[0][0] || ptr == &tac[1][0] || ptr == &tac[2][0]) {
					ptr = ptr;
					*ptr = upps(*ptr);
					clear();
					display();
					cout << endl;
					*ptr = lows(*ptr);

				}
				else {
					ptr = ptr - 1;
					*ptr = upps(*ptr);
					clear();
					display();
					cout << endl;
					*ptr = lows(*ptr);

				}

			}
			if (choice == 'd') {
				if (ptr == &tac[0][2] || ptr == &tac[1][2] || ptr == &tac[2][2]) {
					ptr = ptr;
					*ptr = upps(*ptr);
					clear();
					display();
					cout << endl;
					*ptr = lows(*ptr);

				}
				else {
					ptr = ptr + 1;
					*ptr = upps(*ptr);
					clear();
					display();
					cout << endl;
					*ptr = lows(*ptr);

				}

			}
			if (choice == 'i') {
				if (*ptr == 'x' || *ptr == 'o') {
					cout << "there is already a X or an O there" << endl <<endl;
				}
				else {
					*ptr = fun.pop();
					clear();
					display();
					cout << endl;
					if ((tac[0][0] == 'x') && (tac[0][1] == 'x') && (tac[0][2] == 'x')) {
						cout << " " << tac[0][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[1][0] == 'x') && (tac[1][1] == 'x') && (tac[1][2] == 'x')) {
						cout << " " << tac[1][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[2][0] == 'x') && (tac[2][1] == 'x') && (tac[2][2] == 'x')) {
						cout << " " << tac[2][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[0][0] == 'x') && (tac[1][1] == 'x') && (tac[2][2] == 'x')) {
						cout << " " << tac[0][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[2][0] == 'x') && (tac[1][1] == 'x') && (tac[0][2] == 'x')) {
						cout << " " << tac[2][0] << " wins" << endl;
						cout << endl;
						break;
					}

					if ((tac[0][0] == 'x') && (tac[1][0] == 'x') && (tac[2][0] == 'x')) {
						cout << " " << tac[0][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[0][1] == 'x') && (tac[1][1] == 'x') && (tac[2][1] == 'x')) {
						cout << " " << tac[1][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[0][2] == 'x') && (tac[1][2] == 'x') && (tac[2][2] == 'x')) {
						cout << " " << tac[0][2] << " wins" << endl;
						cout << endl;
						break;
					}
					
					//for x's^^^^^     //for o's below
					if ((tac[0][0] == 'o') && (tac[0][1] == 'o') && (tac[0][2] == 'o')) {
						cout << " " << tac[0][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[1][0] == 'o') && (tac[1][1] == 'o') && (tac[1][2] == 'o')) {
						cout << " " << tac[1][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[2][0] == 'o') && (tac[2][1] == 'o') && (tac[2][2] == 'o')) {
						cout << " " << tac[2][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[0][0] == 'o') && (tac[1][1] == 'o') && (tac[2][2] == 'o')) {
						cout << " " << tac[0][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[2][0] == 'o') && (tac[1][1] == 'o') && (tac[0][2] == 'o')) {
						cout << " " << tac[2][0] << " wins" << endl;
						cout << endl;
						break;
					}

					if ((tac[0][0] == 'o') && (tac[1][0] == 'o') && (tac[2][0] == 'o')) {
						cout << " " << tac[0][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[0][1] == 'o') && (tac[1][1] == 'o') && (tac[2][1] == 'o')) {
						cout << " " << tac[1][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[0][2] == 'o') && (tac[1][2] == 'o') && (tac[2][2] == 'o')) {
						cout << " " << tac[2][0] << " wins" << endl;
						cout << endl;
						break;
					}
					//
					//
					//
					//
					//
					i++;
					NPC();
					if (i == 9) {
						cout << "nobody wins" << endl;
						cout << endl;
						break;
					}
					//
					//
					//
					//
					//
					if ((tac[0][0] == 'x') && (tac[0][1] == 'x') && (tac[0][2] == 'x')) {
						cout << " " << tac[0][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[1][0] == 'x') && (tac[1][1] == 'x') && (tac[1][2] == 'x')) {
						cout << " " << tac[1][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[2][0] == 'x') && (tac[2][1] == 'x') && (tac[2][2] == 'x')) {
						cout << " " << tac[2][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[0][0] == 'x') && (tac[1][1] == 'x') && (tac[2][2] == 'x')) {
						cout << " " << tac[0][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[2][0] == 'x') && (tac[1][1] == 'x') && (tac[0][2] == 'x')) {
						cout << " " << tac[2][0] << " wins" << endl;
						cout << endl;
						break;
					}

					if ((tac[0][0] == 'x') && (tac[1][0] == 'x') && (tac[2][0] == 'x')) {
						cout << " " << tac[0][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[0][1] == 'x') && (tac[1][1] == 'x') && (tac[2][1] == 'x')) {
						cout << " " << tac[0][1] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[0][2] == 'x') && (tac[1][2] == 'x') && (tac[2][2] == 'x')) {
						cout << " " << tac[0][2] << " wins" << endl;
						cout << endl;
						break;
					}

					//for x's^^^^^     //for o's below
					if ((tac[0][0] == 'o') && (tac[0][1] == 'o') && (tac[0][2] == 'o')) {
						cout << " " << tac[0][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[1][0] == 'o') && (tac[1][1] == 'o') && (tac[1][2] == 'o')) {
						cout << " " << tac[1][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[2][0] == 'o') && (tac[2][1] == 'o') && (tac[2][2] == 'o')) {
						cout << " " << tac[2][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[0][0] == 'o') && (tac[1][1] == 'o') && (tac[2][2] == 'o')) {
						cout << " " << tac[0][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[2][0] == 'o') && (tac[1][1] == 'o') && (tac[0][2] == 'o')) {
						cout << " " << tac[2][0] << " wins" << endl;
						cout << endl;
						break;
					}

					if ((tac[0][0] == 'o') && (tac[1][0] == 'o') && (tac[2][0] == 'o')) {
						cout << " " << tac[0][0] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[0][1] == 'o') && (tac[1][1] == 'o') && (tac[2][1] == 'o')) {
						cout << " " << tac[1][1] << " wins" << endl;
						cout << endl;
						break;
					}
					if ((tac[0][2] == 'o') && (tac[1][2] == 'o') && (tac[2][2] == 'o')) {
						cout << " " << tac[0][2] << " wins" << endl;
						cout << endl;
						break;
					}
					i++;
				}


			}
			if (i == 9) {
				cout << "nobody wins" << endl;
				cout << endl;
				break;
			}
			if (choice == 'q') {

				run = false;
				cout << "peace out" << endl;
				cout << endl;
			}
			if (choice != 'w' && choice != 's' && choice != 'a' && choice != 'd' && choice != 'q' && choice != 'i') {
				cout << "not a valid command" << endl;
				cout << endl;
			}
		}
	}

	void displayPTR() {
		cout << *ptr << endl;
	}

	void test() {
		char foo = 'a';
		for (int o = 0; o < 3; o++) {
			for (int p = 0; p < 3; p++) {
				tac[o][p] = foo;
				foo = foo + 1;
			}
		}
	}

	char upps(char c) {
		char temp = toupper(c);
		return temp;
	}
	char lows(char s) {
		char crisp = tolower(s);
		return crisp;
	}


};
void play() {
	bool getGUD = true;
	while (getGUD) {
		char again;
		cout << "play?" << endl;
		cout << "Y for yes, X for no" << endl;
		cout << endl;
		again = controller();
		if (again == 'y') {
			Toe one;
			one.display();
			cout << endl;
			one.game();
		}
		if (again == 'x') {
			cout << "goodbye in " << endl;
			for (int j = 5; j > 0; j--) {
				cout << j << endl;
				Sleep(1000);

			}
			break;
		}
		else if ((again != 'x') || (again != 'y')) {
			cout << "enter either X or Y" << endl;
			cout << endl;
		}
	}
}
int main()
{
	play();
	
	



	return 0;
}

