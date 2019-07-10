#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class FactoryFile
{
public:
	
public:
	FactoryFile( );
	 void readFile(const string &, int **);
	 void writeFile(ofstream *,int**,bool s=true);
	 void showLineOfFile(string path);
	~FactoryFile();
};

