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
	unsigned int var_nav_console;
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
	int delete_encod = var_exit::NO;
	int delete_encoded_text = var_exit::NO;
	int j = 1;
	int ordinal_number = 1;
	unsigned int var_delete;
	string var_delete_str;
	string var_nav_console_str;
	string text_str;
	while (exit != var_exit::YES)
	{
		info_console();
		cin >> var_nav_console_str;
		try
		{
			var_nav_console = stoi(var_nav_console_str);
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
				encoded_text.open(path, fstream::out);
				path = "alfabet.txt";
				alfabet.open(path, fstream::in);
				path = "encoding.txt";
				encod.open(path, fstream::in);
				if (encoded_text.is_open() && alfabet.is_open() && encod.is_open())
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
					encoded_text.close();
				}
				else
				{
					error("encoded_text.txt");
				}
				break;
			case 4:
				path = "encoded_text.txt";
				encoded_text.open(path, fstream::in);
				path = "alfabet.txt";
				alfabet.open(path, fstream::in);
				path = "encoding.txt";
				encod.open(path, fstream::in);
				if (encoded_text.is_open() && alfabet.is_open() && encod.is_open())
				{
					done("encoding.txt", "encoded_text.txt", "alfabet.txt");
					while (!encoded_text.eof())
					{
						line = 1;
						coincidence = false;
						getline(encoded_text, text_str);
						if (text_str != "")
						{
							while (coincidence != true)
							{
								getline(encod, code_symbol);
								if (code_symbol == text_str)
								{
									getline(alfabet, symbol);
									cout << symbol[line - 1];
									coincidence = true;
								}
								line++;
							}
						}
						encod.seekg(0);
					}
					cout << endl;
				}
				else
				{
					error("encoding.txt", "encoded_text.txt", "alfabet.txt");
				}
				encoded_text.close();
				alfabet.close();
				encod.close();
				break;
			case 5:
				path = "encoded_text.txt";
				encoded_text.open(path, fstream::out);
				path = "encoding.txt";
				encod.open(path, fstream::out);
				if (encod.is_open() && encoded_text.is_open())
				{
					done("encoded_text.txt", "encoding.txt");
					if (encod.good() == false || encod.eof() == false)
					{
						delete_encod = var_exit::YES;
					}
					if (encoded_text.good() == false || encoded_text.eof() == false)
					{
						delete_encoded_text = var_exit::YES;
					}
					if (delete_encod == var_exit::NO && delete_encoded_text == var_exit::NO)
					{
						cout << "Нет доступных файлов для удаления" << endl;
					}
					else
					{
						cout << "Доступные файлы для удаления" << endl;
						if (delete_encod == var_exit::YES)
						{
							cout << ordinal_number << " - encoding.txt - удалить?" << endl;
							ordinal_number++;
						}
						if (delete_encoded_text == var_exit::YES)
						{
							cout << ordinal_number << " - encoded_text.txt - удалить?" << endl;
							ordinal_number++;
						}
						cout << ordinal_number << " - удалить все" << endl;
						cin >> var_delete_str;
						try
						{
							var_delete = stoi(var_delete_str);
							switch (var_delete)
							{
							case 1:
								encod.clear();
								break;
							case 2:
								encoded_text.clear();
								break;
							case 3:
								encod.clear();
								encoded_text.clear();
								break;
							default:
								cout << "Такого варианта ответа нет" << endl;
								break;
							}
						}
						catch (...)
						{
							cout << "Некоректный ввод данных" << endl;
						}
					}
				}
				else
				{
					error("encoded_text.txt", "encoding.txt");
				}
				encod.close();
				encoded_text.close();
				break;
			case 6:
				exit = var_exit::YES;
				break;
			default:
				break;
			}
		}
		catch (...)
		{
			cout << "Некоректный ввод данных" << endl;
		}
		
	}
	return 0;
}