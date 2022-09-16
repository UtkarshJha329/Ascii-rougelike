#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>

class MovementController
{
public:
	MovementController();
	//Movement on axis
	void MoveX(std::vector<std::vector<char>>& chars, int moveAmt, int charIndex[2]);
	void MoveY(std::vector<std::vector<char>>& chars, int moveAmt, int charIndex[2]);

	//Helpers
	bool CanSwap(const char nextChar, int moveAmt, int charIndex[2], bool& chest);
	bool ShouldReplace(const char collidingChar, bool& coin);
	void Replace(std::vector<std::vector<char>>& chars, int charIndex[2]);

private:
	static constexpr char _wall = '#';
	static constexpr char _air = '.';
	static constexpr char _coin = 'o';
	static constexpr char _chest = 'x';
	static constexpr char _enemy = 'E';
	static constexpr char _player = '@';

};

