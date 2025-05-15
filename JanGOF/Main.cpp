#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
#include <string>
#include "JanGameOfLife.h"
using namespace std;


void settings(int& height, int& width, int& step) {
	int ch = 0;
	while (ch != 4) {
		system("cls");

		if (ch == 0) {
			cout << ">";
		}
		cout << "Width: " << width << "\n";
		if (ch == 1) {
			cout << ">";
		}
		cout << "Height: " << height << "\n";
		if (ch == 2) {
				cout << ">";
		}
		cout << "Advance by: "<< step << "\n";
		if (ch == 3) {
			cout << ">";
		}
		cout << "Exit\n";
		int b = _getch();
		if (b == 0 || b == 224) {
		int a = _getch();
		if (a == 72) {
			if(ch!=0)
			ch--;
		}
		else if (a == 80) {
			if (ch != 3) {
				ch++;
			}
		}
		else if (a == 77) {
			switch (ch) {
				case 0:
					width++;
					break;
				case 1:
					height++;
					break;
				case 2:
					step++;
					break;
			}
		}
		else if (a == 75) {
			switch (ch) {
			case 0:
				width--;
				break;
			case 1:
				height--;
				break;
			case 2:
				if(step>1)
				step--;
				break;
			}
		}
		else if (a == 82) {
			if(ch==3)
			ch = 4;
		}

		}
	}
}

void randomgen(int& height, int& width, int& step) {
	JanGameOfLife game(height, width);
	srand(time(nullptr));
	int choice = 1;
	game.gen();
	game.advance(step);
}

void genonspot(int& height, int& width, int& step) {
	JanGameOfLife game(height, width);
	game.edit();
	game.advance(step);
}

int main() {
	ifstream f("title.txt");
	try
	{
		string temp;
		while (getline(f,temp)) {
			cout << temp << endl;
		}
		cout << "\n\n\n";
		cout << "====================================================USER MANUAL====================================================\n"
			<< "To navigate the program use arrow keys. To select items use insert.\n"
			<< "In the settings tab, you can adjust the height and the width of the simulation.\n"
			<< "You can also set the number of steps it takes each turn. To raise or lower the values use the arrow keys.\n"
			<< "By choosing controlled generation, you can paint your board before running.\n"
			<< "Use arrow keys to navigate, and insert to set down or raise your brush.\n"
			<< "To run the game, press end. Choosing random generation, generates a random board filled to approximately 25%.\n"
			<< "It then automatically takes the specified ammount of steps after which it asks for conformation to go further."
			<< "To confirm press insert. To exit press end.";

		cout <<"Press any key to continue...";
		_getch();
	}
	catch (const std::exception& e)
	{
		cout << e.what();
		return 404;
	}
	int height = 25, width = 50, step = 1;
	int ch = 1;
	do {
		system("cls");
		cout << "Choose an option:\n\n";
		if (ch == 1) {
			cout << ">";
		}
		cout << "Exit\n";

		if (ch == 2) {
			cout << ">";
		}
		cout << "Random generation\n";

		if (ch == 3) {
			cout << ">";
		}
		cout << "Controlled generation\n";

		if (ch == 4) {
			cout << ">";
		}
		cout << "Settings\n\n";
		
		int b = _getch();
		if (b == 0 || b == 224) {
			int a = _getch();
			if (a == 72) {
				if (ch > 1)
					ch--;
			}
			else if (a == 80) {
				if (ch < 4) {
					ch++;
				}
			}
			else if (a == 82) {
				switch (ch) {
				case 1:
					ch = 0;
					break;
				case 2:
					randomgen(height, width, step);
					break;
				case 3:
					genonspot(height, width, step);
					break;
				case 4:
					settings(width, height, step);
					break;
				}
			}
		}
	} while (ch!=0);
	return 0;
}
//Jan Pintar