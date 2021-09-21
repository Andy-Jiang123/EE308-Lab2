#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;




int main()
{
	ifstream srcFile("C:/Users/JHQ/Desktop/test.c", ios::in);
	string x;
	string y;
	string z;
	vector<string> str;
	vector<string> line;
	int KeyWord_Num = 0;
	int Count_Switch = 0;
	int Switch_Loop = 0;

	int Next_Else=0;
	int Next_Elseif = 0;
	int Count_Ifelse = 0;
	int Count_Elseif = 0;
	string keyword[32] = { "auto","break","case","char","const","continue","default","do",
				           "double","else","enum","extern","float","for","goto","if",
				           "int","long","register","return","short","signed","sizeof","static",
				           "struct","switch","typedef","union","unsigned","void","volatile","while"};


	while (getline(srcFile, x))
	{
		
		for (int i = 0; i < x.length(); i++)
		{
			if (x[i] >= 'A' && x[i] <= 'z')
			{
				y += x[i];
				if (x[i] == 'e' || x[i] == 'f' || x[i] == 'l' || x[i] == 's' || x[i] == 'i')
				{
					z += x[i];					
				}
			}
			if (x[i] ==' '||x[i]=='\n'||x[i]=='\t')
			{
				if (y != "")
				{
					str.push_back(y);
				}
				
				y = "";
				continue;
			}
			
		}
		if (z.length()>=2&&z.substr(0, 2) == "if" )
		{
			line.push_back(z.substr(0, 2));
			
		}
		if (z.length() >= 2&& z.length() <=6 && z.substr(0, 4) == "else")
		{
			line.push_back(z.substr(0, 4));
			
		}
		if (z.length() >= 6 && z.substr(0, 6) == "elseif")
		{
			line.push_back(z.substr(0, 6));
			
		}
		
		z = "";
		y = "";

	}
	srcFile.close();
	
	for (int i = 0; i < str.size(); i++) 
	{
		cout << str[i] << endl;//打印容器的内容
		for (int a = 0; a < 32; a++)
		{
			if (keyword[a] == str[i])
			{
								
				KeyWord_Num += 1;
			}
		}
	}
	for (int a = 0; a < line.size(); a++)//if else elseif
	{
		cout << line[a] << endl;//打印容器的内容
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
	cout << "Keywork=" << KeyWord_Num << endl;
	cout << "Count if else=" << Count_Ifelse << "Count else if" << Count_Elseif << endl;
	
	return 0;
}
//int main()
//{
//	ifstream srcFile("C:/Users/JHQ/Desktop/test.c", ios::in); //以文本模式打开txt文件
//	string x;
//	string y;
//	string z;//if else or else if 
//	int KeyWord_Num = 0;
//	int Count_Switch = 0;
//	int Switch_Loop = 0;
//	string keyword[32] = {"auto","break","case","char","const","continue","default","do",
//		                  "double","else","enum","extern","float","for","goto","if",
//		                  "int","long","register","return","short","signed","sizeof","static",
//		                  "struct","switch","typedef","union","unsigned","void","volatile","while"};
//	string Case_Num = "";
//	int Case_Number = 0;
//	while (srcFile>>x)    
//	{
//		y = "";
//		for (int i = 0;i < x.length(); i++)
//		{
//			if (x[i] >= 'A' && x[i] <= 'z')
//			{
//				y += x[i];
//			}
//		}
//		
//		for (int a = 0; a < 32; a++)
//		{
//			if (keyword[a] == y)
//			{
//				
//				KeyWord_Num += 1;
//			}
//		}
//		if (y == "switch")
//		{
//			Count_Switch += 1;
//			Switch_Loop += 1;
//		}
//		if (Switch_Loop > 0 && y == "case")
//		{
//			Case_Number += 1;
//		}
//		if (Switch_Loop > 0 && y == "default")
//		{
//			Case_Num += to_string(Case_Number);
//			Case_Number = 0;
//			Switch_Loop = 0;
//		}
//		
//		cout << y << endl;
//	}
//	cout << KeyWord_Num << endl;
//	cout << Count_Switch << endl;
//	for (int b = 0; b < Count_Switch; b++)
//	{
//		cout << Case_Num[b] << " ";
//	}
//	cout << endl;
//	srcFile.close();
//	return 0;
//}