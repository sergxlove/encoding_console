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
	std::cout << "��������� ��������" << std::endl;
	std::cout << "1 - ��������� ���������" << std::endl;
	std::cout << "2 - ���� ������ ��� �����������" << std::endl;
	std::cout << "3 - ����� ������ � �������������� ����" << std::endl;
	std::cout << "4 - ����� ������ � ��������������� ����" << std::endl;
	std::cout << "5 - ������� ���������" << std::endl;
	std::cout << "6 - ����� �� ���������" << std::endl;
	for (int i = 0; i < 30;i++)
	{
		std::cout << " - ";
	}
	std::cout << std::endl;
}
void done(std::string name_file)
{
	std::cout << "���� " << name_file << " ������� ������" << std::endl;
}
