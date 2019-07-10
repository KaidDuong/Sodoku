#include "Sudoku.h"

Sudoku::Sudoku()
{
	this->grid = new int*[9];
	for (int i = 0; i < 9; i++) {
		this->grid[i] = new int[9];
	}
	for (int i = 1; i < 10; i++)
		this->guessNum[i - 1] = i;
	string s = "C:\\Users\\HANH-PC\\Desktop\\output.txt";
	ofs = new ofstream(s, std::ios::out);
}

void Sudoku::printGrid()
{
	for (int i = 0; i < 9; i++)
	{
		cout << endl;
		if ((i % 3)==0&&i!=0) cout <<"__________________________________\n";
		
		for (int j = 0; j < 9; j++)
		{
			if ((j % 3) == 0&&j!=0)cout << " | ";
			
			if (grid[i][j] == 0)
				cout << setw(3) << "?";
			else
				cout <<setw(3)<< grid[i][j];
			
		}
		cout << endl;
	}cout << "\nx-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x\n";
}



bool Sudoku::solveGrid()
{
	
	string s1 = "C:\\Users\\HANH-PC\\Desktop\\output.txt";
	int row=0, col=0;
	//neu toan bo deu duoc gan thi da giai xong
	if (!this->FindUnassignedLocation(this->grid, row, col))
		return true; // success!

	 // xem xet cac so tu 1-9
	for (int num = 0; num < 9; num++)

	{//thuc hien du doan
		if (this->isSafe(this->grid, row, col, this->guessNum[num]))
		{
			this->grid[row][col] = this->guessNum[num];
			this->ofs->open(s1, std::ios::app);
			this->writeFile(this->ofs, this->grid);
			// return true neu da giai duoc
			if (this->solveGrid())
			{
				return true;
			}

			// neu that bai thi thu lai
			this->grid[row][col] = UNASSIGNED;
		}
	}
	return false; // dieu kien quay lui
}

void Sudoku::game()
{ 
	cout << "\n--------------Game Sudoku------------";
	cout << "\n 1. Nhap 1 de chon do kho cua game";
	cout << "\n 2. Nhap 2 de giai Sudoku ";
	cout << "\n 3. Nhap 3 de hien thi cach giai Sudoku";
	cout << "\n 4. Nhap 0 de thoat";
	int choice;
	do {
		cout << "\nmoi ban nhap lua chon :";
		cin >> choice;
		switch (choice)
		{
		case 0: {
			cout << "\nChuc ban mot ngay tot lanh !\n";
			break;
		}
		case 1: {
			cout << "\nBan co the chon muc :";
			cout << "\n1.Nhan 1 de chon muc de";
			cout << "\n2.Nhan 2 de chon muc thuong";
			cout << "\n3.Nhan 3 de chon muc kho";
			int choice_1;
			string s1 = "C:\\Users\\HANH-PC\\Desktop\\input.txt";
			string s2 = "C:\\Users\\HANH-PC\\Desktop\\input2.txt";
			string s3 = "C:\\Users\\HANH-PC\\Desktop\\input3.txt";
			cout << "\n moi ban nhap vao lua chon : ";
			cin >> choice_1;
			switch (choice_1)
			{
			case 1: {
				this->loadData(s1);
				break;
			}
			case 2: {
				this->loadData(s2);
				break;
			}
			case 3: {
				this->loadData(s3);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 2: {
			this->ofs->clear();
			this->writeFile(this->ofs, this->grid);
			if (this->solveGrid()) {
				cout << "Success !";
				this->printGrid();
			}
			else cout << " Don't Success !";
			break;
			
		}
		case 3: {
			this->CachGiai();
			break;
		}
		default:
			break;
		}
		if (choice != 0) {
			cout << "\n--------------Game Sudoku------------";
			cout << "\n 1. Nhap 1 de chon do kho cua game";
			cout << "\n 2. Nhap 2 de giai Sudoku ";
			cout << "\n 3. Nhap 3 de hien thi cach giai Sudoku";
			cout << "\n 4. Nhap 0 de thoat";
		}
	} while (choice != 0);
	
}
void Sudoku::CachGiai()
{
	cout << "\n------Loi Giai Sudoku-------\n";
	string path = "C:\\Users\\HANH-PC\\Desktop\\output.txt";
	this->showLineOfFile(path);
}
void Sudoku::loadData(string path)
{
	
	int **data = new int*[9];
	for (int i = 0; i < 9; i++) {
		data[i] = new int[9];
	}
	this->readFile(path, data);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			this->grid[i][j] = data[i][j];
			//cout << this->grid[i][j]<<"\t";
		}
		//cout << endl;
	}
	for (int i = 0; i < 9; i++)
		delete data[i];
	delete[] data;
	this->printGrid();
}

