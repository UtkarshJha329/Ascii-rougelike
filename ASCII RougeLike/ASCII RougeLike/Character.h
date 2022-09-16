#pragma once
#include "MovementController.h"
#include "Inventory.h"
#include <vector>
#include <string>

class Character
{
public:
	Character();
	Character(const int pos[2], int init_health, std::string name);
	void Init(const int pos[2], int init_health, std::string name, const int money);
	void Init(const int pos[2], int init_health, std::string name);

	void CharacterHandler(const int dX, const int dY, std::vector<std::vector<char>>& chars);
	void MoveCharacterAuto(int& dX, int& dY, std::vector<std::vector<char>>& chars, bool x, bool y);

	void Buy(Inventory& otherInventory, const int iNum);
	//Getters
	bool Hit() const { return _hit; }
	int Money() const { return _money; }
	bool OpenChest() const { return _chest; }

	//Setters
	void SetChest(const bool tF) { _chest = tF; }
private:
	void MoveCharacter(const int dX, const int dY, std::vector<std::vector<char>>& chars);
	void ProcessCollision();
	bool MoveX(const int dX, std::vector<std::vector<char>>& chars, bool& chest, bool& coin, bool& hit);
	bool MoveY(const int dY, std::vector<std::vector<char>>& chars, bool& chest, bool& coin, bool& hit);

public:
	int charPos[2] = { 0 , 0 };
	int health = 0;
	bool buy = false;
	Inventory inventory;
private:
	MovementController movementController;
	std::string _name = "character name";
	int _money = 0;
	bool _coin = false;
	bool _chest = false;
	bool _hit = false;
};

