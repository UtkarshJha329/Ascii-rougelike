#include "MovementController.h"
#include <iostream>
#include <stdio.h>
#include <vector>


MovementController::MovementController()
{
}

void MovementController::MoveX(std::vector<std::vector<char>>& chars, int moveAmt, int charIndex[2])
{
	int pY = charIndex[0];
	int pX = charIndex[1];

	std::swap(chars[pY][pX], chars[pY][pX + moveAmt]);
	charIndex[1] = pX + moveAmt;
}

void MovementController::MoveY(std::vector<std::vector<char>>& chars, int moveAmt, int charIndex[2])
{
	int pY = charIndex[0];
	int pX = charIndex[1];

	std::swap(chars[pY][pX], chars[pY - moveAmt][pX]);
	charIndex[0] = pY - moveAmt;
}

void MovementController::Replace(std::vector<std::vector<char>>& chars, int charIndex[2])
{
	chars[charIndex[1]][charIndex[0]] = _air;
}

bool MovementController::CanSwap(const char nextChar, int moveAmt, int charIndex[2], bool& chest)
{
	if (nextChar == _wall || nextChar == _enemy || nextChar == _player) {
		chest = false;
		//std::cout << "Collision with: " << nextChar << std::endl;

		return false;
	}
	else if (nextChar == _chest) {
		chest = true;
		//std::cout << "Collision with: " << nextChar << std::endl;

		return false;
	}
	else {
		chest = false;
		return true;
	}
}

bool MovementController::ShouldReplace(const char collidingChar, bool& coin)
{
	if (collidingChar == _coin) {
		coin = true;
		return true;
	}
	else if (collidingChar == _air) {
		coin = false;
		return true;
	}
	else {
		coin = false;
		return false;
	}
}
