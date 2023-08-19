#pragma once
#ifndef _MENU_H_
#define _MENU_H_
void info_console();
void done(std::string name_file);
void done(std::string name_first_file, std::string name_second_file);
void done(std::string name_first_file, std::string name_second_file, std::string name_third_file);
void error(std::string name_file);
void error(std::string name_first_file, std::string name_second_file);
void error(std::string name_first_file, std::string name_second_file, std::string name_third_file);
void print_line();
#endif // !_MENU_H_

