#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <bitset>
#include "menu.h"
#include "enum.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int exit = var_exit::NO;
	int var_nav_console;
	unsigned int value;
	const int n = 8;
	int count = 0;
	string code_symbol;
	string path = "encoding.txt";
	fstream encod;
	while (exit != var_exit::YES)
	{
		info_console();
		cin >> var_nav_console;
		switch (var_nav_console)
		{
		case 1:
			encod.open(path, fstream::in | fstream::out | fstream::trunc);
			if (encod.is_open())
			{
				cout << "Файл успешно открыт" << endl;
				encod.clear();
				value = rand() % 80 + 130;
				while (count < 33)
				{
					code_symbol = bitset<n>(value).to_string();
					encod << code_symbol << endl;
					value++;
					count++;
				}
				encod.close();
			}
			else
			{
				cout << "Ошибка открытия файла"<<endl;
			}
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			exit = var_exit::YES;
			break;
		default:
			break;
		}
	}
	return 0;
}