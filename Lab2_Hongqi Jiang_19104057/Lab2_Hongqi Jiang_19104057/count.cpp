#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "count.h"
using namespace std;
//text file C:\Users\JHQ\Desktop\test.c
int Count_Keywork_Switch_Case(string inputfile, int level);
void Count_If_Elseif(string inputfile, int level);


int main()
{
	string filename;
	int lev;
	cout << "please input the name of file" << endl;
	cin >> filename;
	cout << "please input the level" << endl;
	cin >> lev;
	if (lev <= 2)
	{
		Count_Keywork_Switch_Case(filename, lev);
	}
	if (lev > 2)
	{
		Count_Keywork_Switch_Case(filename, lev);
		Count_If_Elseif(filename, lev);
	}
}
