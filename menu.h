#pragma once
#ifndef _MENU_H_
#define _MENU_H_
class menu
{
public:
	//метод отображающий доступные функции программы
	void info_console();
	//методы сообщающие об успешном открытии файла
	void done(std::string name_file);
	void done(std::string name_first_file, std::string name_second_file);
	void done(std::string name_first_file, std::string name_second_file, std::string name_third_file);
	//методы сообщающие об ошибке открытия файла
	void error(std::string name_file);
	void error(std::string name_first_file, std::string name_second_file);
	void error(std::string name_first_file, std::string name_second_file, std::string name_third_file);
	//метод выводящий в консоль линию
	void print_line();
private:
};
#endif // !_MENU_H_

