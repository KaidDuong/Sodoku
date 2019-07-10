#include "FactoryFile.h"



FactoryFile::FactoryFile( )
{
}

void FactoryFile::readFile(const string &path,int ** data)
{
	try {
		ifstream fileInput(path, ios::in);
		if (fileInput.fail()) {
			cout << "Failed to open this file\n";
			return ;
		}
		//read
		int j = 0;
		while(!fileInput.eof())
		{
			char temp[255];
			fileInput.getline(temp, 255);
			// tach cacs ki tu so ra dua vao mang
			string a =temp;
			string s="";
			int k = 0;
			int c = a.length();
			//loai bo cac khoang trong
			while(k<c){
				if ( a[k]> 47 && a[k] < 58) {
					s += a[k];
			 }
				k++;
			}
			for (int i = 0; i < 9; i++)
			{
				data[j][i] = int(s[i])-48;	
				//cout << data[j][i]<<"\t";
			}
			//cout << endl;
			j++;
		}

		fileInput.close();
		return ;
	}
	catch (exception e) {
	}
}

void FactoryFile::writeFile(  ofstream *fileOutput , int ** data,bool s)
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			*fileOutput << data[i][j] ;
			*fileOutput << " ";
		}
		*fileOutput << endl;
	}
	if (s == false) *fileOutput << "++++++++++++++++\n";
	else *fileOutput << "******************\n";
	fileOutput->close();
	return ;
}
void FactoryFile::showLineOfFile(string path) {
	try {
		ifstream fileInputs(path, ios::in);
		if (fileInputs.fail()) {
			cout << "Failed to open this file\n";
			return;
		}
		//read
		while (!fileInputs.eof())
		{
			char temp[255];
			fileInputs.getline(temp, 255);
			// tach cacs ki tu so ra dua vao mang
			string a = temp;
			cout << a <<endl;
		}

		fileInputs.close();
		return;
	}
	catch (exception e) {
	}
}

FactoryFile::~FactoryFile()
{
}
