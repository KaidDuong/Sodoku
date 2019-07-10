#pragma once
#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string.h>
#include <iomanip>
#include <vector>
#include "SolveGridHelper.h"
#include "FactoryFile.h"
using namespace std;
class Sudoku:
	public SolveGridHelper,FactoryFile
{
public:
	int ** grid;
	int guessNum[9];
	int gridPos[81];
	
public:
	Sudoku( );

	void printGrid();
	bool solveGrid();
	void game();
	ofstream* ofs;
	void CachGiai();
	void loadData(string s);
};

