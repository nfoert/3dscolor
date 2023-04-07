#include <iostream>

#pragma once
class Foreground
{
public:
	const char* black = "\x1b[30m";
	const char* red = "\x1b[31m";
	const char* green = "\x1b[32m";
	const char* yellow = "\x1b[33m";
	const char* blue = "\x1b[34m";
	const char* magenta = "\x1b[35m";
	const char* cyan = "\x1b[36m";
	const char* white = "\x1b[37m";
	
};

class Background
{
public:
	const char* black = "\x1b[40m";
	const char* red = "\x1b[41m";
	const char* green = "\x1b[42m";
	const char* yellow = "\x1b[43m";
	const char* blue = "\x1b[44m";
	const char* magenta = "\x1b[45m";
	const char* cyan = "\x1b[46m";
	const char* white = "\x1b[47m";
	
};

class Reset 
{
public:
	const char* reset = "\x1b[0m";
};

class Move
{
public:
	std::string goTo(int row, int column)
	{
		++row;
		++column;
		
		std::string ROW = std::to_string(row);
		std::string COLUMN = std::to_string(column);

		std::string value = "\x1b[" + ROW + ";" + COLUMN + "H";
		return value;
	}
};