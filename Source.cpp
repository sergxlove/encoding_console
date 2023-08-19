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
	int line = 1;
	bool coincidence = false;
	string text;
	string symbol;
	string code_symbol;
	string path;
	fstream encod;
	fstream encoded_text;
	fstream alfabet;
	int j = 1;
	while (exit != var_exit::YES)
	{
		info_console();
		cin >> var_nav_console;
		switch (var_nav_console)
		{
		case 1:
			path = "encoding.txt";
			encod.open(path, fstream::out);
			if (encod.is_open())
			{
				done("encodding.txt");
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
				error("encodding.txt");
			}
			break;
		case 2:
			//SetConsoleCP(1251);
			//SetConsoleCP(866);
			path = "encoded_text.txt";
			encoded_text.open(path,fstream::out);
			path = "alfabet.txt";
			alfabet.open(path, fstream::in);
			path = "encoding.txt";
			encod.open(path, fstream::in);
			if (encoded_text.is_open()&&alfabet.is_open()&&encod.is_open())
			{
				done("encoding.txt", "encoded_text.txt", "alfabet.txt");
				cout << "Введите ваш текст (в конце вашего предложения необходимо поставить символ ;)" << endl;
				encoded_text.clear();
				getline(cin, text, ';');
				getline(alfabet, symbol);
				for (int i = 0;j < text.size();i++)
				{
					if (symbol[i] == text[j])
					{
						line = i + 1;
						j++;
						i = -1;
						for (int iter = 1;iter < line + 1;iter++)
						{
							getline(encod, code_symbol);
							if (iter == line)
							{
								encoded_text << code_symbol << endl;
								encod.seekg(0);
							}
						}
					}
				}
				encoded_text.close();
				alfabet.close();
				encod.close();
			}
			else
			{
				error("encoding.txt", "encoded_text.txt", "alfabet.txt");
			}
			break;
		case 3:
			path = "encoded_text.txt";
			encoded_text.open(path, fstream::in);
			if (encoded_text.is_open())
			{
				done("encoded_text.txt");
				while (!encoded_text.eof())
				{
					getline(encoded_text, symbol);
					cout << symbol << endl;
				}
			}
			else
			{
				error("encoded_text.txt");
			}
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