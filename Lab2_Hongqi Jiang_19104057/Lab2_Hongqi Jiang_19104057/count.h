#pragma once
#ifndef COUNT_H
#define COUNT_H
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int Count_Keywork_Switch_Case(string inputfile, int level)
{
	ifstream srcFile(inputfile, ios::in); //open file
	string x;
	string y;
	int KeyWord_Num = 0;
	int Count_Switch = 0;
	int Switch_Loop = 0;
	string keyword[32] = { "auto","break","case","char","const","continue","default","do",
							"double","else","enum","extern","float","for","goto","if",
							"int","long","register","return","short","signed","sizeof","static",
							"struct","switch","typedef","union","unsigned","void","volatile","while" };
	string Case_Num = "";
	int Case_Number = 0;
	while (srcFile >> x)
	{
		y = "";
		for (int i = 0; i < x.length(); i++)
		{
			if (x[i] >= 'A' && x[i] <= 'z')
			{
				y += x[i];
			}
		}

		for (int a = 0; a < 32; a++)
		{
			if (keyword[a] == y)
			{

				KeyWord_Num += 1;
			}
		}
		if (y == "switch")
		{
			Count_Switch += 1;
			Switch_Loop += 1;
		}
		if (Switch_Loop > 0 && y == "case")
		{
			Case_Number += 1;
		}
		if (Switch_Loop > 0 && y == "default")
		{
			Case_Num += to_string(Case_Number);
			Case_Number = 0;
			Switch_Loop = 0;
		}


	}
	srcFile.close();
	if (level == 1)
	{
		cout << "total num: " << KeyWord_Num << endl;
	}
	if (level >= 2)
	{
		cout << "total num: " << KeyWord_Num << endl;
		cout << "switch num:" << Count_Switch << endl;
		cout << "case num:";
		for (int b = 0; b < Count_Switch; b++)
		{
			cout << Case_Num[b] << " ";
		}
		cout << endl;
	}
	return 1;
}

int Count_If_Elseif(string inputfile, int level)
{
	ifstream srcFile(inputfile, ios::in);
	string x;
	string z;
	vector<string> line;
	int Next_Else = 0;
	int Next_Elseif = 0;
	int Count_Ifelse = 0;
	int Count_Elseif = 0;
	while (getline(srcFile, x))
	{

		for (int i = 0; i < x.length(); i++)
		{

			if (x[i] == 'e' || x[i] == 'f' || x[i] == 'l' || x[i] == 's' || x[i] == 'i')
			{
				z += x[i];
			}


		}
		if (z.length() >= 2 && z.substr(0, 2) == "if")
		{
			line.push_back(z.substr(0, 2));

		}
		if (z.length() >= 2 && z.length() <= 6 && z.substr(0, 4) == "else")
		{
			line.push_back(z.substr(0, 4));

		}
		if (z.length() >= 6 && z.substr(0, 6) == "elseif")
		{
			line.push_back(z.substr(0, 6));

		}

		z = "";

	}
	srcFile.close();
	for (int a = 0; a < line.size(); a++)//if else elseif
	{
		if (line[a] == "if")
		{
			Next_Else += 1;
			Next_Elseif += 1;

		}
		if (line[a] == "else" && Next_Else > 0)
		{
			Count_Ifelse += 1;
			Next_Else -= 1;
			Next_Elseif -= 1;
		}
		if (line[a] == "elseif" && Next_Elseif > 0)
		{
			Next_Else -= 1;
			Next_Elseif -= 1;
			Count_Elseif += 1;
		}


	}
	if (level == 3)
	{
		cout << "if-else num:" << Count_Ifelse << endl;
	}
	if (level == 4)
	{
		cout << "if-else num:" << Count_Ifelse << endl;
		cout << "if-elseif-else num:" << Count_Elseif << endl;
	}
	return 1;


}





#endif // !CLASS_H

