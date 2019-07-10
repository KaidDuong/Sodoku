#include "SolveGridHelper.h"


SolveGridHelper::SolveGridHelper()
{
}


bool SolveGridHelper::FindUnassignedLocation(int **grid, int & row, int & col)
{
	for (row = 0; row < 9; row++)
	{
		for (col = 0; col < 9; col++)
		{
			if (grid[row][col] == UNASSIGNED)
				return true;
		}
	}

	return false;
}

bool SolveGridHelper::UsedInRow(int **grid, int row, int num)
{
	for (int col = 0; col < 9; col++)
	{
		if (grid[row][col] == num)
			return true;
	}

	return false;
}

bool SolveGridHelper::UsedInCol(int **grid, int col, int num)
{
	for (int row = 0; row < 9; row++)
	{
		if (grid[row][col] == num)
			return true;
	}

	return false;
}

bool SolveGridHelper::UsedInBox(int **grid, int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (grid[row + boxStartRow][col + boxStartCol] == num)
				return true;
		}
	}

	return false;
}

bool SolveGridHelper::isSafe(int **grid, int row, int col, int num)
{
	return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row % 3, col - col % 3, num);
}
