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
