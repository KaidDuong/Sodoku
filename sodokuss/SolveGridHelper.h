#pragma once
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#define UNASSIGNED 0
class SolveGridHelper
{
public:
	SolveGridHelper();
	//ham kiem tra xem da dien het cac o hay chua
	bool FindUnassignedLocation(int **grid ,int &row, int &col);
	//ham kieem tra tren hang do dien dung hay khong 
	bool UsedInRow(int **grid, int row, int num);
	//ham kiem tra tren cot do dien dung hay khong
	bool UsedInCol(int **grid, int col, int num);
	//ham kiem tra trong matran 3*3 co dien dung hay chua
	bool UsedInBox(int **grid, int boxStartRow, int boxStartCol, int num);
	//ham kiem tra ca 3 dieu kien tren
	bool isSafe(int **grid, int row, int col, int num);
};

