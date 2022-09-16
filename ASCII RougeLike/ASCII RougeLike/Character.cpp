#include "Character.h"
#include "MovementController.h"
#include <vector>
#include <iostream>
#include <string>

Character::Character()
{
}

Character::Character(const int pos[2], int init_health, std::string name)
{
	charPos[1] = pos[1];
	charPos[0] = pos[0];
	health = init_health;
	_name = name;
	inventory.INIT(_name, _money);
}

void Character::Init(const int pos[2], int init_health, std::string name)
{
	charPos[1] = pos[1];
	charPos[0] = pos[0];
	health = init_health;
	_name = name;
	inventory.INIT(_name, _money);
}

void Character::Init(const int pos[2], int init_health, std::string name, const int money)
{
	charPos[1] = pos[1];
	charPos[0] = pos[0];
	health = init_health;
	_name = name;
	_money = money;
	inventory.INIT(_name, _money);
}


void Character::CharacterHandler(const int dX, const int dY, std::vector<std::vector<char>>& chars)
{
	MoveCharacter(dX, dY, chars);
	ProcessCollision();
}

void Character::MoveCharacter(const int dX, const int dY, std::vector<std::vector<char>>& chars)
{
	MoveY(dY, chars, _chest, _coin, _hit);
	MoveX(dX, chars, _chest, _coin, _hit);
	//std::cout << "(" << charPos[1] << ", " << charPos[0] << ")" << std::endl;
}

void Character::ProcessCollision()
{
	if (_coin) {
		_money++;
		inventory.Money(_money);
		_coin = false;
	}
	if (_hit) {
		if (health >= 1) {
			health--;
		}
	}
}

void Character::MoveCharacterAuto(int& dX, int& dY, std::vector<std::vector<char>>& chars, const bool x, const bool y)
{
	int pX = charPos[1];
	int pY = charPos[0];

	bool fakeHit = false;

	if (MoveY(dY, chars, _chest, _coin, fakeHit) && y == true) {
		if (pY == charPos[0]) {
			dY = -dY;
		}
	}
	if (MoveX(dX, chars, _chest, _coin, fakeHit) && x == true) {
		//std::cout << pX << charPos[1] << std::endl;
		if (pX == charPos[1]) {
			//std::cout << "Same." << std::endl;
			dX = -dX;
		}
	}
	//std::cout << "(" << charPos[1] << ", " << charPos[0] << ")" << std::endl;
}

void Character::Buy(Inventory& otherInventory, const int iNum)
{
	Item itemToBuy = otherInventory.ItemAtIndex(iNum);
	inventory.Buy(otherInventory, itemToBuy, _money);
}

bool Character::MoveX(const int dX, std::vector<std::vector<char>>& chars, bool& chest, bool& coin, bool& hit)
{
	if (dX != 0) {

		chest = false;
		coin = false;

		int pY = charPos[0];
		int pX = charPos[1];

		char nextChar = chars[pY][pX + dX];
		//std::cout << "next char: " << nextChar << std::endl;

		bool canSwap = movementController.CanSwap(nextChar, dX, charPos, chest);
		bool wallChar = nextChar == '#';
		hit = nextChar == 'E';

		if (canSwap) {
			bool shouldReplace = movementController.ShouldReplace(nextChar, coin);
			movementController.MoveX(chars, dX, charPos);
			if (shouldReplace) {
				int prevPos[2] = { pX, pY };
				movementController.Replace(chars, prevPos);
			}
			return true;
		}
		else if (wallChar) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
	return true;
	}
}

bool Character::MoveY(const int dY, std::vector<std::vector<char>>& chars, bool& chest, bool& coin, bool& hit)
{
	if (dY != 0) {

		chest = false;
		coin = false;

		int pY = charPos[0];
		int pX = charPos[1];

		char nextChar = chars[pY - dY][pX];
		//std::cout << "next char: " << nextChar << std::endl;

		bool canSwap = movementController.CanSwap(nextChar, dY, charPos, chest);
		bool wallChar = nextChar == '#';
		hit = nextChar == 'E';

		if (canSwap) {
			bool shouldReplace = movementController.ShouldReplace(nextChar, coin);
			movementController.MoveY(chars, dY, charPos);
			if (shouldReplace) {
				int prevPos[2] = { pX, pY };
				movementController.Replace(chars, prevPos);
			}
			return true;
		}
		else if (wallChar) {
			return true;
		}
		else {
			
			return false;
		}
	}
	else {
		return true;
	}
}


