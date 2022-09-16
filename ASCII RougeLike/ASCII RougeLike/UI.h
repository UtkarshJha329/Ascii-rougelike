#pragma once
#include <string>
#include <vector>
#include "Character.h"
#include "Inventory.h"

class UI
{
public:
	UI();
	static void UpdateUI(Character& character, const int linesInLvl, const std::vector<std::vector<char>>& chars, Character& shop);
	static std::string GameOver();
private:
	static void NormalUI(const int i, const std::string health, const int money, const int hearts);
	static void ShopUI(const int i, Character& shop, Character& player);
	static std::string GetHearts(int health);

};

