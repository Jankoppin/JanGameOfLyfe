#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;
class JanGameOfLife
{
private:
	char b0 = 205, b1 = 186, b2 = 201, b3 = 187, b4 = 200, b5 = 188, full = 219, empty = 32;
	int height, width;
	vector<vector<bool>> alan;
	int gen_rand(int min, int max);
	vector<vector<bool>> gen_emt();

public:
	JanGameOfLife(int height,int width);
	void gen();
	void out();
	void update();
	void edit();
	void advance(int& step);
};
//Jan Pintar

