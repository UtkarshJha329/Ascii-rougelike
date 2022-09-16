#pragma once
#include <string>
#include <vector>

class randw
{
public:
	randw();
	static std::vector<std::vector<char>> Read(std::string fileName, int& numLines);
	static std::vector<std::vector<int>> PositionOfChar(const std::vector<std::vector<char>>& chars, const int lines, const char charToFind);
	static void Save(std::vector<std::vector<char>>& chars, const int lines, std::string fileLoc);
private:
	static std::string CreateText(std::vector<std::vector<char>>& chars, const int lines);
};

