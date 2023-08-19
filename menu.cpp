#pragma once
#include <iostream>
#include "menu.h"
void info_console()
{
	for (int i = 0; i < 30;i++)
	{
		std::cout << " - ";
	}
	std::cout << std::endl;
	std::cout << "Доступные действия" << std::endl;
	std::cout << "1 - Генерация кодировки" << std::endl;
	std::cout << "2 - Ввод текста для кодирования" << std::endl;
	std::cout << "3 - Вывод текста в закодированном виде" << std::endl;
	std::cout << "4 - Вывод текста в раскодированном виде" << std::endl;
	std::cout << "5 - Очистка документа" << std::endl;
	std::cout << "6 - Выход из программы" << std::endl;
	for (int i = 0; i < 30;i++)
	{
		std::cout << " - ";
	}
	std::cout << std::endl;
}
void done(std::string name_file)
{
	std::cout << "Файл " << name_file << " успешно открыт" << std::endl;
}

void done(std::string name_first_file, std::string name_second_file)
{
	std::cout << "Файлы " << name_first_file << " , " << name_second_file << " успешно открыты" << std::endl;
}

void done(std::string name_first_file, std::string name_second_file, std::string name_third_file)
{
	std::cout << "Файлы " << name_first_file << " , " << name_second_file << " , " << name_third_file << " успешно открыты" << std::endl;
}

void error(std::string name_file)
{
	std::cout << "Ошибка открытия файла " << name_file << std::endl;
}

void error(std::string name_first_file, std::string name_second_file)
{
	std::cout << "Ошибка открытия файлов " << name_first_file << " , " << name_second_file << std::endl;
}

void error(std::string name_first_file, std::string name_second_file, std::string name_third_file)
{
	std::cout << "Ошибка открытия файлов : " << name_first_file << " , " << name_second_file << " , " << name_third_file << std::endl;
}

void print_line()
{
	for (int i = 0; i < 30;i++)
	{
		std::cout << " - ";
	}
	std::cout << std::endl;
}

