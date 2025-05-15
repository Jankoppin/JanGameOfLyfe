#include "JanGameOfLife.h"
//Jan Pintar
//random number generator
int JanGameOfLife::gen_rand(int min,int max)
{
	return min + rand() % (max - min + 1);
}

//generate an empty world
vector<vector<bool>> JanGameOfLife::gen_emt()
{
	vector<vector<bool>> b(height, vector<bool>(width, false));
	return b;
}

JanGameOfLife::JanGameOfLife(int height, int width) //done
{
	this->height = height;
	this->width = width;
	alan = gen_emt();
}

//generate a random level with 25% probability
void JanGameOfLife::gen()
{
	vector<vector<bool>> b = gen_emt();
	for (int i = 1; i < height - 1; i++) {
		for (int j = 1; j < width - 1; j++) {
			b[i][j] = gen_rand(1, 4) == 4;
		}
	}
	alan = b;
}

//printing out L
void JanGameOfLife::out()
{
	cout << b2;
	for (int i = 0; i < width; i++) {
		cout << b0;
	}
	cout << b3;
	cout << endl;

	for (int i = 0; i < height; i++) {
		cout << b1;
		for (int j = 0; j < width; j++) {
			if (alan[i][j]) {
				cout << full;
			}
			else {
				cout << empty;
			}
		}
		cout << b1;
		cout << endl;
	}

	cout << b4;

	for (int i = 0; i < width; i++) {
		cout << b0;
	}
	cout << b5;
	cout << endl;
}

//update :3
void JanGameOfLife::update()
{
	vector<vector<bool>> fin = gen_emt();
	for (int i = 1; i < height - 1; i++) {
		for (int j = 1; j < width - 1; j++) {
			int cnt = 0;
			cnt += alan[i - 1][j - 1];
			cnt += alan[i - 1][j];
			cnt += alan[i - 1][j + 1];
			cnt += alan[i][j - 1];
			cnt += alan[i][j + 1];
			cnt += alan[i + 1][j - 1];
			cnt += alan[i + 1][j];
			cnt += alan[i + 1][j + 1];

			//cout << cnt << " ";
			if (alan[i][j]) {
				if (cnt > 3 || cnt < 2)
					fin[i][j] = 0;
				else fin[i][j] = 1;
			}
			else if (cnt == 3) {
				fin[i][j] = 1;
			}
		}
	}
	alan = fin;
}

//secret ;)
void JanGameOfLife::edit() {
	system("cls");
	int x = 1, y = 1;
	alan[y][x] = 1;
	out();
	bool pendown = 0;
	int a = 0;
	while (true) {
		
		int b = _getch();
		if (b == 0 || b == 224) {
			int a = _getch();

			if (a == 82) {
				pendown = !pendown;
			}
			if (!pendown) {
				alan[y][x] = 0;
			}
			if (a == 77) {
				if (x < width - 1)
					x++;
			}
			if (a == 80) {
				if (y < height - 1)
					y++;
			}
			if (a == 75) {
				if (x > 1)
					x--;
			}
			if (a == 72) {
				if (y > 1)
					y--;
			}
			if (a == 79) {
				break;
			}
		}
		alan[y][x] = 1;
		system("cls");
		out();
		cout << a;
	}
	
	
}

void JanGameOfLife::advance(int& step)
{
	int choice = 5;
	while (choice != 0) {
		for (int i = 0; i < step; i++) {
			system("cls");
			out();
			update();
		}
		cout << "Advance?";
		do {
			int b = _getch();
			if (b == 0 || b == 224) {
				int a = _getch();
				if (a == 82) {
					choice = 1;
				}
				else if (a == 79) {
					choice = 0;
				}
			}
		} while (choice != 1 && choice != 0);
	}
}
