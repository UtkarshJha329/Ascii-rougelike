#include "randw.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <vector>

randw::randw()
{
}

std::vector<std::vector<char>> randw::Read(std::string fileName, int& numLines)
{
	std::ifstream inputStream;
	std::vector<std::vector<char>> chars;

	inputStream.open(fileName);
	if (inputStream.fail()) {
		perror(fileName.c_str());
	}

	std::string valRead;

	numLines = 0;
	while (getline(inputStream, valRead)) {

		std::vector<char> val(valRead.length());
		for (int i = 0; i < val.size(); i++) {
			val[i] = valRead.at(i);
		}
		chars.push_back(val);
		numLines++;
	}
	//std::cout << "Done reading and creating char 2d array" << std::endl;
	return chars;
	inputStream.close();
}

std::vector<std::vector<int>> randw::PositionOfChar(const std::vector<std::vector<char>>& chars, const int lines, const char charToFind)
{
	std::vector<std::vector<int>> pos;
	for (int i = 0; i < lines; i++)
	{
		for (int y = 0; y < chars[i].size(); y++)
		{
			if (chars[i][y] == charToFind)
			{
				pos.push_back({ i, y });
			}
		}
	}

	return pos;
}

void randw::Save(std::vector<std::vector<char>>& chars, const int lines, std::string fileLoc)
{
	std::ofstream saveStream;
	saveStream.open(fileLoc);

	saveStream << CreateText(chars, lines);
}

std::string randw::CreateText(std::vector<std::vector<char>>& chars, const int lines)
{
	std::string reconstLvl = "";
	for (int y = 0; y < lines; y++)
	{
		for (int x = 0; x < chars[y].size(); x++)
		{
			reconstLvl += chars[y][x];
		}
		reconstLvl += "\n";
	}

	return reconstLvl;
}

