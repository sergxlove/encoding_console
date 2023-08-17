#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>
#include "menu.h"
#include "enum.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int exit = var_exit::NO;
	int var_nav_console;
	string path = "encoding.txt";
	fstream encod;
	while (exit != var_exit::YES)
	{
		info_console();
		cin >> var_nav_console;
		switch (var_nav_console)
		{
		case 1:
			encod.open(path, fstream::in | fstream::out | fstream::app);
			if (encod.is_open())
			{
				cout << "Файл успешно открыт" << endl;
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